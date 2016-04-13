#include "network.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <memory>
#include <unistd.h>

using namespace std;

bool g_shutdown = false;

void shutdown_handler() {
    cout << "Server: started..." << endl;
    sleep(15);
    cout << "Server: stopped!" << endl;
    g_shutdown = true;
}

void client_handler( Client *client, int k ) {
    cout << "Server: client " << k << " connected!,"
         << " address: " << client->address()
         << " port : " << client->port()
         << endl << flush;
    for ( int i=0; true ; ++i ) {
        string msg = client->receive();
        cout << "Server: received '" << msg << "'" << endl << flush;
        if ( msg == "bye" )
            break;
        else
            client->send("ok");
    }
   delete client;
}

int main(int argc, char *argv[]) {
    Server server;
    server.start();
    thread s(shutdown_handler);
    vector<unique_ptr<thread>> threads; // Garbage collection
    for( int i=0; !g_shutdown ; ++i ) {
        Client *client = server.connect();
        if ( !client )
            exit(0);
        threads.push_back( unique_ptr<thread>( new thread(client_handler, client, i) ));
    }
   //server.stop();
   server.close();
   return 0;
}
