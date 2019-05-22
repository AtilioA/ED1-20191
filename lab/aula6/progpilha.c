/*
*********************************
* Programa testador do TAD Pilha
*********************************
*/
#include <stdio.h>
#include "pilha.h"

int main()
{
    // criando pilhas vazias
    tPilha *p = criaPilha();
    tPilha *p2 = criaPilha();

    // tentando imprimir a pilha (ainda vazia neste momento)
    imprimePilha(p);

    // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    tPessoa *pessoa1= inicializaPessoa("pessoa1", 51, "rua da pessoa1");
    tPessoa *pessoa2= inicializaPessoa("pessoa2", 63, "rua da pessoa2");
    tPessoa *pessoa3= inicializaPessoa("pessoa3", 10, "rua da pessoa3");
    tPessoa *pessoa4= inicializaPessoa("pessoa4", 70, "rua da pessoa4");
    tPessoa *pessoa5= inicializaPessoa("pessoa5", 20, "rua da pessoa5");
    tPessoa *pessoa6= inicializaPessoa("pessoa6", 30, "rua da pessoa6");
    tPessoa *pessoa7= inicializaPessoa("pessoa7", 40, "rua da pessoa7");
    tPessoa *pessoa8= inicializaPessoa("pessoa8", 45, "rua da pessoa8");
    tPessoa *pessoa9= inicializaPessoa("pessoa9", 65, "rua da pessoa9");
    tPessoa *pessoa10= inicializaPessoa("pessoa10", 67, "rua da pessoa10");
    tPessoa *pessoa11= inicializaPessoa("pessoa11", 13, "rua da pessoa11");

    // Insere os pessoas na pilha
    push(pessoa1, p);
    push(pessoa2, p);
    push(pessoa3, p);
    push(pessoa4, p);
    push(pessoa5, p);
    push(pessoa6, p);
    push(pessoa7, p);
    push(pessoa8, p);
    push(pessoa9, p);
    push(pessoa10, p);
    push(pessoa11, p);

    // pessoa11 vai ficar na pilha p2
    push(pessoa11, p2);

    printf ("---------- Imprime pilha-----------\n");
    // Imprime a pilha com todas as pessoas
    imprimePilha(p);
    imprimePilha(p2);

    // Retira pessoa da pilha p e coloca na pilha p2
    printf("eh isto\n");
    // tPessoa *teste = pop(p);
    // teste = pop(p);
    // imprimePessoa(teste);
    push(pop(p), p2);

    // imprimePilha(p);
    printf("\np2\n");
    imprimePilha(p2);

    // //libera a memoria ocupada pelas pilhas
    destroiPilha(p);
    destroiPilha(p2);

}
