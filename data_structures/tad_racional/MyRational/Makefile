all: rational.o client.o
	gcc rational.o client.o -std=c99 -o client -Wall

rational.o:
	gcc -c rational.c

client.o:
	gcc -c client.c

clean:
	rm *.o client