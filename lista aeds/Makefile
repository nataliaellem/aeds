# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c lista.c -o lista.out

build:
	$(CC) $(CFLAGS) main.c lista.out -o $(EXEC)

clean:
	rm -rf lista.out