CC=gcc
CFLAGS= -I. -lm -g -Wall
DEPS = listahet.h
OBJ =  listahet.o proglistahet.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

listaHet: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	# -make clean
	mv listaHet prog

run:
	make
	./prog

val:
	valgrind ./prog

clean:
	rm -f *.o
