/* 3) Dizemos que uma matriz quadrada inteira é um quadrado mágico se a soma dos
elementos de cada linha, a soma dos elementos de cada coluna e a soma dos elementos
das diagonais principal e secundária são todas iguais. Leia uma matriz 10x10 do usuário
e imprima se ela é um quadrado mágico ou não.
*/
// Com alocação dinâmica
// Supõe matriz quadrada

#include <stdio.h>
#include <stdlib.h>


int somaColunaMatriz(int **matriz, int colunaAlvo, int tam)
{
    int i = 0, soma = 0;

    for (i = 0; i < tam; i++)
    {
        soma += matriz[i][colunaAlvo];
    }

    return soma;
}

int somaLinhaMatriz(int **matriz, int linhaAlvo, int tam)
{
    int i = 0, soma = 0;

    for (i = 0; i < tam; i++)
    {
        soma += matriz[linhaAlvo][i];
    }

    return soma;
}

int somaDiagonalPrincipal(int **matriz, int tam)
{
    int i = 0, soma = 0;

    for (i = 0; i < tam; i++)
    {
        soma += matriz[i][i];
    }

    return soma;
}

int somaDiagonalSecundaria(int **matriz, int tam)
{
    int i = 0, j = 0, soma = 0;

    for (i = 0, j = tam - 1; i < tam, j >= 0; i++, j--)
    {
        soma += matriz[j][i];
    }

    return soma;
}

void printaMatriz(int **matriz, int tam)
{
    int i = 0, j = 0;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("\n");
        for (j = 0; j < tam; j++)
        {
            printf("%i ", matriz[i][j]);
        }
    }
    printf("\n");
}

void leMatriz(int **matriz, int tam)
{
    int i = 0, j = 0;

    printf("\nInforme os elementos da matriz:\n");
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            printf("a%i%i", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

int *mallocaLinha(int tam)
{
    int *linha = (int *)malloc(tam * sizeof(int));

    return linha;
}

int **mallocaMatriz(int tam)
{
    int i = 0;

    int **matriz = (int **)malloc(tam * sizeof(int *));

    for (i = 0; i < tam; i++)
    {
        matriz[i] = mallocaLinha(tam);
    }

    return matriz;
}

int ehQuadradoMagico(int **matriz, int tam)
{
    int *somas, somasPossiveis = (tam * 2) + 2, i = 0, j = 0, k = 0;

    somas = (int *)malloc(somasPossiveis * sizeof(int));

    // Determina todas as somas (colunas, linhas e diagonais)
    for (i = 0; i < tam; i++)
    {
        somas[k] = somaColunaMatriz(matriz, i, tam);
        somas[k + 1] = somaLinhaMatriz(matriz, i, tam);
        k += 2;
    }
    somas[k] = somaDiagonalPrincipal(matriz, tam);
    k++;
    somas[k] = somaDiagonalSecundaria(matriz, tam);

    // Se todas as somas forem iguais, retorna 1 ao final
    for (i = 0; i < somasPossiveis; i++)
    {
        if (somas[0] != somas[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int i = 0, j = 0, tam = 0, **matriz;

    printf("Informe o tamanho da matriz quadrada: ");
    scanf("%i", &tam);

    matriz = mallocaMatriz(tam);
    leMatriz(matriz, tam);

    printf("\nMatriz:");
    printaMatriz(matriz, tam);

    if (ehQuadradoMagico(matriz, tam) == 1)
    {
        printf("\nEssa matriz eh um quadrado magico.\n");
    }
    else
    {
        printf("\nEssa matriz NAO eh um quadrado magico.\n");
    }

    for (i = 0; i < tam; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
