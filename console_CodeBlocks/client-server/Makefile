#Makefile
CC = g++
INCLUDE = /usr/lib
LIBS = 
OBJS = 
CFLAGS = -fpermissive -Wno-write-strings

all: server client

server: 
	$(CC) -o server server.cpp $(CFLAGS) $(LIBS)

client:
	$(CC) -o client client.cpp $(CFLAGS) $(LIBS)

clean:
	rm -f serveur client
