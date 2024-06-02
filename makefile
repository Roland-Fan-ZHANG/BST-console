CC=gcc
CFLAGS=-std=c99 -Wall -Werror
LDFLAGS=
DEPS=src/visualtree.h src/tree.h
OBJ=src/visualtree.o src/tree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) main main.o current-tree.dot current-tree.pdf