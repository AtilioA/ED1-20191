CC=gcc
CFLAGS=-I. -Wall -lm
DEPS = listahet.h
OBJ = proglistahet.o listahet.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	exe

voado: exe run

clean:
	rm -f *.o
