
# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c pilhas.c -o pilhas.out

build:
	$(CC) $(CFLAGS) main.c pilhas.out -o $(EXEC)

clean:
	rm -rf pilhas.out