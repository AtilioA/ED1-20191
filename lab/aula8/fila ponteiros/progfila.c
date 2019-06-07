/*
*********************************
* Programa testador 4 do TAD Fila (usando pilhas)
* Testa funcoes cria_fila, imprime_fila, insere, retira,  destroi_fila e separa_filas
*********************************
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
     // criando a fila vazia
    printf("Criando fila...\n");
    Fila* f = cria_fila();
    printf("Fila criada.\n");
    // tentando imprimir a fila (ainda vazia neste momento)
    printf("Imprimindo fila...\n");
    imprime_fila(f);

    printf("Inicializando celulas...\n");
     // criando algumas celulas apenas para testar (mais adequado seria carregar de um arquivo)
    tCelula* celula1 = inicializaC("celula1", 51, "rua da celula1");
    // tCelula* celula2= inicializaC("celula2", 63, "rua da celula2");
    // tCelula* celula3= inicializaC("celula3", 10, "rua da celula3");
    // tCelula* celula4= inicializaC("celula4", 70, "rua da celula4");
    // tCelula* celula5= inicializaC("celula5", 20, "rua da celula5");
    // tCelula* celula6= inicializaC("celula6", 30, "rua da celula6");
    // tCelula* celula7= inicializaC("celula7", 40, "rua da celula7");
    // tCelula* celula8= inicializaC("celula8", 45, "rua da celula8");
    // tCelula* celula9= inicializaC("celula9", 65, "rua da celula9");
    // tCelula* celula10= inicializaC("celula10", 67, "rua da celula10");
    // tCelula* celula11= inicializaC("celula11", 13, "rua da celula11");
    printf("Inicializacao concluida.\n");

    //Insere os celulas na fila
    printf("Inserindo na fila...\n");
    insere(celula1, f);
    // insere(celula2, f);
    // insere(celula3, f);
    // insere(celula4, f);
    // insere(celula5, f);
    // insere(celula6, f);
    // insere(celula7, f);
    // insere(celula8, f);
    // insere(celula9, f);
    // insere(celula10, f);
    // insere(celula11, f);
    printf("Insercao concluida.\n");
    /*
    printf ("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as celulas
    imprime_fila(f);
    */
    // // Retira celula1 do inicio da fila
    // tCelula* retirado = retira (f);
    // // Insere celula1 no final da fila
    // insere (retirado, f);
    // // Retira celula2 do inicio da fila
    // retirado = retira (f);
    // // Insere celula2 no final da fila
    // insere (retirado, f);
    // // Retira celula3 do inicio da fila
    // retirado = retira (f);
    // // Insere celula3 no final da fila
    // insere (retirado, f);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as celulas
    // imprime_fila(f);

    // // Retira celula4 do inicio da fila
    // retirado = retira (f);
    // // Insere celula4 no final da fila
    // insere (retirado, f);
    // // Retira celula5 do inicio da fila
    // retirado = retira (f);
    // // Insere celula5 no final da fila
    // insere (retirado, f);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as celulas
    // imprime_fila(f);

    // Fila* f_maiores = cria_fila();
    // Fila* f_menores = cria_fila();

    // separa_filas(f, f_maiores, f_menores);

    // printf ("---------- Imprime fila-----------\n");
    // //Imprime a fila com todas as celulas
    // imprime_fila(f);

    // printf ("---------- Imprime fila Maiores-----------\n");
    // //Imprime a fila com todas as celulas maiores que 60
    // imprime_fila(f_maiores);

    // printf ("---------- Imprime fila Menores-----------\n");
    // //Imprime a fila com todas as celulas menores que 60
    // imprime_fila(f_menores);

    // //libera a mem�ria ocupada pela fila
    // f = destroi_fila(f);
    // f_maiores = destroi_fila(f_maiores);
    // f_menores = destroi_fila(f_menores);
    // destroi_celula(celula11);
}
