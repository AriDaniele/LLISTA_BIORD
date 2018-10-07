all: ex1

ex1: main.o llista.o
	gcc main.o llista.o -o ex1

llista.o: llista.c llista.h
	gcc -c llista.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

