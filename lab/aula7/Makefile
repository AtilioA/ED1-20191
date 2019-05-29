CC = gcc
CFLAGS = -g
DEPS = notacaopolonesa.h pilha.h
OBJ = notacaopolonesa.o pilha.o progpilha.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calculadoraPilha: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: calculadoraPilha
	./calculadoraPilha

val:
	valgrind -v --leak-check=full ./calculadoraPilha

clean:
	rm -f *.o
