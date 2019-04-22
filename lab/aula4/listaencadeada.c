#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void FLVazia(tLista *lista)
{
    lista->primeiro = (tCelula *)malloc(sizeof(tCelula)); // lista->primeiro será a cabeça da lista
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    lista->tamanho = 0;
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
    }
    else
    {
        lista->ultimo->prox = (tCelula *)malloc(sizeof(tCelula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->produto = x;
        lista->ultimo->prox = NULL;
        lista->tamanho++;
    }
}

void retira(int cod, tLista *lista, tProduto *produto)
{
    tCelula *anterior = NULL;
    tCelula *atual = lista->primeiro; // lista->primeiro->prox

    while (atual != NULL && cod != atual->produto.codigo)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("Nao existe produto com este codigo!\n");
    }

    else if (atual->produto.qtd == 0)
    {
        anterior->prox = atual->prox;
        *produto = atual->produto;
        free(atual);
        lista->tamanho--;
    }
    else
    {
        printf("Produto em estoque nao pode ser removido!\n");
    }
}

int quantidadeLista(tLista *lista)
{
    return lista->tamanho;
}

void imprimeLista(tLista *lista)
{
    tCelula *aux = NULL;

    printf("Quantidade de itens: %i\n", quantidadeLista(lista));
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
    // Produtos inválidos recebem código -1 e não são exibidos
    if (produto.codigo != -1)
    {
        printf("Codigo: %i\n", produto.codigo);
        printf("Nome: %s\n", produto.nome);
        printf("Quantidade: %i\n", produto.qtd);
        printf("Preco: %.2f\n", produto.preco);
    }
}

void destroiLista(tLista *lista)
{
    tCelula *atual = lista->primeiro;
    tCelula *anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }

    lista->tamanho = 0;
}

tProduto buscaCodigo(tLista *lista, int codigo)
{
    tCelula *atual = lista->primeiro->prox;

    for (atual = lista->primeiro->prox; atual != NULL; atual = atual->prox)
    {
        if (codigo == atual->produto.codigo)
        {
            return atual->produto;
        }
    }

    tProduto produtoInvalido;
    produtoInvalido.codigo = -1;

    printf("Nao ha produto com este codigo.\n");

    return produtoInvalido;
}

tProduto maisBarato(tLista *lista)
{
    if (estaVazia(lista) || lista->tamanho == 0)
    {
        printf("Nao existe, pois a lista esta vazia.");

        tProduto produtoInvalido;
        produtoInvalido.codigo = -1;
        return produtoInvalido;
    }

    else
    {
        tProduto produtoMaisBarato = lista->primeiro->prox->produto;

        tCelula *aux = lista->primeiro->prox;

        while (aux != NULL)
        {
            if ((aux->produto.preco) < (produtoMaisBarato.preco))
            {
                produtoMaisBarato = aux->produto;
            }

            aux = aux->prox;
        }

        return produtoMaisBarato;
    }
}
