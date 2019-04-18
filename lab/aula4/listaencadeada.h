// Guard para evitar dupla inclusão
#ifndef __LISTAENCADEADA_H
#define __LISTAENCADEADA_H

typedef struct tProduto
{
    int codigo;
    char *nome;
    float preco;
    int qtd;
} tProduto;

typedef struct tCelula
{
    tProduto produto;
    struct tCelula *prox;
} tCelula;

typedef struct tLista
{
    tCelula *primeiro, *ultimo;
} tLista;

// Faz a lista ficar vazia
void FLVazia(tLista *lista);

// Verifica se a lista está vazia
int estaVazia(tLista *lista);

// Insere um produto na lista
void insere(tProduto x, tLista *lista);

// Retira um produto da lista e retorna o elemento por referência
void retira(int cod, tLista *lista, tProduto *produto);

int quantidadeLista(tLista *lista);

void destroiLista(tLista *lista);

tProduto criaProduto(int cod, char *nome, int qtd, float preco);


// Imprime os produtos da lista
void imprimeLista(tLista *lista);

void imprimeProduto(tProduto produto);

tProduto buscaCodigo(tLista *lista, int codigo);

tProduto maisBarato(tLista *lista);
tProduto maisBarato2(tLista *lista);

#endif
