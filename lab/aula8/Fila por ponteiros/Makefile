CC = gcc
CFLAGS = -Wall -g
DEPS = filaPonteiro.h
OBJ = filaPonteiro.o progfila.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filaPonteiro: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make cleanO

run: filaPonteiro
	./filaPonteiro

voado: filaPonteiro run cleanO

val:
	valgrind -v --leak-check=full --track-origins=yes ./filaPonteiro

valzin:
	valgrind ./filaPonteiro

cleanO:
	rm -f *.o

clean:
	make cleanO
	rm -f ${EXEC}
	rm -f main
