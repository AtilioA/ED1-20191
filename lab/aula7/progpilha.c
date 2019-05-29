#include <stdio.h>
#include "pilha.h"
#include "notacaopolonesa.h"

int main()
{
    tPilha *pilha = criaPilha();

    // Preenchendo pilha
    printf("Criando celulas...\n");
    tCelula *c1 = criaCelula(2);
    tCelula *c2 = criaCelula(0);
    tCelula *c3 = criaCelula(10);
    tCelula *c4 = criaCelula(3);
    tCelula *c5 = criaCelula(7);

    printf("Adicionando celulas...\n");
    push(c1, pilha);
    push(c2, pilha);
    push(c3, pilha);
    push(c4, pilha);
    push(c5, pilha);

    // Operações
    printf("Imprimindo pilha...\n");
    imprimePilha(pilha);

    printf("Multiplicacao usando notacao pos-fixa:\n");
    mult(pilha);
    imprimePilha(pilha);

    printf("Adicao usando notacao pos-fixa:\n");
    add(pilha);
    imprimePilha(pilha);

    printf("Divisao usando notacao pos-fixa:\n");
    if (divi(pilha) == 0);
    {
        printf("ERRO: divisao por 0.\n");
    }
    imprimePilha(pilha);

    printf("Subtracao usando notacao pos-fixa:\n");
    sub(pilha);
    imprimePilha(pilha);

    printf("Removendo elemento %g da pilha...\n", getN(pop(pilha)));
    imprimePilha(pilha);

    liberaCelula(c1);
    liberaCelula(c2);
    liberaCelula(c3);
    liberaCelula(c4);
    liberaCelula(c5);

    destroiPilha(pilha);

    return 0;
}
