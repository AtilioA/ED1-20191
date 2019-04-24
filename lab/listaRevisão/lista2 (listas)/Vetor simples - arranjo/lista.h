#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          5 // Para testar com listas pequenas


typedef int posicao;

typedef struct {
  int chave;
} tItem;

typedef struct {
  int tamanho;
  tItem item[MAXTAM];
  posicao primeiro, ultimo;
} tLista;

/* Faz a lista ficar vazia */
void FLVazia(tLista *lista);

/*Verifica se a lista est� vazia*/
int estaVazia(tLista *lista);

/* Insere x ap�s o �ltimo elemento da lista */
void insere(tItem x, tLista *lista);

/*Op��o que n�o modifica o lista.h */
void retira(posicao p, tLista *lista, tItem *Item);

/*Imprime a lista */
void imprime(tLista *lista);

/*Quantidade de elementos na lista*/
int quantidade(tLista *lista);

/*Copia uma lista */
void copiaLista(tLista *ListaOrigem, tLista *ListaDestino);

// /*Copia uma lista */
void partirLista(int p, tLista *ListaOrigem, tLista *ListaDestino);

tItem recupera(posicao p, tLista *lista);

#endif
