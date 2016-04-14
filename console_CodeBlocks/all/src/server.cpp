#include "../include/network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <exception>

#include "../include/expression.h"
#include "../include/constante.h"
#include "../include/binaire.h"    // contient les sous-classes de Binaire : Somme, Produit, Superieur ....
#include "../include/unaire.h"     // contient les sous-classes de Unaire : COs, Sin ....
#include "../include/variable.h"
#include "../include/affectation.h"
#include "../include/conditionnel.h"
#include "../include/ifThenElse.h"
#include "../include/boucle.h"
#include "../include/bloc.h"

using namespace std;

void createExercise(Client*);
void sendExercise(Client*);
void showMenuApp(Client*);
void openConnection(Server, Client*);

int main(int argc, char *argv[]) {
    string name;

    cout << "Votre nom : ";
    cin >> name;
    cout << endl;

    cout << "----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------" << endl;
    cout << "Bonjour '" << name << "', vous etes le professeur (serveur).\n" << endl;

    Server server;

    Client* client;

    createExercise(client);

    //showMenuApp(client);

    //openConnection(server, client);

    delete client;

    //server.stop();
    server.close();

    return 0;
}

void openConnection(Server s, Client* c) {
    cout << "En attente des eleves (clients) connecté............." << endl;

    try {
        s.start();
        c = s.connect();
        if ( !c )
            exit(0);
        else {

            //Receive client name from client
            string clientName = c->receive();

            cout << "\n=> L'eleve '" << clientName
                    << "' (IP: '" << c->address() << "'"
                    << ", Port: " << c->port() << ") "
                    << "est connecte." << endl;
        }
    }catch(exception& m) {
        cerr << m.what() << endl;
    }
}

void createExercise(Client* c) {
    string pathFile;
    cout << "Entrer le path de l'excercice que vous voulez créer :" << endl;
    cin >> pathFile;

    ofstream file(pathFile);

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
        cout << "666 : Sauvegarder votre fichier" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;

        switch(choice) {
            case 0:
            {
                string temp;
                cout << "Entrer le valeur de constante : " << endl;
                cin >> temp;
                Expression * c = new Constante(5);
                cout << "c = "<< *c << endl;
                //string s = c.afficher();
                //temp = temp + " = ";
                //file << s;
                //createExercise(c);
                break;
            }
            case 1:
                //sendExercise(c);
                break;
            default:
                cout << "Sauvegarder votre fichier......" << endl;
                file.close();
                break;
        }
    } while (choice != 666);
}

void sendExercise(Client* c) {
    string pathFile;
    cout << "Entrer le path du fichier que vous voulez envoyer : ";
    cin >> pathFile;
    c->sendFile(pathFile);
}

void showMenuApp(Client* c) {
    int choice = -1;

    cout << "***Menu***" << endl;

    do {
        cout << "1 : Creer des expressions" << endl;
        cout << "2 : Ouvrir la connexion" << endl;
        cout << "3 : Envoyer l'exercice aux eleves" << endl;
        cout << "4 : Fermer la connexion" << endl;
        cout << "666 : Quitter" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;

        switch(choice) {
            case 1:
                createExercise(c);
                break;
            case 2:
                sendExercise(c);
                break;
            default:
                cout << "Cas inconnu!" << endl;
                break;
        }
    } while (choice != 666);
}
