/* 3) Faça um programa que leia dois números N e M e:
a) Crie dinamicamente e preencha uma matriz de inteiros N x M;
b) Localize os três maiores números da matriz e mostre a linha e a coluna onde estão.
c) Crie dinamicamente e construa a matriz transposta M x N de inteiros.
*/
// Assume matriz sem elementos repetidos

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

void printaVetor(int *vetor, int tam)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int *mallocaLinha(int nColunas)
{
    int *linha;

    linha = (int *)malloc(nColunas * sizeof(int));

    return linha;
}

int **mallocaMatriz(int linhas, int colunas)
{
    int i = 0, **matriz;

    matriz = (int **)malloc(linhas * sizeof(int *));

    for (i = 0; i < linhas; i++)
    {
        matriz[i] = mallocaLinha(colunas);
    }

    return matriz;
}

int **transpoeMatriz(int **matriz, int N, int M)
{
    int i = 0, j = 0, k = 0, **transposta;

    transposta = mallocaMatriz(M, N);

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    return transposta;
}

int *matrizParaVetor(int **matriz, int N, int M)
{
    int i = 0, j = 0, k = 0, *vetorMatriz;

    vetorMatriz = (int *)malloc(N * M * sizeof(int));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            vetorMatriz[k] = matriz[i][j];
            k++;
        }
    }

    return vetorMatriz;
}

int *boaSorteInvertido(int *vetorOriginal, int tam)
{
    int i = 0, j = 0, aux = 0, *vetorOrdenado;

    vetorOrdenado = (int *)malloc(tam * sizeof(int));
    vetorOrdenado = vetorOriginal;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam - 1; j++)
        {
            if (vetorOrdenado[j] < vetorOrdenado[j + 1])
            {
                aux = vetorOrdenado[j];
                vetorOrdenado[j] = vetorOrdenado[j + 1];
                vetorOrdenado[j + 1] = aux;
            }
        }
    }

    return vetorOrdenado;
}

int *nMaioresMatriz(int **matriz, int N, int M, int nMaiores)
{
    int i = 0, *vetorMatriz, tamVetor = N * M, *vetorMatrizOrdenado, *maiores;

    maiores = (int *)malloc(nMaiores * sizeof(int));

    vetorMatriz = matrizParaVetor(matriz, N, M);
    vetorMatrizOrdenado = boaSorteInvertido(vetorMatriz, tamVetor);

    for (i = 0; i < nMaiores; i++)
    {
        maiores[i] = vetorMatrizOrdenado[i];
    }

    return maiores;
}

int **buscaNMaiores(int **matriz, int *maiores, int nMaiores, int N, int M)
{
    int i = 0, j = 0, k = 0, l = 0, **maioresEPosicoes, colMP = 3, linMP = nMaiores;

    maioresEPosicoes = mallocaMatriz(linMP, colMP);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            for (k = 0; k < nMaiores; k++)
            {
                if (maiores[k] == matriz[i][j])
                {
                    maioresEPosicoes[k][0] = maiores[k];
                    maioresEPosicoes[k][1] = i;
                    maioresEPosicoes[k][2] = j;
                    k++;
                }
            }
        }
    }

    return maioresEPosicoes;
}

int main()
{
    int i = 0, N, M, **matriz, **transposta, nMaiores, *maiores, **maioresEPosicoes;

    printf("Informe N e M:\n");
    scanf("%i%i", &N, &M);

    matriz = mallocaMatriz(N, M);

    printf("Informe os elementos da matriz:\n");
    leMatriz(matriz, N, M);
    printf("Matriz original:");
    printaMatriz(matriz, N, M);

    transposta = transpoeMatriz(matriz, N, M);
    printf("Matriz transposta:");
    printaMatriz(transposta, M, N);

    printf("\nQuantos elementos maiores deseja buscar?\n");
    scanf("%i", &nMaiores);
    if (nMaiores > (N * M))
    {
        printf("poxa amigao\n");
    }

    maiores = nMaioresMatriz(matriz, N, M, nMaiores);
    printaVetor(maiores, nMaiores);
    maioresEPosicoes = buscaNMaiores(matriz, maiores, nMaiores, N, M);

    printf("Matriz de maiores elementos e suas posicoes em indice (elemento | i | j )");
    printaMatriz(maioresEPosicoes, nMaiores, 3);

    for (i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
