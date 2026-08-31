CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o string_utils.o
	$(CC) $(CFLAGS) main.o string_utils.o -o prog

main.o: main.c string_utils.h
	$(CC) $(CFLAGS) -c main.c

string_utils.o: string_utils.c string_utils.h
	$(CC) $(CFLAGS) -c string_utils.c

clean:
	rm -f *.o prog