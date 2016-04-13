#ifndef NETWORK_H
#define NETWORK_H

#include <string>

#define SERVER_ADDRESS "127.0.0.1"
#define PORT 8888

using namespace std;

/////////////////////////////////////////////////////////
// Socket

class Socket {
public:
	explicit Socket(int sokect = -1);
	virtual ~Socket();
	// File
	bool opened() const { return m_socket >= 0; };
	bool open();
    bool close();
	// Messages
	string receive() const;
	bool send(const string &msg) const;
protected:
	void error(const string &msg);
	// Socket
	int m_socket;
};

/////////////////////////////////////////////////////////
// Client

class Client : public Socket {
public:
	explicit Client( const string &host = SERVER_ADDRESS,
					 int port = PORT,
                     int socket = -1 );
	// Initialization
	void setAddress(string server_addr);
	bool connect();
    // Member access
    string address() const { return m_address; }
    int port() const { return m_port; }

    //////
    void sendMessageToServer(Client c, string msg);
    string receiveMessageFromServer(Client c);

    void sendFile(char *file);

private:
	string m_address;
	int m_port;
};

/////////////////////////////////////////////////////////
// Server

class Server : public Socket {
public:
	explicit Server( int port = PORT );
	// Initialization
	bool start();
    bool stop() { return close(); }
    // Accept client connection
    Client *connect();

    /////////////////////
    void sendMessageToClient(Client *c, string msg);
    string receiveMessageFromClient(Client *c);

    void receiveFile();

private:
	int m_port;
};

#endif // NETWORK_H
