CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = cliente.c pilha.c item.c
OBJ = $(SRC:.c=.o)
DEPS = pilha.h item.h

all: cliente

cliente: $(OBJ)
	$(CC) $(CFLAGS) -o cliente $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o cliente.exe

.PHONY: all clean