/* Faça um programa que permita ao usuário entrar com uma matriz de 3 x 3 números
inteiros. Em seguida, gere um vetor pela soma dos números de cada coluna da matriz e
mostre esse vetor na tela. */
// Com alocação dinâmica
// Supõe matriz quadrada

#include <stdio.h>
#include <stdlib.h>

int *mallocaLinha(int tamMatriz)
{
    int i, *linha;

    for (i = 0; i < tamMatriz; i++)
    {
        linha = (int *)malloc(tamMatriz * sizeof(int));
    }

    return linha;
}

int **mallocaMatriz(int tamMatriz)
{
    int i = 0, j = 0, **matriz;

    matriz = (int **)malloc(tamMatriz * sizeof(int *));

    for (i = 0; i < tamMatriz; i++)
    {
        matriz[i] = mallocaLinha(tamMatriz);
    }

    return matriz;
}

void leMatriz(int **matriz, int tamMatriz)
{
    int i = 0, j = 0;

    printf("Informe os elementos da matriz:\n");
    for (i = 0; i < tamMatriz; i++)
    {
        for (j = 0; j < tamMatriz; j++)
        {
            printf("a%i%i: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void printaMatriz(int **matriz, int tamMatriz)
{
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < tamMatriz; i++)
    {
        printf("\n");
        for (j = 0; j < tamMatriz; j++)
        {
            printf("%i ", matriz[i][j]);
        }
    }
    printf("\n");
}

// Transforma uma coluna em um número
int *somaLinhas(int **matriz, int tamMatriz)
{
    int i = 0, j = 0, k = 0, *vetor;

    vetor = (int *)malloc(tamMatriz * sizeof(int));

    for (i = 0; i < tamMatriz; i++)
    {
        vetor[k] = 0;
        for (j = 0; j < tamMatriz; j++)
        {
            vetor[k] += matriz[j][i];
        }
        k++;
    }

    return vetor;
}

void printaVetor(int *vetor, int tamVetor)
{
    int i = 0;

    for (i = 0; i < tamVetor; i++)
    {
        printf("%i ", vetor[i]);
    }
}

int main()
{
    int i = 0, tamMatriz = 3, **matriz, *vetorColunasMatriz;

    matriz = mallocaMatriz(tamMatriz);
    leMatriz(matriz, tamMatriz);

    vetorColunasMatriz = somaLinhas(matriz, tamMatriz);

    printaMatriz(matriz, tamMatriz);
    printaVetor(vetorColunasMatriz, tamMatriz);

    free(vetorColunasMatriz);
    for (i = 0; i < tamMatriz; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
