#ifndef LISTAENC_H_
#define LISTAENC_H_

typedef struct item
{
    int chave;
} tItem;

typedef struct celula
{
    tItem item;
    struct celula *prox;
} tCelula;

typedef struct listaEncadeada
{
    tCelula *primeiro, *ultimo;
} tLista;

void FLVazia(tLista *lista);
int vazia(tLista *lista);
int listaValida(tLista *lista);
void insere(tItem x, tLista *lista);
void retira(tCelula *p, tLista *lista, tItem *item);
void imprime(tLista lista);
void destroiLista(tLista *lista);

#endif
