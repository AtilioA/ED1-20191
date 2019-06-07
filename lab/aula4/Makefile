CC=gcc
CFLAGS=-I. -Wall -lm
DEPS = listaencadeada.h
OBJ = main.o listaencadeada.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	exe

clean:
	rm -f *.o
