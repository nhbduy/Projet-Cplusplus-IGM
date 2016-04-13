#Makefile
CC = g++ -pthread
OPT = -O6 -Wall -std=c++11
INCLUDE = /usr/lib
LIBS =
OBJS =
CFLAGS = -fpermissive -Wno-write-strings

all: client server server_multithreads

network.o: network.h network.cpp
	$(CC) $(OPT) -c network.cpp

format.o: format.h format.cpp
	$(CC) $(OPT) -c format.cpp

client: network.o format.o client.cpp
	$(CC) $(OPT) client.cpp network.o format.o -o client $(CFLAGS) $(LIBS)

server: network.o format.o server.cpp
	$(CC) $(OPT) server.cpp network.o format.o -o server $(CFLAGS) $(LIBS)

server_multithreads: network.o format.o server_multithreads.cpp
	$(CC) $(OPT) server_multithreads.cpp network.o format.o -o server_multithreads $(CFLAGS) $(LIBS)

clean:
	rm -f *.o

distclean: clean
	rm -f server
	rm -f client
	rm -f server_multithreads
