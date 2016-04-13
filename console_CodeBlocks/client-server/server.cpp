#include "network.h"
#include <iostream>
#include <string>

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
    cout << "Client: '" << client->address() << "' "
              << "Port : " << client->port()
              << endl;
    for ( int i=0; ; ++i ) {
        string msg = client->receive();
        cout << "<< '" << msg << "'" << endl;
        client->send("ok");
        if ( msg == "bye" )
            break;
    }
   delete client;
   //server.stop();
   server.close();
   return 0;
}
