#include "network.h"
#include "format.h"
#include <iostream>
#include "string.h"
#include <unistd.h>

using namespace std;

int main( int argc, char *argv[] ) {
    string name;
    string server_addr;

    cout << endl;
    cout << "\n----------BIENVENUE A L'APPLICATION : TUTEUR ALGEBRE----------\n" << endl;
    cout << "Vous etes : l'eleve (client)." << endl;

    cout << "Votre nom : ";
    cin >> name
    cout << endl;
    cout << "Votre nom est : " << name;

    cout << "L'adresse IP serveur : ";
    std::getline(cin, server_addr);
    cout << endl;

    Client client;
    client.setAddress(server_addr);
    client.connect();

    // Send messages
//    string name;
//    if ( argc > 1 )
//        name = argv[1];
    for ( int i=0; i<=4; ++i ) {
        string msg = format("client %s, message %d", name.c_str(), i);
        cout << "Client: send '" << msg << "'" << endl << flush;
        client.send( msg );
        string ok = client.receive();
        if ( ok.empty() )
            ok = "failed!";
        cout << "Client: received confirmation '" << msg << "'... "  << ok << endl << flush;
        sleep(2);
    }
    client.send("bye");
    cout << "Client: bye!" << std::endl;
    return 0;
}
