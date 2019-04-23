CC=gcc
CFLAGS= -I. -lm
DEPS = listaencadeada.h
OBJ =  listaencadeada.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

progListaArr: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./progListaArr

val:
	valgrind ./progListaArr

clean:
	rm -f *.o
