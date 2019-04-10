#ifndef LOJA_H_
#define LOJA_H_

#include <stdio.h>
#include <stdlib.h>

#define INICIO 1
#define MAXTAM 1000

typedef int Posicao;

typedef struct Produto
{
    int codigo;
    char nome[30];
    float preco;
    int qtd;
} produto;

typedef struct {
  produto itens[MAXTAM];
  Posicao primeiro, ultimo;
} TipoLista;

int listaEPosicaoValidos(TipoLista *lista, Posicao p);
int codigoRepetido(TipoLista *lista, produto x);
int codigoRepetidoIndice(TipoLista *lista, produto x);
void listaVazia(TipoLista *lista);
int estaVazia(TipoLista lista);
void Insere(produto x, TipoLista *lista);
void Retira(produto x, TipoLista *lista, produto *ItemRecuperado);
produto Recupera(Posicao p, TipoLista *lista);
void ImprimeProduto(produto *produto);
produto CriarProduto();
void Imprime(TipoLista Lista);
int Quantidade(TipoLista Lista);
void copiaLista(TipoLista *ListaOrigem, TipoLista *ListaDestino);
produto maisBarato(TipoLista *lista);

#endif
