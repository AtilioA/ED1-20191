#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

/*Inicializa uma matriz de nlinhas e ncolunas
* inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
* output: ponteiro para a matriz inicializada
* pre-condicao: nlinhas e ncolunas diferentes de 0
* pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
*/
tMatriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    if (nlinhas < 1 || ncolunas < 1)
    {
        printf("Linhas/colunas invalidas\n");
        exit(1);
    }

    int i = 0, j = 0;
    tMatriz *matriz = (tMatriz *)malloc(sizeof(tMatriz));

    matriz->nLinhas = nlinhas;
    matriz->nColunas = ncolunas;
    matriz->elementos = (int **)malloc(nlinhas * sizeof(int *));

    for (i = 0; i < nlinhas; i++)
    {
        matriz->elementos[i] = (int *)malloc(ncolunas * sizeof(int));
    }

    for (i = 0; i < nlinhas; i++)
    {
        for (j = 0; j < ncolunas; j++)
        {
            matriz->elementos[i][j] = 0;
        }
    }

    return matriz;
}

void modificaElemento(tMatriz *mat, int linha, int coluna, int elem)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        // exit(1);
    }

    if (linha < 0 || coluna < 0 || linha > mat->nLinhas || coluna > mat->nColunas)
    {
        printf("Linha/coluna invalida\n");
        // exit(1);
    }

    mat->elementos[linha][coluna] = elem;
}

int recuperaElemento(tMatriz *mat, int linha, int coluna)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    if (linha < 0 || coluna < 0)
    {
        printf("Linha/coluna invalida\n");
        exit(1);
    }

    printf("Elemento da linha %i, coluna %i: %i", linha, coluna, mat->elementos[linha][coluna]);

    return mat->elementos[linha][coluna];
}

/* ???
int recuperaNColunas(tMatriz *mat);
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    int i = 0;

    for (i = 0; i < mat->nColunas; i++)
    {
        for (j ; 0; j < nColunas ???; j++)
        printf("Elemento da linha %i, coluna %i: %i", linha, coluna, mat->elementos[i][j]);
    }

    return 0;
}
*/

// int recuperaNLinhas(tMatriz *mat);

tMatriz *transposta(tMatriz *mat)
{
    // Pré-condição
    int i = 0, j = 0, aux = 0;

    for (i = 0; i < mat->nLinhas; i++)
    {
        for (j = mat->nColunas; j > 0; j--)
        {
            aux = mat->elementos[i][j];
            mat->elementos[i][j] = mat->elementos[j][i];
            mat->elementos[j][i] = aux;

        }
    }
}

// tMatriz *multiplicacao(tMatriz *mat1, tMatriz *mat2);

void imprimetMatriz(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    int i = 0, j = 0;

    for (i = 0; i < mat->nLinhas; i++)
    {
        for (j = 0; j < mat->nColunas; j++)
        {
            printf("%i ", mat->elementos[i][j]);
        }
        printf("\n");
    }
}

/*Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada e matriz transposta existe
*/

void destroitMatriz(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    int i = 0;

    for (i = 0; i < mat->nLinhas; i++)
    {
        free(mat->elementos[i]);
    }
    free(mat->elementos);
    free(mat);
}

// void giratMatriz(tMatriz *mat);
