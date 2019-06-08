/*
*********************************
* Programa testador 4 do TAD tFila (usando pilhas)
* Testa funcoes criaFila, imprimeFila, insere, retira,  destroiFila e separaFilas
*********************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filaVetorCircular.h"

int main()
{
    // criando a fila vazia
    printf("Criando fila...\n");
    tFila *f = criaFila();
    printf("Fila criada com sucesso.\n");

    // tentando imprimir a fila (ainda vazia neste momento)
    printf("Imprimindo fila vazia...\n");
    imprimeFila(f);

    printf("Inicializando pessoas...\n");
    // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    tPessoa *pessoa1 = inicializaPessoa("pessoa1", 51, "rua da pessoa1");
    tPessoa *pessoa2 = inicializaPessoa("pessoa2", 63, "rua da pessoa2");
    tPessoa *pessoa3 = inicializaPessoa("pessoa3", 10, "rua da pessoa3");
    tPessoa *pessoa4 = inicializaPessoa("pessoa4", 70, "rua da pessoa4");
    tPessoa *pessoa5 = inicializaPessoa("pessoa5", 20, "rua da pessoa5");
    tPessoa *pessoa6 = inicializaPessoa("pessoa6", 30, "rua da pessoa6");
    tPessoa *pessoa7 = inicializaPessoa("pessoa7", 40, "rua da pessoa7");
    tPessoa *pessoa8 = inicializaPessoa("pessoa8", 45, "rua da pessoa8");
    tPessoa *pessoa9 = inicializaPessoa("pessoa9", 65, "rua da pessoa9");
    tPessoa *pessoa10 = inicializaPessoa("pessoa10", 67, "rua da pessoa10");
    tPessoa *pessoa11 = inicializaPessoa("pessoa11", 13, "rua da pessoa11");
    printf("Inicializacao concluida.\n");

    printf("Inserindo pessoas...\n");
    //Insere os pessoas na fila
    insere(pessoa1, f);
    insere(pessoa2, f);
    insere(pessoa3, f);
    insere(pessoa4, f);
    insere(pessoa5, f);
    insere(pessoa6, f);
    insere(pessoa7, f);
    insere(pessoa8, f);
    insere(pessoa9, f);
    insere(pessoa10, f);
    insere(pessoa11, f);
    printf("Insercao concluida.\n");

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprimeFila(f);

    // Retira pessoa1 do inicio da fila
    tPessoa *retirado = retira(f);
    // Insere pessoa1 no final da fila
    insere(retirado, f);
    // Retira pessoa2 do inicio da fila
    retirado = retira(f);
    // Insere pessoa2 no final da fila
    insere(retirado, f);
    // Retira pessoa3 do inicio da fila
    retirado = retira(f);
    // Insere pessoa3 no final da fila
    insere(retirado, f);
    // Retira pessoa4 do inicio da fila
    retirado = retira(f);
    // Insere pessoa4 no final da fila
    insere(retirado, f);
    // Retira pessoa5 do inicio da fila
    retirado = retira(f);
    // Insere pessoa5 no final da fila
    insere(retirado, f);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprimeFila(f);

    tFila *fMaiores = criaFila();
    tFila *fMenores = criaFila();

    separaFilas(f, fMaiores, fMenores);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprimeFila(f);

    printf("---------- Imprime fila Maiores-----------\n");
    //Imprime a fila com todas as pessoas maiores que 60
    imprimeFila(fMaiores);

    printf("---------- Imprime fila Menores-----------\n");
    //Imprime a fila com todas as pessoas menores que 60
    imprimeFila(fMenores);

    //libera a memória ocupada pela fila
    fMaiores = destroiFila(fMaiores);
    fMenores = destroiFila(fMenores);
    f = destroiFila(f);
    destroiPessoa(pessoa11);

    return 0;
}
