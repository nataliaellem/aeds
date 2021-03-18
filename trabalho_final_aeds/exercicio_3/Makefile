# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c fila.c -o fila.out

build:
	$(CC) $(CFLAGS) main.c fila.out -o $(EXEC)

clean:
	rm -rf fila.out 