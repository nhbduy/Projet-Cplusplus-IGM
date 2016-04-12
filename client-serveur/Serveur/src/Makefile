#Makefile
CC = g++
INCLUDE = /usr/lib
LIBS = 
OBJS = 
CFLAGS = -fpermissive -Wno-write-strings

all: serveur coordinator client

chat_server: 
	$(CC) -o serveur serveur.cpp $(CFLAGS) $(LIBS)
chat_coordinator:
	$(CC) -o coordinator coordinator.cpp $(CFLAGS) $(LIBS)
chat_client:
	$(CC) -o client client.cpp $(CFLAGS) $(LIBS)

clean:
	rm -f serveur coordinator client
