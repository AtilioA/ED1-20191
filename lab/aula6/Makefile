CC = gcc
CFLAGS = -g
DEPS = pilha.h
OBJ = pilha.o progpilha.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilhaEstatica: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: pilhaEstatica
	./pilhaEstatica

val:
	valgrind -v --leak-check=full ./pilhaEstatica
	
clean:
	rm -f *.o
