CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o ponto.o
	$(CC) $(CFLAGS) main.o ponto.o -o prog -lm

main.o: main.c ponto.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

clean:
	rm -f *.o prog