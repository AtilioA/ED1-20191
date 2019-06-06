CC = gcc
CFLAGS = -g
DEPS = fila.h pilha.h
OBJ = fila.o pilha.o progfila.o
EXEC = filhaPilha

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: ${EXEC}
	./${EXEC}

val: ${EXEC}
	valgrind --leak-check=full ./${EXEC}

valzao: ${EXEC} #tamo safe
	valgrind -v --leak-check=full --show-leak-kinds=all ./${EXEC}

valzin:
	valgrind ./${EXEC}

clean:
	rm -f *.o
	rm -f ${EXEC}
