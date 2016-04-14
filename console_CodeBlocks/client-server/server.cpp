#include "network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <exception>

#include "expression.h"
#include "constante.h"
#include "binaire.h"    // contient les sous-classes de Binaire : Somme, Produit, Superieur ....
#include "unaire.h"     // contient les sous-classes de Unaire : COs, Sin ....
#include "variable.h"
#include "affectation.h"
#include "conditionnel.h"
#include "ifThenElse.h"
#include "boucle.h"
#include "bloc.h"

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
    try {

        server.start();

        // Connect to clients
        Client *client = server.connect();

        if ( !client )
            exit(0);
        else {

            //Receive client name from client
            string clientName = client->receive();

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
            //while(1) {

            showMenuApp(client);



            //}
            delete client;
        }

        //server.stop();
        server.close();

    }catch(exception& m) {
        cerr << m.what() << endl;
    }


    return 0;
}

void showMenuApp(Client* c) {
    int choice = -1;

    cout << "***Menu***" << endl;

    do {
        cout << "1 : Creation d'expressions" << endl;
        cout << "2 : Envoi l'exercice aux eleves" << endl;
        cout << "666 : Quitter" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;

        switch(choice) {
            case 1:
                createExercice(c);
                break;
            case 2:
                sendExcercice(c);
            default:
                cout << "Cas inconnu!" << endl;
                exit(1);
                break;
        }
    } while (choice != 666);
}

void createExercice(Client* c) {
    int choice = -1;

    do {
        cout << " 0 : constante" << endl;
        cout << " 1 : cosinus" << endl;
        cout << " 2 : binaire" << endl;
        cout << " 3 : variable1" << endl;
        cout << " 4 : variable2" << endl;
        cout << " 5 : conditionnel" << endl;
        cout << " 6 : if then else" << endl;
        cout << " 7 : bloc" << endl;
        cout << " 8 : boucle avec une seule expression" << endl;
        cout << " 9 : boucle avec bloc d'expressions" << endl;
        cout << " 10 : boucles imbriquées" << endl;
        cout << " 11 : tous les tests" << endl;
        cout << "666 : Retourner au menu principal" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;

        switch(choice) {
            case 1:
                createExercice();
                break;
            case 2:
                sendExcercice(c);
            default:
                cout << "Retourner au menu principal......" << endl;
                showMenuApp(c;)
                break;
        }
    } while (choice != 666);
}

void sendExercice(Client* c) {
    string pathFile;
    cout << "Entrer le path du fichier que vous voulez envoyer : ";
    cin >> pathFile;
    c->sendFile(pathFile);

}
