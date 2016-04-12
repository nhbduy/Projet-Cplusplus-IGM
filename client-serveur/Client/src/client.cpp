//#include <iostream>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <netdb.h>
//
//using namespace std;
//
//int main()
//{
//    /* ---------- INITIALIZING VARIABLES ---------- */
//
//    /*
//       1. client is a file descriptor to store the values
//       returned by the socket system call and the accept
//       system call.
//
//       2. portNum is for storing port number on which
//       the accepts connections
//
//       3. isExit is bool variable which will be used to
//       end the loop
//
//       4. The client reads characters from the socket
//       connection into a dynamic variable (buffer).
//
//       5. A sockaddr_in is a structure containing an internet
//       address. This structure is already defined in netinet/in.h, so
//       we don't need to declare it again.
//
//        DEFINITION:
//
//        struct sockaddr_in
//        {
//          short   sin_family;
//          u_short sin_port;
//          struct  in_addr sin_addr;
//          char    sin_zero[8];
//        };
//
//        6. serv_addr will contain the address of the server
//
//    */
//
//    int client;
//    int portNum = 1500; // NOTE that the port number is same for both client and server
//    bool isExit = false;
//    int bufsize = 1024;
//    char buffer[bufsize];
//    char* ip = "192.168.245.131";
//
//    struct sockaddr_in server_addr;
//
//    client = socket(AF_INET, SOCK_STREAM, 0);
//
//    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
//    /* --------------- socket() function ------------------*/
//
//    if (client < 0)
//    {
//        cout << "\nError establishing socket..." << endl;
//        exit(1);
//    }
//
//    /*
//        The socket() function creates a new socket.
//        It takes 3 arguments,
//
//            a. AF_INET: address domain of the socket.
//            b. SOCK_STREAM: Type of socket. a stream socket in
//            which characters are read in a continuous stream (TCP)
//            c. Third is a protocol argument: should always be 0. The
//            OS will choose the most appropiate protocol.
//
//            This will return a small integer and is used for all
//            references to this socket. If the socket call fails,
//            it returns -1.
//
//    */
//
//    cout << "\n=> Socket client has been created..." << endl;
//
//    /*
//        The variable serv_addr is a structure of sockaddr_in.
//        sin_family contains a code for the address family.
//        It should always be set to AF_INET.
//
//        htons() converts the port number from host byte order
//        to a port number in network byte order.
//
//    */
//
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_port = htons(portNum);
//
//    // this function returns returns 1 if the IP is valid
//    // and 0 if invalid
//    // inet_pton converts IP to packets
//    // inet_ntoa converts back packets to IP
//    //inet_pton(AF_INET, ip, &server_addr.sin_addr);
//
//    /*if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
//        cout << "=> Connection to the server " << inet_ntoa(server_addr.sin_addr) << " with port number: " << portNum << endl;*/
//
//
//    /* ---------- CONNECTING THE SOCKET ---------- */
//    /* ---------------- connect() ---------------- */
//
//    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
//        cout << "=> Connection to the server port number: " << portNum << endl;
//
//    /*
//        The connect function is called by the client to
//        establish a connection to the server. It takes
//        three arguments, the socket file descriptor, the
//        address of the host to which it wants to connect
//        (including the port number), and the size of this
//        address.
//
//        This function returns 0 on success and -1
//        if it fails.
//
//        Note that the client needs to know the port number of
//        the server but not its own port number.
//    */
//
//    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
//    recv(client, buffer, bufsize, 0);
//    cout << "=> Connection confirmed, you are good to go...";
//
//    cout << "\n\n=> Enter # to end the connection\n" << endl;
//
//    // Once it reaches here, the client can send a message first.
//
//    do {
//        cout << "Client: ";
//        do {
//            cin >> buffer;
//            send(client, buffer, bufsize, 0);
//            if (*buffer == '#') {
//                send(client, buffer, bufsize, 0);
//                *buffer = '*';
//                isExit = true;
//            }
//        } while (*buffer != 42);
//
//        cout << "Server: ";
//        do {
//            recv(client, buffer, bufsize, 0);
//            cout << buffer << " ";
//            if (*buffer == '#') {
//                *buffer = '*';
//                isExit = true;
//            }
//
//        } while (*buffer != 42);
//        cout << endl;
//
//    } while (!isExit);
//
//    /* ---------------- CLOSE CALL ------------- */
//    /* ----------------- close() --------------- */
//
//    /*
//        Once the server presses # to end the connection,
//        the loop will break and it will close the server
//        socket connection and the client connection.
//    */
//
//    cout << "\n=> Connection terminated.\nGoodbye...\n";
//
//    close(client);
//    return 0;
//}


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define BUFSIZE 2048
#define MAXLEN 80
#define SERVICE_PORT  21234

int connectsock(const char *host, int portnum);

int main(int argc, char *argv[]) {
  struct sockaddr_in myaddr, remaddr;
  string msg;
  int port;
  int udp_sock, tcp_sock, i;
  socklen_t slen=sizeof(remaddr);
  char buf[BUFSIZE], buf1[BUFSIZE], recbuf[BUFSIZE];
  int recvlen;
  vector<string> msg_vec;
  size_t msglen;
  char *coordinator = argv[1];
  stringstream strValue;
  bool started_sock = false;

  strValue << argv[2];
  strValue >> port;

  if ((udp_sock=socket(AF_INET, SOCK_DGRAM, 0))==-1)
    printf("socket created\n");

  memset((char *)&myaddr, 0, sizeof(myaddr));
  myaddr.sin_family = AF_INET;
  myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myaddr.sin_port = htons(0);

  if (bind(udp_sock, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
    perror("bind failed");
    return 0;
  }

  memset((char *) &remaddr, 0, sizeof(remaddr));
  remaddr.sin_family = AF_INET;
  remaddr.sin_port = htons(port);

  if (inet_aton(coordinator, &remaddr.sin_addr)==0) {
    fprintf(stderr, "inet_aton() failed\n");
    exit(1);
  }

  while (true) {
    cout << "> ";
    getline(cin, msg);
    msglen = msg.copy(buf, msg.length(), 0);
    msglen = msg.copy(buf1, msg.length(), 0);

    stringstream ss(buf1);
    while (ss >> buf1)
      msg_vec.push_back(buf1);
    fill_n(buf1, BUFSIZE, NULL);

    if (msg_vec[0] == "Start" || msg_vec[0] == "Find"){
      if (sendto(udp_sock, buf, MAXLEN, 0, (struct sockaddr *)&remaddr, slen)==-1) {
        perror("sendto");
        exit(1);
      }
      recvlen = recvfrom(udp_sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &slen);
      if (recvlen >= 0) {
        buf[recvlen] = 0;
        sscanf(buf, "%d", &port);
        cout << "Port: " << port << endl;
        if (port == -1){
          cout << "Server already exists or cannot be found" << endl;
        }
        tcp_sock = connectsock("localhost", port);
        cout << "started socket" << endl;
        started_sock = true;
      }
      if (port != -1){
        if (msg_vec[0] == "Start")
          cout << "A new chat session " << msg_vec[1] << " has been created and you have joined this session" << endl;
        else
          cout << "You have joined the chat session " << msg_vec[1] << endl;
      }
    } else if (msg_vec[0] == "Submit"){
      if (!started_sock){
        tcp_sock = connectsock("localhost", port);
        started_sock = true;
      }
      int nbytes = write(tcp_sock, buf, BUFSIZE);

    } else if (msg_vec[0] == "GetAll"){
      if (sendto(tcp_sock, buf, MAXLEN, 0, (struct sockaddr *)&remaddr, slen)==-1) {
        perror("sendto");
        exit(1);
      }
      recvlen = recvfrom(tcp_sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &slen);
      int unreadcount;
      stringstream strValue;

      strValue << buf;
      strValue >> unreadcount;

      if (recvlen >= 0) {
        buf[recvlen] = 0;
        cout << ">> Unread Messages: " << unreadcount << endl;
      }

      for (int i = 0; i < unreadcount; i++) {
        recvlen = recvfrom(tcp_sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &slen);
        if (recvlen >= 0) {
          buf[recvlen] = 0;
          cout << ">> " << buf << endl;
        }
      }

    } else if (msg_vec[0] == "GetNext") {
      if (sendto(tcp_sock, buf, MAXLEN, 0, (struct sockaddr *)&remaddr, slen)==-1) {
        perror("sendto");
        exit(1);
      }
      recvlen = recvfrom(tcp_sock, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &slen);
      if (recvlen >= 0) {
        buf[recvlen] = 0;
        cout << ">> " << buf << endl;
      }

    } else if (msg_vec[0] == "Leave") {
      if (sendto(tcp_sock, buf, MAXLEN, 0, (struct sockaddr *)&remaddr, slen)==-1) {
        perror("sendto");
        exit(1);
      }
      cout << "Left the chat" << endl;
      close(tcp_sock);
    } else if (msg_vec[0] == "Exit") {
      return 1;
    }else {
      cout << "Command not recognized" << endl;
    }

    fill_n(buf, msglen, NULL);
    fill_n(buf1, BUFSIZE, NULL);
    msg_vec.clear();
  }

  close(udp_sock);
  return 0;
}

int connectsock(const char *host, int portnum) {
  struct hostent  *phe;   /* pointer to host information entry    */
  struct sockaddr_in sin; /* an Internet endpoint address         */
  int     s;              /* socket descriptor                    */


  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;

  /* Map port number (char string) to port number (int)*/
  if ((sin.sin_port=htons(portnum)) == 0)
    printf("can't get \"%d\" port number\n", portnum);

  /* Map host name to IP address, allowing for dotted decimal */
  if ( phe = gethostbyname(host) )
    memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
  else if ( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
    printf("can't get \"%s\" host entry\n", host);

  /* Allocate a socket */
  s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (s < 0)
    printf("can't create socket: %s\n", strerror(errno));

  /* Connect the socket */
  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    printf("can't connect to %s.%d: %s\n", host, portnum, strerror(errno));

  return s;
}
