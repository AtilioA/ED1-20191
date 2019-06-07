CC=gcc
CFLAGS=-I.   -lm
DEPS = lista.h
OBJ =  lista.o proglista_arranjo.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./exe

voado: exe
	./exe

clean:
	rm -f *.o
