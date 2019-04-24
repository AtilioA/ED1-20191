
/*
Baseado na implementa��o do livro Projeto de Algoritmos
Modifica��es: VM
========================================================================== */
#include <sys/time.h>

#include "lista.h"

/* ========================================================================== */

int main(int argc, char *argv[])
{
    struct timeval t;

    tLista lista;
    tItem item;
    int vetor[MAXTAM];
    int i, j, k, n, max;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    max = 10;
    FLVazia(&lista);
    printf("fodase\n");

    /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
    for (i = 0; i < max; i++)
        vetor[i] = i + 1;
    for (i = 0; i < max; i++)
    {
        k = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        j = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        n = vetor[k];
        vetor[k] = vetor[j];
        vetor[j] = n;
    }
    /*insere cada chave na lista */
    for (i = 0; i < max; i++)
    {
        item.chave = vetor[i];
        insere(item, &lista);
        printf("Inserindo %d...\n", item.chave);
    }
    imprime(&lista);


    tLista lista2;
    printf("Copiando...\n");
    copiaLista(&lista, &lista2);
    imprime(&lista2);
    printf("Partindo lista 1 em duas:\n");
    partirLista(4, &lista, &lista2);
    printf("Lista 1: \n");
    imprime(&lista);
    printf("Lista 2: \n");
    imprime(&lista2);

    /*retira cada chave da lista */
    i = 1;
    while (quantidade(&lista) > 0)
    {
        /*retira chave apontada */
        retira(i, &lista, &item);
        printf("Retirando %d...\n", item.chave);
    }
    imprime(&lista);
    imprime(&lista2);
    return (0);
}
