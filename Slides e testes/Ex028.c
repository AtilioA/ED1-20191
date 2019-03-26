#include <stdio.h>
#include <stdlib.h>

int *mallocaMatrizVetor(int m, int n)
{
    int i = 0, *matrizVetor;

    matrizVetor = (int *)malloc(m * n * sizeof(int));

    return matrizVetor;
}

void leMatrizVetor(int *matrizVetor, int m, int n)
{
    int i = 0, j = 0;

    printf("Informe os valores da matrizVetor:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%i", &matrizVetor[i * n + j]);
        }
    }
}

void printaMatrizVetor(int *matrizVetor, int m, int n)
{
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%i ", matrizVetor[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicaMatrizVetor(int *A, int *B, int *M, int m, int p, int n)
{
    int i = 0, j = 0, k = 0, t = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            t = 0;

            for (k = 0; k < p; k++)
            {
                t += A[i * p + k] * B[k * n + j]; // p = colunas de A; n = colunas de B
            }

            M[i * n + j] = t;
        }
    }
}

int main()
{
    int *A, *B, *M, m, p, n;

    printf("Informe m: ");
    scanf("%i", &m);

    printf("Informe p: ");
    scanf("%i", &p);

    printf("Informe n: ");
    scanf("%i", &n);

    A = mallocaMatrizVetor(m, p);
    B = mallocaMatrizVetor(p, n);
    M = mallocaMatrizVetor(m, n);

    printf("MatrizVetorVetor A:\n");
    leMatrizVetor(A, m, p);
    printf("MatrizVetorVetor B:\n");
    leMatrizVetor(B, p, n);

    multiplicaMatrizVetor(A, B, M, m, p, n);

    printaMatrizVetor(A, m, p);
    printaMatrizVetor(B, p, n);
    printaMatrizVetor(M, m, n);

    free(A);
    free(B);
    free(M);

    return 0;
}
