# All makefile tasks
.PHONY: all build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: build clean

build:
	$(CC) $(CFLAGS) -c lib/linked_list.c -o linked_list.out
	$(CC) $(CFLAGS) -c lib/user.c -o user.out
	$(CC) $(CFLAGS) main.c linked_list.out user.out -o $(EXEC)

clean:
	rm -rf linked_list.out user.out
