CC = gcc
CFLAGS = -Wall -g
DEPS = filaVetorCircular.h
OBJ = filaVetorCircular.o progfila.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filaVetorCircular: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make cleanO

run: filaVetorCircular
	./filaVetorCircular

voado: filaVetorCircular run cleanO

val:
	valgrind -v --leak-check=full --track-origins=yes ./filaVetorCircular

valzin:
	valgrind ./filaVetorCircular

cleanO:
	rm -f *.o

clean:
	make cleanO
	rm -f ${EXEC}
	rm -f main
