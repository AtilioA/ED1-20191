CC=gcc
CFLAGS=-I. -Wall -lm
DEPS = loja.h
OBJ = teste.o loja.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

progListaArr: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
