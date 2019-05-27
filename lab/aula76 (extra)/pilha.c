#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "notacaopolonesa.h"

tPilha *criaPilha()
{
    tPilha *pilha;

    pilha = (tPilha *)malloc(sizeof(tPilha));
    pilha->qtd = 0;

    return pilha;
}

int getN(tPilha *pilha)
{
    return pilha->topo;
}

void imprimeCelula(tCelula *celula)
{
    printf("Float: %s\n", getNome(celula));
}

void imprimePilha(tPilha *pilha)
{
    int i = 0;

    if (pilha != NULL && getTopo(pilha) > 0)
    {
        for (i = getTopo(pilha) - 1; i >= 0; i--)
        {
            imprimeCelula(pilha->stack[i]);
        }
    }
    else
    {
        printf("Pilha invalida/vazia\n");
    }
}

tCelula *pop(tPilha *pilha)
{
    if (pilha != NULL)
    {
        pilha->topo--;
        return pilha->stack[pilha->topo];
    }

    return NULL;
}

void popBolado(tPilha *pilha)
{
    if (pilha != NULL)
    {
        pilha->topo--;
    }
}

void push(tCelula *celula, tPilha *pilha)
{
    if (pilha != NULL && celula != NULL)
    {
        if (getTopo(pilha) < 10)
        {
            pilha->stack[getTopo(pilha)] = celula;
            pilha->topo++;
        }
        else
        {
            printf("Pilha cheia\n");
        }
    }
}

void liberacelula(tCelula *celula)
{
    if (celula != NULL)
    {
        free(celula->nome);
        celula->idade = -1;
        free(celula->endereco);
    }
}

void destroiPilha(tPilha *pilha)
{
    int i;

    if (pilha != NULL)
    {
        for (i = 0; i < getTopo(pilha); i++)
        {
            liberacelula(pilha->stack[i]);
            free(pilha->stack[i]);
        }
    }
    free(pilha);
}

tCelula *inicializacelula(char *nome, int idade, char *endereco)
{
    tCelula *renanM = (tCelula *)malloc(sizeof(tCelula));

    renanM->nome = (char *)malloc(strlen(nome) * sizeof(char) + 1);
    strcpy(renanM->nome, nome);

    renanM->endereco = (char *)malloc(strlen(endereco) * sizeof(char) + 1);
    strcpy(renanM->endereco, endereco);

    renanM->idade = idade;

    return renanM;
}
