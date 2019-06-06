/*
*********************************
* Programa testador 4 do TAD Fila (usando pilhas)
* Testa funcoes cria_fila, imprimeFila, insere, retira,  destroiFila e separa_filas
*********************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

int main()
{
    // criando a fila vazia
    tFila *f = criaFila();
    // tentando imprimir a fila (ainda vazia neste momento)
    imprimeFila(f);

     // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    tPessoa* pessoa1= inicializaPessoa("pessoa1", 51, "rua da pessoa1");
    tPessoa* pessoa2= inicializaPessoa("pessoa2", 63, "rua da pessoa2");
    tPessoa* pessoa3= inicializaPessoa("pessoa3", 10, "rua da pessoa3");
    tPessoa* pessoa4= inicializaPessoa("pessoa4", 70, "rua da pessoa4");
    tPessoa* pessoa5= inicializaPessoa("pessoa5", 20, "rua da pessoa5");
    tPessoa* pessoa6= inicializaPessoa("pessoa6", 30, "rua da pessoa6");
    tPessoa* pessoa7= inicializaPessoa("pessoa7", 40, "rua da pessoa7");
    tPessoa* pessoa8= inicializaPessoa("pessoa8", 45, "rua da pessoa8");
    tPessoa* pessoa9= inicializaPessoa("pessoa9", 65, "rua da pessoa9");
    tPessoa* pessoa10= inicializaPessoa("pessoa10", 67, "rua da pessoa10");
    tPessoa* pessoa11= inicializaPessoa("pessoa11", 13, "rua da pessoa11");
    printf("deus inicializou o server\n");

    //Insere os pessoas na fila

    tCelula *insere1 = inicializaCelula(pessoa1);
    tCelula *insere2 = inicializaCelula(pessoa2);
    tCelula *insere3 = inicializaCelula(pessoa3);
    tCelula *insere4 = inicializaCelula(pessoa4);
    tCelula *insere5 = inicializaCelula(pessoa5);
    tCelula *insere6 = inicializaCelula(pessoa6);
    tCelula* insere7 = inicializaCelula(pessoa7);
    tCelula *insere8 = inicializaCelula(pessoa8);
    tCelula *insere9 = inicializaCelula(pessoa9);
    tCelula *insere10 = inicializaCelula(pessoa10);
    tCelula *insere11 = inicializaCelula(pessoa11);

    insere(insere1, f);
    insere(insere2, f);
    insere(insere3, f);
    insere(insere4, f);
    insere(insere5, f);
    insere(insere6, f);
    insere(insere7, f);
    insere(insere8, f);
    insere(insere9, f);
    insere(insere10, f);
    insere(insere11, f);
    printf("deus inseriu o server\n");


    printf ("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprimeFila(f);
    /*
    */
    // // Retira pessoa1 do inicio da fila
    // Pessoa* retirado = retira (f);
    // // Insere pessoa1 no final da fila
    // insere (retirado, f);
    // // Retira pessoa2 do inicio da fila
    // retirado = retira (f);
    // // Insere pessoa2 no final da fila
    // insere (retirado, f);
    // // Retira pessoa3 do inicio da fila
    // retirado = retira (f);
    // // Insere pessoa3 no final da fila
    // insere (retirado, f);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as pessoas
    // imprimeFila(f);

    // // Retira pessoa4 do inicio da fila
    // retirado = retira (f);
    // // Insere pessoa4 no final da fila
    // insere (retirado, f);
    // // Retira pessoa5 do inicio da fila
    // retirado = retira (f);
    // // Insere pessoa5 no final da fila
    // insere (retirado, f);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as pessoas
    // imprimeFila(f);

    // tFila* f_maiores = cria_fila();
    // tFila* f_menores = cria_fila();

    // separa_filas(f, f_maiores, f_menores);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as pessoas
    // imprimeFila(f);

    // printf ("---------- Imprime fila Maiores-----------\n");
    // //Imprime a fila com todas as pessoas maiores que 60
    // imprimeFila(f_maiores);

    // printf ("---------- Imprime fila Menores-----------\n");
    // //Imprime a fila co1,
    // imprimeFila(f_menores);

    // //libera a mem�ria ocupada pela fila
    // f_maiores = destroiFila(f_maiores);
    // f_menores = destroiFila(f_menores);
    f = destroiFila(f);


    destroiCelula(insere1);
    destroiCelula(insere2);
    destroiCelula(insere3);
    destroiCelula(insere4);
    destroiCelula(insere5);
    destroiCelula(insere6);
    destroiCelula(insere7);
    destroiCelula(insere8);
    destroiCelula(insere9);
    destroiCelula(insere10);
    destroiCelula(insere11);


}
