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
	$(CC) $(CFLAGS) -c lib/login.c -o login.out
	$(CC) $(CFLAGS) -c lib/logger.c -o logger.out
	$(CC) $(CFLAGS) -c lib/date.c -o date.out
	$(CC) $(CFLAGS) main.c linked_list.out user.out login.out logger.out date.out -o $(EXEC)

clean:
	rm -rf linked_list.out user.out login.out logger.out date.out
