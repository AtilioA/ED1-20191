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
    int tamanho; // tamanho armanezado na lista
    tCelula *primeiro, *ultimo;
} tLista;

// Faz a lista ficar vazia
void FLVazia(tLista *lista);

// Verifica se a lista está vazia
int estaVazia(tLista *lista);

// Verifica se existe um produto com um dado código na lista
int codigoExistente(int codigo, tLista *lista);

// Insere um produto na lista
void insere(tProduto x, tLista *lista);

// Retira um produto da lista e retorna o elemento por referência
void retira(int cod, tLista *lista, tProduto *produto);

// Retorna a quantidade de uma lista
int quantidadeLista(tLista *lista);

// Libera uma lista
void destroiLista(tLista *lista);

// Cria um produto e retorna-o
tProduto criaProduto(int cod, char *nome, int qtd, float preco);

// Imprime os produtos da lista
void imprimeLista(tLista *lista);

// Imprime um produto
void imprimeProduto(tProduto produto);

// Busca um produto pelo código
tProduto buscaCodigo(tLista *lista, int codigo);

// Busca o produto mais barato da lista
tProduto maisBarato(tLista *lista);

#endif
