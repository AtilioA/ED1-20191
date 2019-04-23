#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

#define MOV 0
#define IMOV 1
#define NOTITEM -1

ListaHet *cria()
{
    ListaHet *lista;

    lista = (ListaHet *)malloc(sizeof(ListaHet));
    if(lista == NULL){
        printf("Nao foi possivel alocar");
        return NULL;
    }

    lista->prox = NULL;
    lista->id = NOTITEM;
    lista->dono = NULL;
    lista->item = NULL;

    return lista;
}

int idValido(int id)
{
    if (id >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int nomeValido(char *nome)
{
    if (nome != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


Cliente *cria_cliente(char *nome, int id)
{
    // if (nomeValido(nome) && idValido(id))
    // {
        Cliente *cleiton = (Cliente *)malloc(sizeof(Cliente));

        cleiton->nome = (char *)malloc(strlen(nome) + 1 * sizeof(char));
        strcpy(cleiton->nome, nome);
        cleiton->id = id;

        return cleiton;
    // }
    // else
    // {
    //     return NULL;
    // }
}

void libera_cliente(Cliente *cleiton)
{
    if (cleiton != NULL)
    {
        if (cleiton->nome != NULL)
        {
            free(cleiton->nome);
        }
        free(cleiton);
    }
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
    if (lista == NULL)
    {
        return NULL;
    }

    ListaHet *novo;

    novo = cria();
    novo->dono = cria_cliente(dono->nome, dono->id);
    novo->item = cria_movel(item->placa, item->ano, item->valor);
    novo->id = MOV;

    if(lista->id == NOTITEM)
    {
        free(lista);
        lista = novo;

        return lista;
    }

    novo->prox = lista;

    return novo;
}

ListaHet *insere_imovel(ListaHet *lista, Cliente *dono, Imovel *item)
{
    if (lista == NULL)
    {
        return NULL;
    }

    ListaHet *novo;

    novo = cria();
    novo->dono = cria_cliente(dono->nome, dono->id);
    novo->item = cria_imovel(item->identificador, item->ano, item->valor);
    novo->id = IMOV;

    if(lista->id == NOTITEM)
    {
        free(lista);
        lista = novo;

        return lista;
    }

    novo->prox = lista;

    return novo;
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
    if(lista != NULL)
    {
        if(lista->id != NOTITEM)
        {
            ListaHet *atual = lista;

            while (atual != NULL)
            {
                imprimeCliente(atual->dono);

                switch (lista->id)
                {
                case MOV:
                    imprimeMovel((Movel *)atual->item);
                    break;

                case IMOV:
                    imprimeImovel((Imovel *)atual->item);

                default:
                    break;
                }
                atual = atual->prox;
            }
        }
    }
}

void removeCelula(ListaHet *celula)
{
    if (celula != NULL)
    {
        libera_cliente(celula->dono);
        free(celula->item);
        free(celula);
    }
}

void destroiLista(ListaHet *lista)
{
    ListaHet *atual = NULL;

    while(lista != NULL)
    {
        atual = lista;
        lista = lista->prox;
        removeCelula(atual);
    }
}

ListaHet* retira_cliente (ListaHet *lista, int id_cliente){
    if(lista == NULL)
        return NULL;
    if(lista->id == NOTITEM)
        return lista;

    ListaHet *selecionada = lista;
    ListaHet *anterior = NULL;

    while(selecionada != NULL && selecionada->dono->id != id_cliente){
        anterior = selecionada;
        selecionada = selecionada->prox;
    }

    if(selecionada == NULL) //não encontrou nada
        return lista;
    if(anterior == NULL)
        lista = selecionada->prox;
    else
        anterior->prox = selecionada->prox;

    removeCelula(selecionada);


    // CAUTION, ~REAL PROGRAMMING~ JANK BELOW:
    selecionada = lista; //percorro pra saber se tem mais algum, se tiver, executo a função denovo
                        //é muito ineficiente, mas é oq eu consigo fazer sem dar erro de leitura
                        //com o tempo de tenho, tô morrendo de sono
                        //então ela virou meio recursiva, meio iterativa. Bosta.
    while(selecionada != NULL && selecionada->dono->id != id_cliente)
        selecionada = selecionada->prox;
    if(selecionada != NULL) //encontrou algo
        lista = retira_cliente(lista, id_cliente);


    return lista;
}
