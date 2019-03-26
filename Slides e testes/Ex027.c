#include <stdio.h>
#include <stdlib.h>

int **mallocaMatriz(int m, int n)
{
    int i = 0, **matriz;

    matriz = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    return matriz;
}

void leMatriz(int **matriz, int m, int n)
{
    int i = 0, j = 0;

    printf("Informe os valores da matriz:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }
}

void printaMatriz(int **matriz, int m, int n)
{
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicaMatriz(int **A, int **B, int **M, int m, int p, int n)
{
    int i = 0, j = 0, k = 0, t = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            t = 0;

            for (k = 0; k < p; k++)
            {
                t += A[i][k] * B[k][j];
            }

            M[i][j] = t;
        }
    }
}

int main()
{
    int **A, **B, **M, m, p, n;

    printf("Informe m: ");
    scanf("%i", &m);

    printf("Informe p: ");
    scanf("%i", &p);

    printf("Informe n: ");
    scanf("%i", &n);

    A = mallocaMatriz(m, p);
    B = mallocaMatriz(p, n);
    M = mallocaMatriz(m, n);

    printf("Matriz A:\n");
    leMatriz(A, m, p);
    printf("Matriz B:\n");
    leMatriz(B, p, n);

    multiplicaMatriz(A, B, M, m, p, n);

    printaMatriz(A, m, p);
    printaMatriz(B, p, n);
    printaMatriz(M, m, n);

    for (int i = 0; i < m; i++)
    {
        free(A);
        free(M);
    }

    for (int i = 0; i < p; i++)
    {
        free(B);
    }

    free(A);
    free(B);
    free(M);

    return 0;
}
