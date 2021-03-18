# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c arvore.c -o arvore.out
	$(CC) $(CFLAGS) -c fila.c -o fila.out

build:
	$(CC) $(CFLAGS) main.c arvore.out fila.out -lm -o $(EXEC)

clean:
	rm -rf arvore.out fila.out