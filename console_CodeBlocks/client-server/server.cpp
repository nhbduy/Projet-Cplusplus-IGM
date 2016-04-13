#include "network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
    string name;

    cout << "Votre nom : ";
    cin >> name;
    cout << endl;

    cout << "----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------" << endl;
    cout << "Bonjour '" << name << "', vous etes le professeur (serveur).\n" << endl;
    cout << "En attente des eleves (clients) connecté............." << endl;

    Server server;
    server.start();
    // Connect to clients
    Client *client = server.connect();
    if ( !client )
        exit(0);
    else {
        //Receive client name from client
        //string clientName = receiveMessageFromClient(client);
        string clientName = client->receive();
        //string clientName = "Well";

        cout << "\n=> L'eleve '" << clientName
                << "' (IP: '" << client->address() << "'"
                << ", Port: " << client->port() << ") "
                << "est connecte." << endl;
    //    for ( int i=0; ; ++i ) {
    //        string msg = client->receive();
    //        cout << "<< '" << msg << "'" << endl;
    //        client->send("ok");
    //        if ( msg == "bye" )
    //            break;
    //    }

        char *file_test = "test_recu.txt";

        server.receiveFile(file_test);
    }



    delete client;
    //server.stop();
    server.close();

    return 0;
}
