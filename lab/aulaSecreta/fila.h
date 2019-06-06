#ifndef FILA_H_
#define FILA_H_

#include "pilha.h"

/*Tipo que define a fila (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementa��o do TAD. Usar como base o TAD Pilha (pilha.h) - n�o usar outra estrutura de dados
  */
typedef struct fila
{
    tPilha *principal;
    tPilha *aux;
} tFila;

/*Cria uma fila vazia, usando pilha
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
tFila *criaFila(void);

/*Insere uma pessoa na fila de Pessoas (lembre-se, fila e' FIFO). Imprime mensagem de erro caso a fila esteja cheia.
* inputs: pessoa a ser inserida na fila (do tipo pessoa) e a fila
* output: nenhum
* pre-condicao: pessoa e fila n�o s�o nulos
* pos-condicao: fila cont�m a pessoa inserida na ultima posi��o*/
void insere(tCelula *celula, tFila *fila);

/*Retira uma pessoa da fila (usando FIFO). Imprime mensagem de erro caso a fila esteja vazia.
* inputs: a fila
* output: a Pessoa (do tipo Pessoa) retirada da tFila (ou NULL, caso a fila esteja vazia)
* pre-condicao: fila n�o � nula
* pos-condicao: fila n�o cont�m a pessoa que estava na primeira posicao */
tCelula *retira(tFila *f);

/*Imprime os dados de todos as pessoas da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de pessoas
* output: nenhum
* pre-condicao: fila n�o � nula
* pos-condicao: dados dos pessoas impressos na saida padrao
*/
void imprimeFila(tFila *f);

/*Verifica se a fila esta ou nao vazia
* inputs: a fila de pessoas
* output: 1 se estiver vazia e zero caso contrario
* pre-condicao: fila n�o � nula
* pos-condicao: nenhuma
*/
int vaziaFila(tFila *f);

/*Separa a fila f de tal forma que as pessoas com idade maior que 60 sejam movidas para a fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores".
* inputs: a fila de pessoas, as filas f_maiores e f_menores (inicialmente vazias)
* output: nao tem
* pre-condicao: fila f n�o � nula
* pos-condicao: fila f vazia, pessoas com idade maior ou igual a 60 na fila "f_maiores" e as pessoas com idade menor que 60 para a fila "f_menores" */
void separaFilas(tFila *f, tFila *f_maiores, tFila *f_menores);

/*Libera toda a mem�ria utilizada pelas estruturas de dados.
* inputs: a fila de pessoas
* output: NULL
* pre-condicao: fila f n�o � nula
* pos-condicao: Mem�ria liberada */
tFila *destroiFila(tFila *f);

tCelula *inicializaCelula(tPessoa *pessoa);

#endif /* FILA_H_ */
