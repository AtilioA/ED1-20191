CC = gcc
CFLAGS = -g
DEPS = fila.h pilha .h
OBJ = fila.o pilha.o progfila.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fila: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make cleanO

run: fila
	./fila

voado: fila run cleanO

val:
	valgrind -v --leak-check=full --track-origins=yes ./fila

valzin:
	valgrind ./fila

cleanO:
	rm -f *.o

clean:
	make cleanO
	rm -f ${EXEC}
	rm -f main
