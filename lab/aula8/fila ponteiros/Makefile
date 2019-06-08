CC = gcc
CFLAGS = -g
DEPS = fila.h
OBJ = fila.o progfila.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fila: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: fila
	./fila

voado: fila run

val:
	valgrind -v --leak-check=full --track-origins=yes ./fila

valzin:
	valgrind ./fila

clean:
	rm -f *.o
