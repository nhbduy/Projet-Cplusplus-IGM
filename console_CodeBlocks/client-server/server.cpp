#include "network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
    cout << endl;
    cout << "\n----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------\n" << endl;
    cout << "Vous etes : le professeur (serveur)." << endl;

    Server server;
    server.start();
    // Connect to clients
    Client *client = server.connect();
    if ( !client )
        exit(0);

    //Receive client name from client
    //string clientName = receiveMessageFromClient(client);
    string clientName = client->receive();

    cout << "\nL'eleve '" << clientName
            << "' (IP : '" << client->address() << "'"
            << ", Port : " << client->port() << ") "
            << "est connecte.\n" << endl;
//    for ( int i=0; ; ++i ) {
//        string msg = client->receive();
//        cout << "<< '" << msg << "'" << endl;
//        client->send("ok");
//        if ( msg == "bye" )
//            break;
//    }

    char *file_test = "test_recu.txt";

    server.receiveFile(file_test);

    delete client;
    //server.stop();
    server.close();
    return 0;
}
