#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Faz a lista ficar vazia */
void FLVazia(tLista *lista)
{
    lista->primeiro = INICIOARRANJO;
    lista->ultimo = lista->primeiro;
}

/*Verifica se a lista est� vazia*/
int estaVazia(tLista *lista)
{
    if (lista->tamanho == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Faz a última posição da lista receber o item de entrada e aumenta o tamanho da lista
void insere(tItem x, tLista *lista)
{
    if (lista->ultimo + 1 > MAXTAM)
    {
        printf("A lista ja esta cheia.\n");
    }
    else
    {
        lista->item[lista->ultimo] = x;
        lista->ultimo++;
    }
}

// Retorna o item da lista por referência e move todos os itens à frente do índice de entrada uma posição para trás.
void retira(posicao p, tLista *lista, tItem *Item)
{
    if (estaVazia(lista) || p >= lista->ultimo)
    {
        printf(" Erro   Posicao nao existe\n");
        return;
    }

    *Item = lista->item[p];
    for (posicao posAux = p; posAux < lista->ultimo; posAux++)
    {
        lista->item[posAux] = lista->item[posAux + 1];
    }
    lista->ultimo--;
}

void imprime(tLista *lista)
{
    if (quantidade(lista) == 0)
    {
        printf("A lista esta vazia.\n");
    }

    posicao posAux;
    for (posAux = lista->primeiro; posAux < lista->ultimo; posAux++)
    {
        printf("%i\n", lista->item[posAux].chave);
    }
}

int quantidade(tLista *lista)
{
    return lista->ultimo - lista->primeiro;
}

tItem recupera(posicao p, tLista *lista)
{
    return lista->item[p];
}

// Recupera cada elemento da lista de origem e insere na lista de destino
void copiaLista(tLista *ListaOrigem, tLista *ListaDestino)
{
    if (!estaVazia(ListaOrigem))
    {
        FLVazia(ListaDestino);

        posicao posAux;

        for (posAux = ListaOrigem->primeiro; posAux < ListaOrigem->ultimo; posAux++)
        {
            insere(recupera(posAux, ListaOrigem), ListaDestino);
        }
    }
}

// Retira item da lista de origem e insere na lista de destino até que a posição passada deixe de ser menor ao fim da lista de origem
void partirLista(posicao p, tLista *listaOrigem, tLista *listaDestino)
{
    if (!estaVazia(listaOrigem))
    {
        tItem itemRetirado;

        FLVazia(listaDestino);

        while (p < listaOrigem->ultimo)
        {
            retira(p, listaOrigem, &itemRetirado);
            insere(itemRetirado, listaDestino);
        }
    }
}
