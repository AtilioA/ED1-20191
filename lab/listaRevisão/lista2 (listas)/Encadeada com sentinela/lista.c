#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tCelula *)malloc(sizeof(tCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int vazia(tLista *lista)
{
    if (lista->primeiro == lista->ultimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int listaValida(tLista *lista)
{
    if (lista->primeiro != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere(tItem x, tLista *lista)
{
    if (listaValida(lista))
    {
        lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->item = x;
        lista->ultimo->prox = NULL;
    }
}

void retira(tCelula *p, tLista *lista, tItem *item)
{
    if (listaValida(lista) && p != NULL)
    {
        tCelula *q;

        q = p->prox;
        *item = q->item;
        p->prox = q->prox;

        if (p->prox == NULL)
        {
            lista->ultimo = p;
        }

        free(q);
    }
}

void imprime(tLista lista)
{
    tCelula *atual = lista.primeiro->prox;

    while (atual != NULL)
    {
        printf("%i\n", atual->item.chave);
        atual = atual->prox;
    }
}

void destroiLista(tLista *lista)
{
    tCelula *atual = lista->primeiro;

    while (atual != NULL)
    {
        lista->primeiro = atual;
        atual = lista->primeiro->prox;

        free(lista->primeiro);
    }
}
