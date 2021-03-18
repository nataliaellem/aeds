# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c fila.c -o fila.out
	$(CC) $(CFLAGS) -c pista_tie_fighters.c -o pista_tie_fighters.out

build:
	$(CC) $(CFLAGS) Main.c fila.out pista_tie_fighters.out -o $(EXEC)

clean:
	rm -rf fila.out pista_tie_fighters.out 