.PHONY: clean all
CC=gcc
CFLAGS=-Wall -g
BIN=daytimetcpcli
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
daytimetcpcli: daytimetcpcli.o
	$(CC) $(CFLAGS) $^ -o $@ -lrt