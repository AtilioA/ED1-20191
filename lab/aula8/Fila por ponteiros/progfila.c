/*
*********************************
* Programa testador 4 do TAD Fila (usando pilhas)
* Testa funcoes cria_fila, imprimeFila, insere, retira,  destroi_fila e separa_filas
*********************************
*/
#include <stdio.h>
#include "filaPonteiro.h"

int main()
{
    // criando a fila vazia
    printf("Criando fila...\n");
    Fila *f = cria_fila();
    printf("Fila criada.\n");
    // tentando imprimir a fila (ainda vazia neste momento)
    printf("Imprimindo fila...\n");
    imprimeFila(f);

    printf("Inicializando pessoas...\n");
    // criando algumas pessoas apenas para testar (mais adequado seria carregar de um arquivo)
    Pessoa *pessoa1 = inicializaPessoa("celula1", 51, "rua da celula1");
    Pessoa *pessoa2 = inicializaPessoa("celula2", 63, "rua da celula2");
    Pessoa *pessoa3 = inicializaPessoa("celula3", 10, "rua da celula3");
    Pessoa *pessoa4 = inicializaPessoa("celula4", 70, "rua da celula4");
    Pessoa *pessoa5 = inicializaPessoa("celula5", 20, "rua da celula5");
    Pessoa *pessoa6 = inicializaPessoa("celula6", 30, "rua da celula6");
    Pessoa *pessoa7 = inicializaPessoa("celula7", 40, "rua da celula7");
    Pessoa *pessoa8 = inicializaPessoa("celula8", 45, "rua da celula8");
    Pessoa *pessoa9 = inicializaPessoa("celula9", 65, "rua da celula9");
    Pessoa *pessoa10 = inicializaPessoa("celula10", 67, "rua da celula10");
    Pessoa *pessoa11 = inicializaPessoa("celula11", 13, "rua da celula11");
    printf("Inicializacao concluida.\n");
    //Insere as pessoas na fila
    printf("Inserindo na fila...\n");
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
    //Imprime a fila com todas as celulas
    imprimeFila(f);
    // Retira pessoa1 do inicio da fila
    Pessoa *retirado = retira(f);
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

    Fila *f_maiores = cria_fila();
    Fila *f_menores = cria_fila();

    separa_filas(f, f_maiores, f_menores);

    printf("---------- Imprime fila-----------\n");
    //Imprime a fila com todas as pessoas
    imprimeFila(f);

    printf("---------- Imprime fila Maiores-----------\n");
    //Imprime a fila com todas as pessoas maiores que 60
    imprimeFila(f_maiores);

    printf("---------- Imprime fila Menores-----------\n");
    //Imprime a fila com todas as pessoas menores que 60
    imprimeFila(f_menores);

    // //libera a mem�ria ocupada pelas filas
    f = destroi_fila(f);

    f_menores = destroi_fila(f_menores);
    f_maiores = destroi_fila(f_maiores);
}
