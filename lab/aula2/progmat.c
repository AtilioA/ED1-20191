/*
*********************************
* Programa testador do TAD tMatriz
*********************************
*/
#include <stdio.h>
#include "matriz.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 4

int main()
{
	int i, j;
	tMatriz *mat;

	// chamando a função do TAD tMatriz que inicializa a matriz
	mat = inicializaMatriz(NLINHAS, NCOLUNAS);
	//preenchendo a matriz com valores para teste
	for (i = 0; i < NLINHAS; i++)
		for (j = 0; j < NCOLUNAS; j++)
			//chamando a funcao do TAD matriz para modificar um dado elemento da matriz
			modificaElemento(mat, i, j, i + j);

	//chamando a funcao do TAD matriz para imprimir os elementos da matriz
	imprimetMatriz(mat);

	//chamando a fun��o do TAD para gerar a matriz transposta
	tMatriz *trp = transposta(mat);
	printf("A matriz transposta eh: \n");
	imprimetMatriz(trp);

/*
	//chamando a fun��o do TAD para gerar a matriz multiplicacao
	tMatriz *mlt = multiplicacao(mat, trp);
	printf("A matriz multiplicacao eh: \n");
	imprimetMatriz(mlt);
	printf("A matriz girada 90o eh: \n");
	giratMatriz(mlt);
	imprimetMatriz(mlt);

	destroitMatriz(trp);
	destroitMatriz(mlt);
*/
	destroitMatriz(mat);

}
