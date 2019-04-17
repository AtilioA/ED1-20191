#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tLista *)malloc(sizeof(tCelula));
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
}

int estaVazia(tLista *lista)
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

void insere(tProduto x, tLista *lista)
{
    lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->produto = x;
    lista->ultimo->prox == NULL;
}

void retira(int cod, tLista *lista, tProduto *produto)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro->prox;

    while(atual != NULL && cod != atual->produto.codigo)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao existe produto com este codigo!\n");
        return;
    }

    anterior->prox = atual->prox;
    *produto = atual->produto;
    free(atual);
}

int quantidadeLista(tLista *lista)
{
    int quantidade = 0;

    tCelula *aux = NULL;
    aux = lista->primeiro;

    for (aux; aux != NULL; aux = aux->prox)
    {
        quantidade++;
    }

    return quantidade;
}

void imprimeLista(tLista *lista)
{
    tCelula *aux = NULL;
    aux = lista->primeiro->prox;

    // Percorre a lista até chegar em NULL
    for (aux; aux != NULL; aux = aux->prox)
    {
        imprimeProduto(aux->produto);
    }
}

tProduto criaProduto(int cod, char *nome, int qtd, float preco)
{
    tProduto milGrau;

    milGrau.codigo = cod;
    milGrau.nome = nome;
    milGrau.qtd = qtd;
    milGrau.preco = preco;

    return milGrau;
}

void imprimeProduto(tProduto produto)
{
    printf("Codigo: %i\n", produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade: %i\n", produto.qtd);
    printf("Preco: %g\n", produto.preco);
}

void destroiLista(tLista *lista)
{
    tCelula *aux = lista->primeiro;
    tCelula *aux2 = NULL;

    while(aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

tProduto maisBarato(tLista *lista)
{
    tProduto socorro = lista->primeiro->produto;

    tCelula *aux = lista->primeiro->prox;

    while(aux != NULL)
    {
        if ((aux->produto.preco) < (socorro.preco))
        {
            socorro = aux->produto;
        }

        aux = aux->prox;
    }

    // free(aux);
    return socorro;
}
