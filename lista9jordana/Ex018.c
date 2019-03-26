/* 4) Faça um programa para ler uma quantidade N do teclado, assim como N números inteiros e
armazená-los em um vetor A. Ao final, verifique se os itens (inteiros) de A formam uma
progressão aritmética. Imprima a razão se for uma progressão aritmética, ou “NAO” caso
contrário.
Entrada: um número inteiro N representando uma quantidade de números, seguido de N
números inteiros, todos separados por espaço.
Saída: Imprima a razão se for uma progressão aritmética, ou “NAO” caso contrário
*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>


int *leVetor(int N)
{
    int i, *vetor;

    vetor = (int *)malloc(N * sizeof(int));

    printf("Informe os elementos do vetor:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%i", &vetor[i]);
    }

    return vetor;
}

int ehPA(int *vetor, int N)
{
    int i, razao;

    if (N <= 1)
    {
        printf("\nNAO\n");
        return 0;
    }

    razao = vetor[0] - vetor[1]; // não precisa necessariamente do abs()

    for (i = 0; i < N - 1; i++)
    {
        if ((vetor[i] - vetor[i + 1]) != razao)
        {
            printf("\nNAO\n");
            return 0;
        }
    }

    printf("\nRazao: %i\n", -razao);
    return 1;
}

int main()
{
    int N, *A;

    printf("Informe N: ");
    scanf("%i", &N);

    A = leVetor(N);
    ehPA(A, N);

    free(A);

    return 0;
}
