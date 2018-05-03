.PHONY: clean all
CC=gcc
CFLAGS=-Wall -g
BIN=daytimetcpcli.out
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
daytimetcpcli.out: daytimetcpcli.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt