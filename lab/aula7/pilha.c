#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "notacaopolonesa.h"

tPilha *criaPilha()
{
    tPilha *pilha;

    pilha = (tPilha *)malloc(sizeof(tPilha));
    pilha->topo = NULL;
    pilha->qtd = 0;

    return pilha;
}

tCelula *criaCelula(float n)
{
    tCelula *celula = (tCelula *)malloc(sizeof(tCelula));

    if (celula != NULL)
    {
        celula->n = n;
        celula->prox = NULL;
    }

    return celula;
}

float getN(tCelula *celula)
{
    return celula->n;
}

void imprimeCelula(tCelula *celula)
{
    if (celula != NULL)
    {
        printf("%g\n", celula->n);
    }
}

void imprimePilha(tPilha *pilha)
{
    if (pilha != NULL)
    {
        tCelula *atual = pilha->topo;
        while (atual != NULL)
        {
            imprimeCelula(atual);
            atual = atual->prox;
        }
    }
}

tCelula *pop(tPilha *pilha)
{
    if (pilha != NULL && pilha->topo != NULL)
    {
        tCelula *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        pilha->qtd--;

        return aux;
    }

    return NULL;
}

int push(tCelula *celula, tPilha *pilha)
{
    if (pilha != NULL && celula != NULL)
    {
        celula->prox = pilha->topo;
        pilha->topo = celula;
        pilha->qtd++;
        return 1;
    }

    return 0;
}

int liberaCelula(tCelula *celula)
{
    if (celula != NULL)
    {
        celula->n = -1;
        free(celula);
        return 1;
    }

    return 0;
}

int destroiPilha(tPilha *pilha)
{
    if (pilha != NULL && pilha->topo != NULL)
    {
        tCelula *atual = pilha->topo;
        tCelula *anterior = NULL;

        while (anterior != NULL)
        {
            anterior = atual;
            atual = atual->prox;
            liberaCelula(anterior);
        }
        pilha->qtd = -1;
        free(pilha);
        return 1;
    }

    return 0;
}
