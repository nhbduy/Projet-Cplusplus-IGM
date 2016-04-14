#Makefile
CC = g++ -pthread
OPT = -O6 -Wall -std=c++11 -w
INCLUDE = ./include/
SOURCE = ./src/
LIBS =
OBJS =
#CFLAGS = -fpermissive -Wno-write-strings

all: main client server server_multithreads tool
test : main
socket: client server server_multithreads
tool: tool

#Tool expressions
#Expressions
tool: $(SOURCE)tool.cpp affectation.o binaire.o bloc.o boucle.o conditionnel.o constante.o expression.o ifThenElse.o unaire.o variable.o
	$(CC) $(OPT) $(SOURCE)tool.cpp affectation.o binaire.o bloc.o boucle.o conditionnel.o constante.o expression.o ifThenElse.o unaire.o variable.o -o tool

#Main expressions
main: main.cpp affectation.o binaire.o bloc.o boucle.o conditionnel.o constante.o expression.o ifThenElse.o unaire.o variable.o
	$(CC) $(OPT) main.cpp affectation.o binaire.o bloc.o boucle.o conditionnel.o constante.o expression.o ifThenElse.o unaire.o variable.o -o main
affectation.o: $(INCLUDE)affectation.h $(SOURCE)affectation.cpp
	$(CC) $(OPT) -c $(SOURCE)affectation.cpp
binaire.o: $(INCLUDE)binaire.h $(SOURCE)binaire.cpp
	$(CC) $(OPT) -c $(SOURCE)binaire.cpp
bloc.o: $(INCLUDE)bloc.h $(SOURCE)bloc.cpp
	$(CC) $(OPT) -c $(SOURCE)bloc.cpp
boucle.o: $(INCLUDE)boucle.h $(SOURCE)boucle.cpp
	$(CC) $(OPT) -c $(SOURCE)boucle.cpp
conditionnel.o: $(INCLUDE)conditionnel.h $(SOURCE)conditionnel.cpp
	$(CC) $(OPT) -c $(SOURCE)conditionnel.cpp
constante.o: $(INCLUDE)constante.h $(SOURCE)constante.cpp
	$(CC) $(OPT) -c $(SOURCE)constante.cpp
expression.o: $(INCLUDE)expression.h $(SOURCE)expression.cpp
	$(CC) $(OPT) -c $(SOURCE)expression.cpp
ifThenElse.o: $(INCLUDE)ifThenElse.h $(SOURCE)ifThenElse.cpp
	$(CC) $(OPT) -c $(SOURCE)ifThenElse.cpp
unaire.o: $(INCLUDE)unaire.h $(SOURCE)unaire.cpp
	$(CC) $(OPT) -c $(SOURCE)unaire.cpp
variable.o: $(INCLUDE)variable.h $(SOURCE)variable.cpp
	$(CC) $(OPT) -c $(SOURCE)variable.cpp

#Client-server sockets
network.o: $(INCLUDE)network.h $(SOURCE)network.cpp
	$(CC) $(OPT) -c $(SOURCE)network.cpp

format.o: $(INCLUDE)format.h $(SOURCE)format.cpp
	$(CC) $(OPT) -c $(SOURCE)format.cpp

client: network.o format.o $(SOURCE)client.cpp
	$(CC) $(OPT) $(SOURCE)client.cpp network.o format.o -o client

server: network.o format.o $(SOURCE)server.cpp
	$(CC) $(OPT) $(SOURCE)server.cpp network.o format.o -o server

server_multithreads: network.o format.o $(SOURCE)server_multithreads.cpp
	$(CC) $(OPT) $(SOURCE)server_multithreads.cpp network.o format.o -o server_multithreads

#Clean files
clean:
	rm -f *.o

#Clean txt
txtclean:
	rm -f *.txt

distclean: clean txtclean
	rm -f server
	rm -f client
	rm -f server_multithreads
	rm -f main
	rm -f tool
