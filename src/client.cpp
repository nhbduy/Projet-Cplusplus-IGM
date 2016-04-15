#include "../include/network.h"
#include "../include/format.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <exception>

using namespace std;

bool openConnection(Client c) {
    cout << "En attente du professeur (serveur) connecté............." << endl;

    try {
        bool isConnected = c.connect();

        if(isConnected) {
//            if (!c)
//                exit(0);
//            else {

                cout << "\n=> Vous avez connecté au serveur." << endl;
//            }
        }
    }catch(exception& m) {
        cerr << m.what() << endl;
        return false;
    }

    return true;
}

void receiveExercise(Client c) {
    string pathFile;
    cout << "Entrer le path de l'exercice que vous voulez stocker : ";
    cin >> pathFile;
    cout << "En attente de recevoir l'exercice du professeur......." << endl;
    if(c.receive() == "ok") {
        c.receiveFile(pathFile);
        cout << "La reception de l'exercice du professeur avec succes......." << endl;
    }
    else {
        cout << "La reception de l'exercice du professeur avec l'echec......." << endl;
    }
}

void sendCopy(Client c, string flag) {
    string pathFile;
    cout << "Entrer le path de la copie que vous voulez envoyer au professeur : ";
    cin >> pathFile;
    if(c.sendFile(pathFile)) {
        flag = "ok";
        c.send(flag);
        cout << "L'envoi de la copie au professeur avec succes......." << endl;
    }
    else {
        cout << "L'envoi de la copie au professeur avec l'echec......." << endl;
    }
}

int showMenuApp(Client c) {
    int choice = -1;
    string flag = "ko";

    cout << "\t-----------------------MENU CLIENT-----------------------" << endl;
    cout << "\t 1 : Recevoir l'exercice du professeur" << endl;
    cout << "\t 2 : Envoyer la copie au professeur" << endl;
    cout << "\t 666 : Quitter" << endl;
    cout << endl;
    cout << "Votre choix : ";

    do {
        cin >> choice;

        switch(choice) {
            case 1:
                //cout << "En attente de recevoir l'exercice..." << endl;
                receiveExercise(c);
                break;
            case 2:
                //sendCopy(c, flag);
                break;
            default:
                cout << "Cas inconnu!" << endl;
                break;
        }
    } while (choice != 666);

    return 0;
}

int main( int argc, char *argv[] ) {
    string name;
    string server_addr;

    cout << "Votre nom : ";
    cin >> name;
    cout << endl;

    cout << "----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------" << endl;
    cout << "Bonjour '" << name << "', vous etes l'eleve (client).\n" << endl;

    Client client;

    cout << "En attente du professeur (serveur) connecté............." << endl;

    try {
        bool isConnected = client.connect();
        //if(openConnection(client)) {
        if(isConnected) {

            client.send(name);

            //showMenuApp(client);

            //client.receiveFile("hello-eleve.txt");
            //client.sendFile("hello.txt");

            int choice = -1;
            string flag = "ko";
            string pathFile;

            cout << "\t-----------------------MENU CLIENT-----------------------" << endl;
            cout << "\t 1 : Recevoir l'exercice du professeur" << endl;
            cout << "\t 2 : Envoyer la copie au professeur" << endl;
            cout << "\t 666 : Quitter" << endl;
            cout << endl;
            cout << "Votre choix : ";

            do {
                cin >> choice;

                switch(choice) {
                    case 1:
                    {
                        cout << "Entrer le path de l'exercice que vous voulez stocker : ";
                        cin >> pathFile;
                        cout << "En attente de recevoir l'exercice du professeur......." << endl;
                        if(client.receiveFile(pathFile)) {
                            cout << "La reception de l'exercice du professeur avec succes......." << endl;
                        }
                        else {
                            cout << "La reception de l'exercice du professeur avec l'echec......." << endl;
                        }
                        return 0;
                        break;
                    }

                    case 2:
                        cout << "Entrer le path de la copie que vous voulez envoyer au professeur : ";
                        cin >> pathFile;
                        if(client.sendFile(pathFile)) {
                            cout << "L'envoi de la copie au professeur avec succes......." << endl;
                        }
                        else {
                            cout << "L'envoi de la copie au professeur avec l'echec......." << endl;
                        }
                        return 0;
                        break;
                    default:
                        cout << "Cas inconnu!" << endl;
                        break;
                }
            } while (choice != 666);


            ////////////////////////////////////////////////////////////////////////

            //    cout << "Veuillez entre le path de l'excercice vous voulez envoyer à cet eleve : ";
            //    cin >> file_test;

                //cout << "L'excercice : " << file_test << endl;

                //char *fileToSend = file_test;
            //string file_test = "test1.txt";
            //client.receiveFile(file_test);


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
    }catch(exception& m) {
        cerr << m.what() << endl;
    }

    return 0;
}
