
# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c arvores.c -o arvores.out

build:
	$(CC) $(CFLAGS) main.c arvores.out -o $(EXEC)

clean:
	rm -rf arvores.out