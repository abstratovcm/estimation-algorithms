CC=g++
CFLAGS=-c -Wall

all: matrix

matrix: Debug.o matrix.o
	$(CC) Debug.o -o matrix

Debug.o: Debug.cpp
	$(CC) $(CFLAGS) Debug.cpp

clean:
	rm -rf *o matrix
