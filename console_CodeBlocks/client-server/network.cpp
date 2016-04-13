#include "network.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

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

/////////////////////////////////////////////////////////
// Server

Server::Server( int port ) : m_port(port) {

}

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
