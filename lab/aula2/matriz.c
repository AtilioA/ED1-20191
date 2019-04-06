#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 2 (verificações de pré-condição) +
 * 1 (alocação do ponteiro da struct) +
 * n (for de 0 até o número de linhas) +
 * 1 * n * m (for de 1 até o número de colunas aninhado em um for de 1 até o número de colunas,
 * com apenas uma operação nos for, isto é, substituição de cada valor [i][j] da matriz por 0)
 * = n(1 + m) + 3. Se n = m, n^2 + n + 3
 * Custo de complexidade: O(n). Se n = m, O(n^2)
 */
tMatriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    // Pré-condição
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

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 5 (verificações de pré-condição) +
 * 1 (substituição de um termo na matriz acessando diretamente a posição da matriz, sem buscas)
 * = 6
 * Custo de complexidade: O(1)
 */
void modificaElemento(tMatriz *mat, int linha, int coluna, int elem)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    if (linha < 0 || coluna < 0 || linha > mat->nLinhas || coluna > mat->nColunas)
    {
        printf("Linha/coluna invalida\n");
        exit(1);
    }

    mat->elementos[linha][coluna] = elem;
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 3 (verificações de pré-condição) +
 * 1 (substituição de um termo na matriz acessando diretamente a posição da matriz, sem buscas)
 * = 4
 * Custo de complexidade: O(1)
 */
int recuperaElemento(tMatriz *mat, int linha, int coluna)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        return 0;
    }

    if (linha < 0 || coluna < 0)
    {
        printf("Linha/coluna invalida\n");
        return 0;
    }

    return mat->elementos[linha][coluna];
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 1 (verificação de pré-condição) +
 * 1 (acesso do conteúdo da struct)
 * = 2
 * Custo de complexidade: O(1)
 */
int recuperaNColunas(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        return 0;
    }

    return mat->nColunas;
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 1 (verificação de pré-condição) +
 * 1 (acesso do conteúdo da struct)
 * = 2
 * Custo de complexidade: O(1)
 */
int recuperaNLinhas(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        return 0;
    }

    return mat->nLinhas;
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 1 (verificação de pré-condição) +
 * n(1 + m) + 3 (custo da função de inicializar matriz) +
 * 1 * n * m (for de 0 até o número de linhas aninhado em um for do número de colunas até 0,
 * com apenas uma operação nos for, isto é, atribuição a cada valor [i][j] da transposta por
 * cada valor [j][i] da matriz original)
 * = 1 + n(1 + m) + 3 + n*m
 * = n(1 + 2m) + 4. Se n = m, 2n^2 + n + 4
 * Custo de complexidade: O(n). Se n = m, O(n^2)
 */
tMatriz *transposta(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    int i = 0, j = 0;
    tMatriz *transposta;

    transposta = inicializaMatriz(mat->nColunas, mat->nLinhas);

    for (i = 0; i < mat->nColunas; i++)
    {
        for (j = 0; j < mat->nLinhas; j++)
        {
            transposta->elementos[i][j] = mat->elementos[j][i];
        }
    }

    return transposta;
}

tMatriz *transpostaFoda(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    int i = 0, j = 0;
    tMatriz *transposta;

    transposta = inicializaMatriz(mat->nColunas, mat->nLinhas);

    for (i = 0; i < mat->nColunas; i++)
    {
        for (j = mat->nLinhas - 1; j >= 0; j--)
        {
            transposta->elementos[i][j] = mat->elementos[j][i];
        }
    }

    return transposta;
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 3 (verificação de pré-condição) +
 * n(1 + m) + 3 (custo da função de inicializar matriz) +
 * 1 * n * n * m
 * = n(1 + m) + n^2 * m + 6. Se n = m, n + n^2 + n^3 + 6.
 * Custo de complexidade: O(n^2). Se n = m, O(n^3)
 */
tMatriz *multiplicacao(tMatriz *mat1, tMatriz *mat2)
{
    // Pré-condição
    if (mat1->elementos == NULL || mat2->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    if (mat1->nColunas != mat2->nLinhas)
    {
        printf("Numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz.\n");
        printf("A multiplicacao nao esta definida.\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;
    tMatriz *matMult;

    matMult = inicializaMatriz(mat1->nLinhas, mat2->nColunas);

    for (i = 0; i < mat1->nLinhas; i++)
    {
        for (j = 0; j < mat2->nColunas; j++)
        {
            for (k = 0; k < mat2->nColunas; k++)
            {
                matMult->elementos[i][j] += mat1->elementos[i][k] * mat2->elementos[k][j];
            }
        }
    }

    return matMult;
}

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 1 (verificação de pré-condição) +
 * 1 * n * m (for de 1 até o número de colunas aninhado em um for de 1 até o número de colunas,
 * com apenas uma operação nos for, isto é, printf de cada valor [i][j] da matriz)
 * = n(1 + m) + 1.Se n = m, n^2 + n + 1
 * Custo de complexidade: O(n). Se n = m, O(n^2)
 */
void imprimeMatriz(tMatriz *mat)
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

/* Complexidade da função: (n = linhas, m = colunas)
 *
 * Função de complexidade: 1 (verificação de pré-condição) +
 * n (for de 1 até o número de linhas, com apenas uma operação no for,
 * isto é, free em cada ponteiro de cada posição do ponteiro em elementos da matriz) +
 * 2 (free no ponteiro em elementos e free no ponteiro da struct tMatriz)
 * = n + 3
 * Custo de complexidade: O(n)
 */
void destroiMatriz(tMatriz *mat)
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

void giraMatriz(tMatriz *mat)
{
    // Pré-condição
    if (mat->elementos == NULL)
    {
        printf("Matriz invalida\n");
        exit(1);
    }

    if (mat->nLinhas < 0 || mat->nColunas < 0 || mat->nColunas != mat->nLinhas)
    {
        printf("Linha/coluna invalida\n");
        exit(1);
    }

    printf("Misteriosa\n");
}
