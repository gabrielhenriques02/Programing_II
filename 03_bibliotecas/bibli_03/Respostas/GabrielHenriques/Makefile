CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o data.o
	$(CC) $(CFLAGS) main.o data.o -o prog

main.o: main.c data.h
	$(CC) $(CFLAGS) -c main.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

clean:
	rm -f *.o prog