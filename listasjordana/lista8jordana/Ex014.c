/* 5) Desenvolva um programa que calcule a soma de duas matrizes NxM* de números reais.
A implementação deste programa deve considerar as dimensões fornecida pelo usuário
*/

#include <stdio.h>
#include <stdlib.h>

void leMatriz(int **matriz, int N, int M)
{
    int i = 0, j = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }
}

void printaMatriz(int **matriz, int N, int M)
{
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

int *mallocaLinha(int colunas)
{
    int *linha;

    linha = (int *)malloc(colunas * sizeof(int));

    return linha;
}

int **mallocaMatriz(int N, int M)
{
    int i = 0, **matriz;

    matriz = (int **)malloc(N * sizeof(int *));

    for (i = 0; i < N; i++)
    {
        matriz[i] = mallocaLinha(M);
    }

    return matriz;
}

int **somaMatriz(int **m1, int **m2, int N, int M)
{
    int i = 0, j = 0, k = 0, **mSoma;

    mSoma = mallocaMatriz(N, M);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            mSoma[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return mSoma;
}

int main()
{
    int **m1, **m2, **mSoma, N, M;

    printf("Informe N e M: ");
    scanf("%i%i", &N, &M);

    m1 = mallocaMatriz(N, M);
    m2 = mallocaMatriz(N, M);

    printf("Informe os elementos da primeira matriz:\n");
    leMatriz(m1, N, M);
    printf("Informe os elementos da segunda matriz:\n");
    leMatriz(m2, N, M);

    mSoma = somaMatriz(m1, m2, N, M);

    printf("Primeira matriz:");
    printaMatriz(m1, N, M);
    printf("Segunda matriz:");
    printaMatriz(m2, N, M);
    printf("Terceira matriz (soma):");
    printaMatriz(mSoma, N, M);

    for (int i = 0; i < N; i++)
    {
        free(m1[i]);
        free(m2[i]);
        free(mSoma[i]);
    }
    free(m1);
    free(m2);
    free(mSoma);

    return 0;
}
