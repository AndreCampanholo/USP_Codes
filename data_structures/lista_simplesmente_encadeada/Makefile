CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = main_encadeada.c lista_encadeada.c item.c
OBJ = $(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main

.PHONY: all clean