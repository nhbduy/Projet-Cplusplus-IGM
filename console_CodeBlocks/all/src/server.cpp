#include "../include/network.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <exception>

using namespace std;

bool openConnection(Server s, Client* c) {
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
        return false;
    }

    return true;
}

void sendExercise(Client* c, string flag) {
    string pathFile;
    cout << "Entrer le path de l'exercice que vous voulez envoyer a l'eleve : ";
    cin >> pathFile;
    if(c->sendFile(pathFile)) {
        flag = "ok";
        c->send(flag);
        cout << "L'envoi de l'exercice a l'eleve avec succes......." << endl;
    }
    else {
        cout << "L'envoi de l'exercice a l'eleve avec l'echec......." << endl;
    }
}

void receiveCopy(Client* c) {
    string pathFile;
    cout << "Entrer le path de la copie que vous voulez stocker : ";
    cin >> pathFile;
    cout << "En attente de recevoir la copie de l'eleve......." << endl;
    if(c->receive() == "ok") {
        c->receiveFile(pathFile);
        cout << "La reception de la copie de l'eleve avec succes......." << endl;
    }
    else {
        cout << "La reception de la copie de l'eleve avec l'echec......." << endl;
    }
}


int showMenuApp(Client* c) {
    int choice = -1;
    string flag = "ko";

    cout << "\t-----------------------MENU SERVEUR-----------------------" << endl;
    cout << "\t 1 : Envoyer l'exercice a l'eleve" << endl;
    cout << "\t 2 : Recevoir la copie de l'eleve" << endl;
    cout << "\t 666 : Quitter" << endl;
    cout << endl;
    cout << "Votre choix : ";

    do {

        cin >> choice;

        switch(choice) {
            case 1:
                sendExercise(c, flag);
                break;
            case 2:
                cout << "En attente de recevoir la copie..." << endl;
                break;
            default:
                cout << "Cas inconnu!" << endl;
                break;
        }
    } while (choice != 666);

    return 0;
}


int main(int argc, char *argv[]) {
    string name;

    cout << "Votre nom : ";
    cin >> name;
    cout << endl;

    cout << "----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------" << endl;
    cout << "Bonjour '" << name << "', vous etes le professeur (serveur).\n" << endl;

    Server server;

    Client* client;

    cout << "En attente des eleves (clients) connecté............." << endl;

    try {
//        if (openConnection(server, client)) {
//            //showMenuApp(client);
//
//            //client->sendFile("test.txt");
//            client->receiveFile("hello-server.txt");
//        }
//
//        else {
//            //something
//        }
        server.start();
        client = server.connect();
        if ( !client )
            exit(0);
        else {

            //Receive client name from client
            string clientName = client->receive();

            cout << "\n=> L'eleve '" << clientName
                    << "' (IP: '" << client->address() << "'"
                    << ", Port: " << client->port() << ") "
                    << "est connecte." << endl;

            //showMenuApp(client);

            //client->sendFile("hello-server.txt");
            //client->receiveFile("hello-server.txt");

            int choice = -1;
            string flag = "ko";
            string pathFile;

            cout << "\t-----------------------MENU SERVEUR-----------------------" << endl;
            cout << "\t 1 : Envoyer l'exercice a l'eleve" << endl;
            cout << "\t 2 : Recevoir la copie de l'eleve" << endl;
            cout << "\t 666 : Quitter" << endl;
            cout << endl;
            cout << "Votre choix : ";

            do {

                cin >> choice;

                switch(choice) {
                    case 1:
                    {
                        cout << "Entrer le path de l'exercice que vous voulez envoyer a l'eleve : ";
                        cin >> pathFile;
                        if(client->sendFile(pathFile)) {
                            cout << "L'envoi de l'exercice a l'eleve avec succes......." << endl;
                        }
                        else {
                            cout << "L'envoi de l'exercice a l'eleve avec l'echec......." << endl;
                        }
                        return 0;
                        break;
                    }
                    case 2:
                        cout << "Entrer le path de la copie que vous voulez stocker : ";
                        cin >> pathFile;
                        cout << "En attente de recevoir la copie de l'eleve......." << endl;
                        if(client->receiveFile(pathFile)) {
                            cout << "La reception de la copie de l'eleve avec succes......." << endl;
                        }
                        else {
                            cout << "La reception de la copie de l'eleve avec l'echec......." << endl;
                        }
                        return 0;
                        break;
                    default:
                        cout << "Cas inconnu!" << endl;
                        break;
                }
            } while (choice != 666);

        }
    }catch(exception& m) {
        cerr << m.what() << endl;
        return false;
    }

    delete client;
    //server.stop();
    server.close();

    return 0;
}

