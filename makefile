all: list.o musicLib.o main.o
	gcc list.o musicLib.o main.o -o run

list.o: list.c list.h
	gcc -c list.c

musicLib.o: musicLib.c musicLib.h
	gcc -c musicLib.c

main.o: main.c
	gcc -c main.c

run: all
	./run
