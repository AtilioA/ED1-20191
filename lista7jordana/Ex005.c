/* 8) Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
duas variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B e, após a execução da função, A conterá o valor de B e B terá o valor de
A. */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int a, b;

    printf("Informe o valor de A: ");
    scanf("%i", &a);

    printf("Informe o valor de B: ");
    scanf("%i", &b);

    swap(&a, &b);

    printf("A: %i\nB: %i\n", a, b);
}
