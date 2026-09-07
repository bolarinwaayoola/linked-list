# list/Makefile
#
# Makefile for list implementation and test file.
#

CC = gcc
CFLAGS = -Wall -Wextra -g

list: main.c list/list.c
	$(CC) $(CFLAGS) -o list main.c list/list.c

clean:
	rm -f list