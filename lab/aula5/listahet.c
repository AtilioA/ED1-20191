#include <stdio.h>
#include <stdlib.h>
#include "listahet.h"

ListaHet *cria()
{
    ListaHet *lista;

    lista = (ListaHet *)malloc(sizeof(ListaHet));

    lista->prox = NULL;

    return lista;
}

Cliente *cria_cliente(char *nome, int id)
{
    Cliente *cleiton = (Cliente *)malloc(sizeof(Cliente));

    cleiton->id = id;
    cleiton->nome = nome;

    return cleiton;
}

Movel *cria_movel(int placa, int ano, float valor)
{
    Movel *delorean = (Movel *)malloc(sizeof(Movel));

    delorean->placa = placa;
    delorean->ano = ano;
    delorean->valor = valor;

    return delorean;
}

Imovel *cria_imovel(int id, int ano, float valor)
{
    Imovel *casaDoRenan = (Imovel *)malloc(sizeof(Movel));

    casaDoRenan->identificador = id;
    casaDoRenan->ano = ano;
    casaDoRenan->valor = valor;

    return casaDoRenan;
}

ListaHet *insere_movel(ListaHet *lista, Cliente *dono, Movel *item)
{
    ListaHet *aux = (ListaHet *)malloc(sizeof(ListaHet));

    aux->dono = dono;
    aux->item = (Movel *)item;
    aux->id = 0;

    aux->prox = lista->prox;
    lista->prox = aux;

    return lista;
}

ListaHet *insere_imovel(ListaHet *lista, Cliente *dono, Imovel *item)
{
    ListaHet *aux = (ListaHet *)malloc(sizeof(ListaHet));

    aux->dono = dono;
    aux->item = (Imovel *)item;
    aux->id = 1;

    aux->prox = lista->prox;
    lista->prox = aux;

    return lista;
}

void imprimeCliente(Cliente *renan)
{
    printf("Cliente\n");
    printf("Nome do cliente: %s\n", renan->nome);
    printf("Identificador: %i\n\n", renan->id);
}

void imprimeMovel(Movel *movel)
{
    printf("Movel:\n");
    printf("Placa: %i\n", movel->placa);
    printf("Ano: %i\n", movel->ano);
    printf("Valor: %g\n\n", movel->valor);
}

void imprimeImovel(Imovel *imovel)
{
    printf("Imovel:\n");
    printf("Identificador: %i\n", imovel->identificador);
    printf("Ano: %i\n", imovel->ano);
    printf("Valor: %g\n\n", imovel->valor);
}

void imprime(ListaHet *lista)
{
    ListaHet *aux = lista->prox;

    while (aux != NULL)
    {
        imprimeCliente(aux->dono);

        switch (lista->id)
        {
        case 0:
            imprimeMovel((Movel *)aux->item);
            break;

        case 1:
            imprimeImovel((Imovel *)aux->item);

        default:
            printf("Erro. Nao foi possivel imprimir o item.\n");
            break;
        }
        aux = aux->prox;
    }
}

void destroiLista(ListaHet *lista)
{
    ListaHet *aux = lista->prox;
    ListaHet *aux2 = NULL;

    while(aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;

        free(aux2->dono);
        free(aux2->item);
        free(aux2);

        // free(lista->prox);
        // lista->prox = aux;
        // aux = aux->prox;
    }

    free(lista);
}

void destroiLista2(ListaHet *lista)
{
    ListaHet *aux = lista->prox->prox;

    while(aux != NULL)
    {
        free(lista->prox);
        lista->prox = aux;
        aux = aux->prox;
    }

    free(lista);
}
