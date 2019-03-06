CC = gcc
CFLAGS = -Wall -fPIC

LDFLAGS = -L.

build:  tema1

tema1: tema1.o
	gcc -g -o tema1 -Wall tema1.o -lcompare -L.

tema1.o: tema1.c
	gcc -g -c tema1.c

clean:
	rm -f *.o  tema1