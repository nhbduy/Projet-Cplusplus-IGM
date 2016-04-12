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
