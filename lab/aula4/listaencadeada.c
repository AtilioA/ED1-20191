#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tLista *)malloc(sizeof(tCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

int estaVazia(tLista lista)
{
    if (lista.primeiro == lista.ultimo)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void insere(tCarta x, tLista *lista)
{
    lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
    lista->ultimo = lista->ultimo->prox; // ?
    lista->ultimo->carta = x;
    lista->ultimo->prox == NULL;
}

void retira(tCelula *p, tLista *lista, tCarta *carta)
{
    tCelula *q;

    if (Vazia(*lista) || p == NULL || p->prox == NULL)
    {
        printf("Erro: lista vazia ou posicao nao existe.\n");
        return;
    }

    q = p->prox;
    *carta = q->carta;
    p->prox = q->prox;

    if (p->prox == NULL)
    {
        lista->ultimo = p;
    }

    free(q); // ?
}

void imprimeLista(tLista lista)
{
    tCelula *aux;
    aux = lista.primeiro->prox;

    // Percorre a lista até chegar em NULL
    for (aux; aux != NULL; aux = aux->prox)
    {
        printf("%i", aux->carta.chave); // ?
    }
}
