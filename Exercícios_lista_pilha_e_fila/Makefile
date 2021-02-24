# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c lista_encadeada.c -o lista_encadeada.out
	$(CC) $(CFLAGS) -c lista_circular.c -o lista_circular.out
	$(CC) $(CFLAGS) -c pilha.c -o pilha.out
	$(CC) $(CFLAGS) -c estacionamento.c -o estacionamento.out

build:
	$(CC) $(CFLAGS) main.c lista_encadeada.out lista_circular.out pilha.out estacionamento.out -o $(EXEC)

clean:
	rm -rf lista_encadeada.out lista_circular.out pilha.out estacionamento.out