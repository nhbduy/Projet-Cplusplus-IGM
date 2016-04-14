#include "network.h"
#include "format.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <iostream>
#include <fstream>

#define LENGTH 512

using namespace std;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

// Get IP from domain name
// http://www.binarytides.com/hostname-to-ip-address-c-sockets-linux/
string resolve(const string &hostname) {
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in *h;
    int rv;
    string ip;
    // Prepare hints
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // use AF_INET6 to force IPv6
    hints.ai_socktype = SOCK_STREAM;
    if ( (rv = getaddrinfo( hostname.c_str() , "http" , &hints , &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return ip;
    }
    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        h = (struct sockaddr_in *) p->ai_addr;
        char buffer[100];
        strcpy(buffer , inet_ntoa( h->sin_addr ) );
        ip = buffer;
    }
    freeaddrinfo(servinfo); // all done with this structure
    return ip;
}

/////////////////////////////////////////////////////////
// Socket

Socket::Socket( int socket ) : m_socket(socket) {

}

Socket::~Socket() {
    close();
}

bool Socket::open() {
    if ( opened() )
        return false;
    // Create socket
    int socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if ( socket < 0 ) {
        error("ERROR, could not open socket!");
        m_socket = -1;
        return false;
    }
    m_socket = socket;
    return true;
}

bool Socket::close() {
    if ( opened() ) {
        ::close(m_socket);
        m_socket = -1;
    }
    return true;
}

string Socket::receive() const {
    if ( !opened() )
        return string();
    char buffer[256];
    memset(buffer,0, 256);
    int n = read(m_socket, buffer, 255);
    if (n < 0)
        return string();
    return string(buffer);
}

bool Socket::send(const string &msg) const {
    if ( !opened() || msg.empty() )
        return false;
    int n = write( m_socket, msg.c_str() , msg.length() );
    if (n < 0)
        return false;
    return true;
}

bool Socket::sendFile(const string &path) const {
    int len;
    char* buff;
    ifstream in;

    in.open(path);
    in.seekg(0, ios::end);

    len = in.tellg();

    in.seekg(0, ios::beg);

    buff = new char[len];

    in.read(buff, len);

    int n = write(m_socket, buff, len);

    if(n < 0)
        return false;

    in.close();

    delete [] buff;

    return true;
}

bool Socket::receiveFile(const string &path) const {
    char* buff;
    buff = new char[LENGTH];
    memset(buff, 0, 256);

    ofstream out;

    out.open(path);

    int n = read(m_socket, buff, LENGTH);

    if(n < 0)
        return false;

    out.write(buff, strlen(buff));

    out.close();

    bzero(buff, LENGTH);

    delete [] buff;

    return true;
}

void Socket::error(const string &msg) {
    perror( msg.c_str() );
}

/////////////////////////////////////////////////////////
// Client

Client::Client( const string &host, int port, int socket )
    : Socket(socket),
      m_address(host),
      m_port(port) {

}

void Client::setAddress(string server_addr){
    m_address = server_addr;
}

//int Client::getSocket() {
//    return Socket.m_socket;
//}

bool Client::connect() {
    if( !open() ) // Socket already opened or fail!
        return false;
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr( ::resolve( m_address ).c_str() );
    server.sin_port = htons( m_port );
    if ( ::connect( m_socket, (struct sockaddr *)&server, sizeof(server) ) < 0 ) {
        error("ERROR, unable to connect socket with server");
        close();
        return false;
    }
	return true;
}

void Client::sendMessageToServer(Client c, string msg) {
    string m = format("%s", msg.c_str());
    c.send(m);
}

string Client::receiveMessageFromServer(Client c) {
    string msg = c.receive();
    return msg;
}

//void Client::sendFileC(string path) {
//    int len;
//    char* buff;
//    ifstream in;
//
//    in.open(path);
//    in.seekg(0, ios::end);
//
//    len = in.tellg();
//
//    in.seekg(0, ios::beg);
//
//    buff = new char[len];
//
//    in.read(buff, len);
//
//    in.close();
//
//    cout.write(buff, len);
//
//    int n = write(m_socket, buff, len);
//
//    if(n < 0) {
//        cout << "Not send file" << endl;
//    }
//    else {
//        cout << "Content file is:" << buff << endl;
//    }
//
//    delete [] buff;
//
//
//
////    string line;
////    cout << "Test 1" << endl;
////    char* buffer = new char[256];
////    cout << "Test 2" << endl;
////    ifstream in(path);
////    cout << "Test 3" << endl;
////    if (!in.is_open()) {
////        cout << "Input is null" << endl;
////    }
////    else {
////        cout << "Input not null" << endl;
////        while(getline(in, line)) {
////            //cout << line << '\n';
////            buffer
////            cout << ::send(m_socket, buffer, 256, 0) << endl;
////        }
////        in.close();
////    }
//////    while((!in.read(buffer, 256).eof())) {
//////        cout << "Test 4" << endl;
//////        cout << ::send(m_socket, buffer, 256, 0);
//////    }
////    cout << "Test 5" << endl;
////    delete [] buffer;
//
//
//
////    char *fs_name = file;
////    char sdbuf[LENGTH];
////
////    cout << "Client envoit le fichier '" << fs_name << "' au serveur..." << endl;
////
//////    char buffer[256];
//////    int n;
//////    fgets(buffer, 255, stdin);
//////    //bzero(buffer, 256);
//////    n = ::write(m_socket, buffer, strlen(buffer));
//////
//////    if(n < 0)
//////        cout << "Erreur : ecrire au socket." << endl;
////
////    FILE *fs = fopen(fs_name, "r");
////
////    if(fs == NULL) {
////        cout << "Erreur : Le fichier '" << fs_name << "' n'est pas trouvé." << endl;
////        exit(1);
////    }
////
////    bzero(sdbuf, LENGTH);
////    int fs_block_sz;
////    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs)) > 0) {
////        if(::send(m_socket, sdbuf, fs_block_sz, 0) < 0) {
////            cout << "Erreur : L'envoi du fichier '" << fs_name << "' avec l'echec." << endl;
////            break;
////        }
////        bzero(sdbuf, LENGTH);
////    }
////    shutdown(m_socket, SHUT_WR);
////    cout << "OK : L'envoi du fichier '" << fs_name << "' avec succes." << endl;
////    cout << m_socket << endl;
//}

/////////////////////////////////////////////////////////
// Server

Server::Server( int port ) : m_port(port) {

}

//bool Server::receiveFileS(string path) {
//    int len = 256;
//    char* buff;
//    buff = new char[len];
//    memset(buff, 0, 256);
//
//    ofstream out;
//
//    out.open(path);
//
////    int recv_buff;
////
////    while((recv_buff = read(m_socket, buff, len)) > 0) {
////        out.write(buff, len);
////    }
//
//    int n = read(m_socket, buff, len);
//    if (n > 0) {
//        out.write(buff, len);
//    }
//    else {
//        out.write("Why ???", len);
//    }
//
//
//    out.close();
//
//    cout.write(buff, len);
//
//    delete [] buff;
//
//    return true;
//
////    cout << "Test 1" << endl;
////    char* buffer = new char[256];
////    cout << "Test 2" << endl;
////    int byte_recv = 0;
////    cout << "Test 3" << endl;
////    ofstream in(path);
////    cout << "Test 4" << endl;
////    while(((byte_recv = ::recv(m_socket, buffer, 5, 0)) > 0)) {
////        cout << "Test 5" << endl;
////        cout << byte_recv;
////        in.write(buffer, 256);
////    }
////    cout << "Test 6" << endl;
////    delete [] buffer;
//
//////    char buffer[256];
//////    int n;
//////    bzero(buffer, 256);
//////    n = ::read(m_socket, buffer, strlen(buffer));
//////
//////    if(n < 0)
//////        cout << "Erreur : lire du socket." << endl;
////
////    char *fr_name = file;
////    char revbuf[LENGTH];
////
////    cout << "Le serveur recoit le fichier '" << fr_name << "' du client..." << endl;
////
////    FILE *fr = fopen(fr_name, "a");
////    if(fr == NULL)
////        cout << "Erreur : Le fichier '" << fr_name << "' n'est pas ouvré sur le serveur." << endl;
////    else {
////        cout << "Test here 1" << endl;
////
////        bzero(revbuf, LENGTH);
////        int fr_block_sz = 0;
////
//////        while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs)) > 0) {
//////        if(::send(m_socket, sdbuf, fs_block_sz, 0) < 0) {
////
////        while((fr_block_sz = ::recv(m_socket, revbuf, LENGTH, 0)) > 0) {
////            cout << "SIZE : " << fr_block_sz  << " " << LENGTH << endl;
//////            int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
////            int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
//////        while((fr_block_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr)) > 0) {
//////            int write_sz = ::recv(m_socket, revbuf, fr_block_sz, 0);
//////
////            cout << "Test here 2" << endl;
////
////            if(write_sz < fr_block_sz) {
////                cout << "Erreur : L'ecriture du fichier sur le serveur est tombe." << endl;
////            }
////            bzero(revbuf, LENGTH);
////            cout << "Test here 3" << endl;
////            if(fr_block_sz == 0 || fr_block_sz != 512) {
////                cout << "Test here 4" << endl;
////                break;
////            }
////
////            cout << "Test here 5" << endl;
////
//////            if(::recv(m_socket, revbuf, fr_block_sz, 0) < 0) {
//////                cout << "Erreur : L'ecriture du fichier sur le serveur est tombe." << endl;
//////                break;
//////            }
//////            bzero(sdbuf, LENGTH);
////        }
////
////        if(fr_block_sz < 0)
////        {
////            if (errno == EAGAIN)
////            {
////
////                cout << "recv() timed out." << endl;
////            }
////            else
////            {
////                cout << "recv() failed due to errno = " << errno << endl;
////            }
////        }
////        cout << "Test here 6" << endl;
////
////        cout << "OK : La reception du fichier '" << fr_name << "' avec succes." << endl;
////        cout << m_socket << endl;
////        fclose(fr);
////    }
//}

bool Server::start() {
    if( !open() ) // Socket already opened or fail!
        return false;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( m_port );
    // Assigning a name to socket
    if( ::bind( m_socket, (struct sockaddr *)&server , sizeof(server)) < 0 ) {
        error("ERROR, bind socket failed");
        close();
        return false;
    }
    // Listen
    ::listen(m_socket , 5);
    // Socket ready!
    return true;
}

Client *Server::connect() {
    // Client address
    struct sockaddr_in client;
    socklen_t l = sizeof(struct sockaddr_in);
	// Client socket
    int socket = ::accept( m_socket,(struct sockaddr *)&client,(socklen_t*)&l );
    if ( socket < 0 ) {
        error("ERROR, accept client failed");
        return 0;
    }
    // Create client
    Client *c = new Client( inet_ntoa(client.sin_addr), m_port, socket );
    return c;
}

void Server::sendMessageToClient(Client *c, string msg) {
    string m = format("%s", msg.c_str());
    c->send(m);
}

string Server::receiveMessageFromClient(Client *c) {
    string msg = c->receive();
    return msg;
}
