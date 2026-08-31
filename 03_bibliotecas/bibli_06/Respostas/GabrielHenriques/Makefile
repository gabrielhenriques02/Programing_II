CC = gcc
CFLAGS = -Wall -Wextra -g

all: prog

prog: main.o temperature_conversor.o
	$(CC) $(CFLAGS) main.o temperature_conversor.o -o prog

main.o: main.c temperature_conversor.h
	$(CC) $(CFLAGS) -c main.c

temperature_conversor.o: temperature_conversor.c temperature_conversor.h
	$(CC) $(CFLAGS) -c temperature_conversor.c

clean:
	rm -f *.o prog