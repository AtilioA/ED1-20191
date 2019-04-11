#ifndef __LOJA_H
#define __LOJA_H

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


// Verifica se a lista e se a posição são válidos
int listaEPosicaoValidos(TipoLista *lista, Posicao p);

// Verifica se um código já ocorreu na lista
int codigoRepetido(TipoLista *lista, produto x);

// Verifica se um código já ocorreu na lista, retornando o índice da primeira ocorrência
int codigoRepetidoIndice(TipoLista *lista, produto x);

// Esvazia uma lista
void listaVazia(TipoLista *lista);

// Verifica se a lista está vazia
int estaVazia(TipoLista lista);

// Insere um produto na lista
void Insere(produto x, TipoLista *lista);

// Retira um produto recebendo o código como entrada
int Retira(int codigo, TipoLista *lista, produto *ItemRecuperado);

// Retira um produto recebendo o produto como entrada
int Retira2(produto x, TipoLista *lista, produto *itemRetirado);

// Cria um produto
produto CriarProduto();

// Recupera um produto
produto Recupera(Posicao p, TipoLista *lista);

// Imprime todos os produtos de uma lista
void ImprimeLista(TipoLista Lista);

// Imprime os códigos de todos os produtos de uma lista
void ImprimeCodigos(TipoLista Lista);

// Imprime um produto
void ImprimeProduto(produto produto);

// Cria um produto
produto CriarProduto();

// Retorna quantidade de itens na lista
int Quantidade(TipoLista Lista);

int buscaIndiceCodigo(TipoLista *lista, int codigo);

// Verifica se um código já ocorreu na lista, retornando o índice (similar a codigoRepetidoIndice)
produto buscaProdutoCodigo(TipoLista *lista, int codigo);

// Retorna o índice do produto de menor preço
int indiceMaisBarato(TipoLista *lista);

// Retorna o produto de menor preço
produto maisBarato(TipoLista *lista);

#endif
