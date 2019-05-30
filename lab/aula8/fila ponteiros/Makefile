CC = gcc
CFLAGS = -g
DEPS = fila.h pilha.h
OBJ = fila.o pilha.o progfila.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filaPilha: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: filaPilha
	./filaPilha

val:
	valgrind -v --leak-check=full ./filaPilha

clean:
	rm -f *.o
