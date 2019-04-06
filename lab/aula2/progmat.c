/*
*********************************
* Programa testador do TAD tMatriz
*********************************
*/
#include <stdio.h>
#include "matriz.h"

// Definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 3
#define NCOLUNAS 3

int main()
{
	int i, j;
	tMatriz *mat;

	// Chamando a função do TAD tMatriz que inicializa a matriz
	mat = inicializaMatriz(NLINHAS, NCOLUNAS);

	// Preenchendo a matriz com valores para teste
	for (i = 0; i < NLINHAS; i++)
    {
		for (j = 0; j < NCOLUNAS; j++)
        {
			// Chamando a função do TAD matriz para modificar um dado elemento da matriz
			modificaElemento(mat, i, j, i + j);
        }
    }

	// Chamando a função do TAD matriz para imprimir os elementos da matriz
	imprimeMatriz(mat);

	// Chamando a função do TAD para gerar a matriz transposta
	tMatriz *trp;
    trp = transposta(mat);
	printf("A matriz transposta eh:\n");
	imprimeMatriz(trp);

	// Chamando a função do TAD para gerar a matriz multiplicação
	tMatriz *mlt = multiplicacao(mat, trp);
	printf("A matriz multiplicacao eh: \n");
	imprimeMatriz(mlt);

	printf("A matriz girada 90o eh: \n");
	giraMatriz(mlt);
	imprimeMatriz(mlt);

	destroiMatriz(mlt);
	destroiMatriz(trp);
	destroiMatriz(mat);

    return 0;
}
