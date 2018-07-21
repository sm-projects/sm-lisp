CC = cc
CFLAGS = -std=c99 -Wall -g
LFLAGS = -ledit
FILES = mpc.c smrepl.c
PLATFORM = $(shell uname)
BINARY = prompt

all: $(FILES)
	$(CC) $(CFLAGS) $^ $(LFLAGS)  -o $(BINARY)
