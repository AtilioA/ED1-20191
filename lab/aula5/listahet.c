#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listahet.h"

#define MOV 0
#define IMOV 1
#define NOTITEM -1

typedef struct cliente
{
    char *nome;
    int id;
} Cliente;

typedef struct movel
{
    int placa;
    int ano;
    float valor;
} Movel;

typedef struct imovel
{
    int identificador;
    int ano;
    float valor;
} Imovel;

typedef struct listahet
{
    Cliente *dono;
    int id;
    void *item;
    struct listahet *prox;
} ListaHet;

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

int placaValida(int placa)
{
    if (placa >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int anoValido(int ano)
{
    if (ano > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int valorValido(float valor)
{
    if (valor > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int clienteValido(Cliente *cliente)
{
    if (idValido(cliente->id) && nomeValido(cliente->nome))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int movelValido(Movel *movel)
{
    if (anoValido(movel->ano) && placaValida(movel->placa) && valorValido(movel->valor))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ImovelValido(Imovel *imovel)
{
    if (anoValido(imovel->ano) && idValido(imovel->identificador) && valorValido(imovel->valor))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ListaHet *cria()
{
    ListaHet *lista = NULL;

    lista = (ListaHet *)malloc(sizeof(ListaHet));
    if (lista == NULL)
    {
        printf("Nao foi possivel alocar a lista.\n");
        return NULL;
    }

    lista->prox = NULL;
    lista->dono = NULL;
    lista->id = NOTITEM;
    lista->item = NULL;

    return lista;
}

Cliente *cria_cliente(char *nome, int id)
{
    if (idValido(id) && nomeValido(nome))
    {
        Cliente *cleiton = (Cliente *)malloc(sizeof(Cliente));

        cleiton->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        strcpy(cleiton->nome, nome);

        cleiton->id = id;

        return cleiton;
    }
    else
    {
        return NULL;
    }
}

Movel *cria_movel(int placa, int ano, float valor)
{
    if (!placaValida(placa) || !anoValido(ano) || !valorValido(valor))
    {
        return NULL;
    }

    Movel *delorean = (Movel *)malloc(sizeof(Movel));

    delorean->placa = placa;
    delorean->ano = ano;
    delorean->valor = valor;

    return delorean;
}

Imovel *cria_imovel(int id, int ano, float valor)
{
    if (!idValido(id) || !anoValido(ano) || !valorValido(valor))
    {
        return NULL;
    }

    Imovel *casaDoRenan = (Imovel *)malloc(sizeof(Movel));

    casaDoRenan->identificador = id;
    casaDoRenan->ano = ano;
    casaDoRenan->valor = valor;

    return casaDoRenan;
}

ListaHet *insere_movel(ListaHet *lista, Cliente *dono, Movel *item)
{
    if (!listaValida(lista))
    {
        return NULL;
    }

    ListaHet *aux = cria();
    aux->dono = cria_cliente(dono->nome, dono->id);
    aux->item = cria_movel(item->placa, item->ano, item->valor);
    aux->id = MOV;

    if (lista->id == NOTITEM) // Se a lista contiver apenas a cabeça
    {
        free(lista);
        lista = aux;

        return lista;
    }
    else
    {
        aux->prox = lista;

        return aux;
    }
}

ListaHet *insere_imovel(ListaHet *lista, Cliente *dono, Imovel *item)
{
    if (!listaValida(lista))
    {
        return NULL;
    }

    ListaHet *aux = cria();
    aux->dono = cria_cliente(dono->nome, dono->id);
    aux->item = cria_imovel(item->identificador, item->ano, item->valor);
    aux->id = IMOV;

    if (lista->id == NOTITEM) // Se a lista contiver apenas a cabeça
    {
        free(lista);
        lista = aux;

        return lista;
    }
    else
    {
        aux->prox = lista;

        return aux;
    }
}

void imprimeCliente(Cliente *renan)
{
    if (clienteValido(renan))
    {
        printf("Cliente:\n");
        printf("Nome do cliente: %s\n", renan->nome);
        printf("Identificador: %i\n\n", renan->id);
    }
}

void imprimeMovel(Movel *movel)
{
    if (movelValido(movel))
    {
        printf("Movel:\n");
        printf("Placa: %i\n", movel->placa);
        printf("Ano: %i\n", movel->ano);
        printf("Valor: %g\n\n", movel->valor);
    }
}

void imprimeImovel(Imovel *imovel)
{
    if (ImovelValido(imovel))
    {
        printf("Imovel:\n");
        printf("Identificador: %i\n", imovel->identificador);
        printf("Ano: %i\n", imovel->ano);
        printf("Valor: %g\n\n", imovel->valor);
    }
}

void imprimeItem(ListaHet *lista)
{
    if (lista != NULL)
    {
        switch (lista->id)
        {
        case MOV:
            imprimeMovel((Movel *)lista->item);

        case IMOV:
            imprimeImovel((Imovel *)lista->item);

        default:
            printf("EAE\n");
        }
    }
}

int listaValida(ListaHet *lista)
{
    if (lista->id == MOV)
    {
        if (clienteValido(lista->dono) && movelValido(lista->item))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else if (lista->id == IMOV)
    {
        if (clienteValido(lista->dono) && ImovelValido(lista->item))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }
}

void imprime(ListaHet *lista)
{
    ListaHet *aux = lista->prox;

    while (aux != NULL)
    {
        if (listaValida(aux))
        {
            imprimeCliente(aux->dono);

            switch (aux->id)
            {
            case MOV:
                imprimeMovel((Movel *)aux->item);
                break;

            case IMOV:
                imprimeImovel((Imovel *)aux->item);

            default:
                // printf("Erro. Nao foi possivel imprimirimprimir o item.\n");
                break;
            }
            aux = aux->prox;
        }
    }
}

float calcula_valor_assegurado(ListaHet *lista, Cliente *dono, float taxa_movel, float taxa_imovel)
{
    if (!listaValida(lista))
    {
        return 0;
    }

    ListaHet *aux = lista;

    float valorTotal = 0;

    while (aux != NULL)
    {
        if (aux->dono->id == dono->id)
        {
            if (aux->id == MOV)
            {
                valorTotal += taxa_movel * ((Imovel *)aux->item)->valor;
            }
            else if (aux->id == IMOV)
            {
                valorTotal += taxa_imovel * ((Imovel *)aux->item)->valor;
            }
            else
            {
                printf("Item invalido\n");
                return 0;
            }
        }

        aux = aux->prox;
    }

    return valorTotal;
}

ListaHet *retira_lixo(ListaHet *lista, int id_cliente)
{
    ListaHet *atual = lista;
    ListaHet *anterior = NULL;
    ListaHet *posterior = lista->prox;

    while (atual != NULL)
    {
        if (atual->prox != NULL)
        {
            posterior = atual->prox;
        }
        if (atual->dono->id == id_cliente)
        {
            if (anterior == NULL)
            {
                lista = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
                freeCelula(atual);
                atual = posterior; // não funciona pois o ponteiro atual é destruido
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
        printf("atual->dono->id/id_cliente: %i %i\n\n", atual->dono->id, id_cliente);
    }

    return lista;
}

ListaHet *retira_cliente(ListaHet *lista, int id_cliente)
{
    if (lista == NULL)
    {
        return NULL;
    }
    if (!idValido(id_cliente))
    {
        return lista;
    }

    ListaHet *atual = lista;
    ListaHet *anterior = NULL;

    while (atual != NULL && atual->dono->id != id_cliente)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return NULL;
    }
    if (anterior == NULL)
    {
        lista = atual->prox;
        return lista;
    }

    else
    {
        anterior->prox = atual->prox;
        freeCelula(atual);
    }

    atual = lista;

    while (atual != NULL && atual->dono->id != id_cliente)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL)
    {
        lista = retira_cliente(lista, id_cliente);
    }

    return lista;
}

void freeDono(Cliente *cleiton)
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

void freeCelula(ListaHet *celula)
{
    if (celula != NULL)
    {
        freeDono(celula->dono);
        free(celula->item);
        free(celula);
    }
}

void destroiLista(ListaHet *lista)
{
    ListaHet *atual = NULL;

    while (lista != NULL)
    {
        atual = lista;
        lista = atual->prox;

        freeCelula(atual);
    }
}
