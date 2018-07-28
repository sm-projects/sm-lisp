CC = cc
CFLAGS = -std=c99 -Wall -g
LFLAGS = -ledit
FILES = mpc.c eval.c parsing.c test-mpc.c
PLATFORM = $(shell uname)
BINARY = smlispy

all: $(FILES)
	$(CC) $(CFLAGS) $^ $(LFLAGS)  -o $(BINARY)
