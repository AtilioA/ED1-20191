/*
6 - Implemente uma função que, dada uma matriz de inteiros dinâmica, implementada com vetor
simples, retorne uma matriz dinâmica representada por vetor de ponteiros, contendo os mesmos
elementos da matriz original: int** matriz (int m, int n, int* mat);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int linhas;
    int colunas;
    int **elementos;
} tMatriz;

// Trocar funções

int *matrizParaVetor(tMatriz matriz, int *tamanhoVetor)
{
    int i = 0, j = 0;
    int *vetorMatriz;

    *tamanhoVetor = matriz.linhas * matriz.colunas;

    vetorMatriz = (int *)malloc(*tamanhoVetor * sizeof(int));

    for (i = 0; i < matriz.linhas; i++)
    {
        for (j = 0; j < matriz.colunas; j++)
        {
            vetorMatriz[i * matriz.colunas + j] = matriz.elementos[i][j];
        }
    }

    return vetorMatriz;
}

void printaVetor(int *vetor, int tamVet)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tamVet; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

void printatMatriz(tMatriz matriz)
{
    int i = 0, j = 0;

    for (i = 0; i < matriz.linhas; i++)
    {
        for (j = 0; j < matriz.colunas; j++)
        {
            printf("%2i ", matriz.elementos[i][j]);
        }
        printf("\n");
    }
}

tMatriz criatMatriz(int m, int n)
{
    int i = 0;
    tMatriz matriz;

    matriz.linhas = m;
    matriz.colunas = n;

    matriz.elementos = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < matriz.linhas; i++)
    {
        matriz.elementos[i] = (int *)malloc(n * sizeof(int));
    }

    return matriz;
}

void faztMatrizVazia(tMatriz *matriz)
{
    int i = 0, j = 0;

    for (i = 0; i < matriz->linhas; i++)
    {
        for (j = 0; j < matriz->colunas; j++)
        {
            matriz->elementos[i][j] = 0;
        }
    }
}

void preenchetMatriz(tMatriz *matriz)
{
    int i = 0, j = 0;

    printf("Informe os elementos da matriz:\n");
    for (i = 0; i < matriz->linhas; i++)
    {
        for (j = 0; j < matriz->colunas; j++)
        {
            printf("a%i%i: ", i + 1, j + 1);
            scanf("%i", &matriz->elementos[i][j]);
        }
        printf("\n");
    }
}

void freetMatriz(tMatriz *matriz)
{
    int i = 0;

    for (i = 0; i < matriz->linhas; i++)
    {
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
}

int main()
{
    int m = 0, n = 0;
    tMatriz matriz;
    int *vetorMatriz, tamVet = 0;

    printf("Informe o tamanho da matriz [MxN]: ");
    scanf("%i %i", &m, &n);

    matriz = criatMatriz(m, n);

    printf("Inicializando matriz:\n");
    faztMatrizVazia(&matriz);
    printatMatriz(matriz);

    preenchetMatriz(&matriz);
    printatMatriz(matriz);

    vetorMatriz = matrizParaVetor(matriz, &tamVet);
    printf("\nVetor matriz:");
    printaVetor(vetorMatriz, tamVet);

    free(vetorMatriz);
    freetMatriz(&matriz);
}
