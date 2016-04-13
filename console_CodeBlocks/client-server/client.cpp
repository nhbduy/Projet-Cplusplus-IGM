#include "network.h"
#include "format.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] ) {
    string name;
    string server_addr;
    //if ( argc > 1 )
        //name = argv[1];



    //cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    //getline(cin, name, '\n');
//
//    if (name == "") {
//        cout << "Votre nom est vide. Par default : X";
//        name = "X";
//    }
//
//    else
//        cout << "Votre nom est : " << name;
//
//    cout << "L'adresse IP serveur : ";
//    getline(cin, server_addr);
//    cout << endl;

    cout << "Votre nom : ";
    cin >> name;
    cout << endl;

    Client client;
    //client.setAddress(server_addr);
    bool isConnected = client.connect();

    if(isConnected) {
        cout << "----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------" << endl;
        cout << "Bonjour '" << name << "', vous etes l'eleve (client).\n" << endl;

    //    int soc = client.getSocket();
    //    cout << "Socket num : " << soc;

        //Send client name to server
        //client.sendMessageToServer(client, name);
        client.send(name);

        ////////////////////////////////////////////////////////////////////////
        char *file_test = "test1.txt";
    //    cout << "Veuillez entre le path de l'excercice vous voulez envoyer à cet eleve : ";
    //    cin >> file_test;

        //cout << "L'excercice : " << file_test << endl;

        //char *fileToSend = file_test;

        client.sendFile(file_test);

        //Choix

        // Send messages
    //    for ( int i=0; i<=4; ++i ) {
    //        string msg = format("client %s, message %d", name.c_str(), i);
    //        cout << "Client: send '" << msg << "'" << endl << flush;
    //        client.send( msg );
    //        string ok = client.receive();
    //        if ( ok.empty() )
    //            ok = "failed!";
    //        cout << "Client: received confirmation '" << msg << "'... "  << ok << endl << flush;
    //        sleep(2);
    //    }
    //    client.send("bye");
    //    cout << "Client: bye!" << endl;
    }

    else {
        cout << "Le client ne peut pas connecter au serveur." << endl;
        exit(0);
    }

    return 0;
}
