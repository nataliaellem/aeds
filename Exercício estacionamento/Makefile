
# All makefile tasks
.PHONY: all build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c estacionamento.c -o estacionamento.out

build:
	$(CC) $(CFLAGS) main.c estacionamento.out -o $(EXEC)

clean:
	rm -rf estacionamento.out