CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o exception.o GeneralTree.o node.o
	$(CC) main.o exception.o GeneralTree.o node.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

exception.o: exception.cpp exception.h
	$(CC) $(CFLAGS) exception.cpp

GeneralTree.o: GeneralTree.cpp GeneralTree.h
	$(CC) $(CFLAGS) GeneralTree.cpp

node.o: node.cpp
	$(CC) $(CFLAGS) node.cpp

clean:
	rm -f *.o driver 
