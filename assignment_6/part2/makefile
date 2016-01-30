CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o exception.o part2.o
	$(CC) main.o exception.o part2.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

exception.o: exception.cpp exception.h
	$(CC) $(CFLAGS) exception.cpp

part2.o: part2.cpp
	$(CC) $(CFLAGS) part2.cpp

clean:
	rm -f *.o driver
