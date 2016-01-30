CC=g++ -std=c++11
DEBUG = -g
CFLAGS= -c -Wall $(DEBUG)

all: driver

driver: main.o polynomial.o shwe_lib.o
	$(CC) $(DEBUG) main.o polynomial.o shwe_lib.o -o driver.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

polynomial.o: polynomial.h polynomial.cpp
	$(CC) $(CFLAGS) polynomial.cpp 

shwe_lib.o: shwe_lib.h shwe_lib.cpp
	$(CC) $(CFLAGS) shwe_lib.cpp

clean:
	rm -f *.o driver
