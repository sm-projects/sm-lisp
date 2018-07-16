CC = cc
CFLAGS = -std=c99 -Wall -g
LFLAGS = -ledit
FILES = smrepl.c
PLATFORM = $(shell uname)
BINARY = prompt

all: $(FILES)
	$(CC) $(CFLAGS) $^ $(LFLAGS)  -o $(BINARY)
