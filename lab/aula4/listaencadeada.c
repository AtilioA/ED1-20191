#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tCelula *)malloc(sizeof(tCelula)); // lista->primeiro será a cabeça da lista
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

int codigoExistente(int codigo, tLista *lista)
{
    tCelula *aux;

    for (aux = lista->primeiro->prox; aux != NULL; aux = aux->prox)
    {
        if (codigo == aux->produto.codigo)
        {
            return 1;
        }
    }
    return 0;
}

void insere(tProduto x, tLista *lista)
{
    if (codigoExistente(x.codigo, lista))
    {
        printf("\nErro ao inserir o seguinte produto:\n");
        imprimeProduto(x);
        printf("Codigo ja existente\n\n");
        return;
    }

    else
    {
        lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->produto = x;
        lista->ultimo->prox = NULL;
    }
}

void retira(int cod, tLista *lista, tProduto *produto)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro;

    while (atual != NULL && cod != atual->produto.codigo)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao existe produto com este codigo!\n");
        return;
    }

    if (atual->produto.qtd == 0)
    {
        anterior->prox = atual->prox;
        *produto = atual->produto;
        free(atual);
    }
    else
    {
        printf("Produto em estoque nao pode ser removido!\n");
    }
}

int quantidadeLista(tLista *lista)
{
    int quantidade = 0;

    tCelula *aux = NULL;

    for (aux = lista->primeiro->prox; aux != NULL; aux = aux->prox)
    {
        quantidade++;
    }

    return quantidade;
}

void imprimeLista(tLista *lista)
{
    tCelula *aux = NULL;

    // Percorre a lista até chegar em NULL
    for (aux = lista->primeiro->prox; aux != NULL; aux = aux->prox)
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
    tCelula *aux = lista->primeiro->prox;
    tCelula *aux2 = NULL;

    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

tProduto buscaCodigo(tLista *lista, int codigo)
{
    tCelula *aux = lista->primeiro->prox;

    for (aux = lista->primeiro->prox; aux != NULL; aux = aux->prox)
    {
        if (codigo == aux->produto.codigo)
        {
            return aux->produto;
        }
    }

    printf("Nao ha produto com este codigo.\n");
    return;
}

tProduto maisBarato(tLista *lista)
{
    tProduto produtomaisBarato = lista->primeiro->prox->produto;

    tCelula *aux = lista->primeiro->prox;

    while (aux != NULL)
    {
        if ((aux->produto.preco) < (produtomaisBarato.preco))
        {
            produtomaisBarato = aux->produto;
        }

        aux = aux->prox;
    }

    // free(aux);
    return produtomaisBarato;
}
