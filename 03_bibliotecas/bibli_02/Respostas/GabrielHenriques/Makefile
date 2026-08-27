CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o matrix_utils.o
	$(CC) $(CFLAGS) main.o matrix_utils.o -o prog

main.o: main.c matrix_utils.h
	$(CC) $(CFLAGS) -c main.c

matrix_utils.o: matrix_utils.c matrix_utils.h
	$(CC) $(CFLAGS) -c matrix_utils.c

clean:
	rm -f *.o prog