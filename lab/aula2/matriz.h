#ifndef MATRIZ_H_
#define MATRIZ_H_

// Tipo matriz (tipo opaco)
// Estrutura interna do tipo deve ser definida na implementação do TAD
struct matriz
{
    int nLinhas;
    int nColunas;
    int **elementos;
};
typedef struct matriz tMatriz;

/* Inicializa uma matriz de nlinhas e ncolunas
* inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
* output: ponteiro para a matriz inicializada
* pre-condicao: nlinhas e ncolunas diferentes de 0
* pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
*/
tMatriz *inicializaMatriz(int nlinhas, int ncolunas);

/* Modifica o elemento [linha][coluna] da matriz mat
* inputs: a matriz, a linha, a coluna, e o novo elemento
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
* pos-condicao: elemento [linha][coluna] da matriz modificado
*/
void modificaElemento(tMatriz *mat, int linha, int coluna, int elem);

/* Retorna o elemento mat[linha][coluna]
* inputs: a matriz, a linha e a coluna
* output: elemento mat[linha][coluna]
* pre-condicao: matriz mat existe, linha e coluna s�o v�lidos na matriz
* pos-condicao: mat n�o � modificada
*/
int recuperaElemento(tMatriz *mat, int linha, int coluna);

/* Retorna o n�mero de colunas da matriz mat
* inputs: a matriz
* output: o n�mero de colunas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNColunas(tMatriz *mat);

/* Retorna o número de linhas da matriz mat
* inputs: a matriz
* output: o número de linhas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada
*/
int recuperaNLinhas(tMatriz *mat);

/* Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat n�o � modificada e matriz transposta existe
*/
tMatriz *transposta(tMatriz *mat);

/* Retorna a matriz multiplicacao entre mat1 e mat2
* inputs: as matrizes mat1 e mat2
* output: a matriz multiplica��o
* pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
* correponde ao numero de linhas de mat2
* pos-condicao: mat1 e mat2 n�o s�o modificadas e a matriz multiplicacao existe
*/
tMatriz *multiplicacao(tMatriz *mat1, tMatriz *mat2);

/* Imprime a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe
* pos-condicao: nenhuma
*/
void imprimeMatriz(tMatriz *mat);

/*Libera memória alocada para a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe
* pos-condicao: toda a mem�ria alocada para matriz foi liberada
*/
void destroiMatriz(tMatriz *mat);

/* BONUS
 *
 * Rotaciona os valores da matriz NxN em 90º (como se fosse uma imagem)
 * A rotação deve ocorrer localmente, isto é, sem uso de matrizes auxiliares
* inputs: a matriz
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna são válidos e iguais
* pos-condicao: mat é rotacionada 90º
*/
void giraMatriz(tMatriz *mat);

#endif /*MATRIZ_H_*/
