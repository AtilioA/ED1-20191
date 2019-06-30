#ifndef HASH_H_
#define HASH_H_


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#define M 97
#define N 20
#define TAMALFABETO 256

/* typedef unsigned int  TipoPesos[n]; */

typedef char TipoChave[N];

typedef unsigned TipoPesos[N][TAMALFABETO];

typedef struct TipoItem {
  /* outros componentes */
  TipoChave Chave;
} TipoItem;

typedef unsigned int TipoIndice;

typedef struct TipoCelula* TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  int qtd;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoLista {
  TipoCelula *Primeiro, *Ultimo;
  int tamanho;
  int colisoes;
} TipoLista;

typedef TipoLista TipoDicionario[M];

void FLVazia(TipoLista *Lista);


short Vazia(TipoLista Lista);

void Ins(TipoItem x, TipoLista *Lista);

void Ret(TipoApontador p, TipoLista *Lista, TipoItem *Item);


void GeraPesos(TipoPesos p);

TipoIndice h(TipoChave Chave, TipoPesos p);

void Inicializa(TipoDicionario T);

TipoApontador Pesquisa(TipoChave Ch, TipoPesos p, TipoDicionario T);

void Insere(TipoItem x, TipoPesos p, TipoDicionario T);

void Retira(TipoItem x, TipoPesos p, TipoDicionario T);

void Imp(TipoLista Lista);

void Imprime(TipoDicionario Tabela);


int n_elementos(TipoDicionario tabela);
int n_colisoes(TipoDicionario tabela);
float carga_pesada(TipoDicionario tabela);

#endif
