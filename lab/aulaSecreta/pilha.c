/*
 * pilha.c
 *
 *  Created on: 11/07/2013
 *      Author: pdcosta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

tPilha *criaPilha()
{
    tPilha *nova = (tPilha *)malloc(sizeof(tPilha));

    nova->topo = NULL;
    nova->qtd = 0;

    return nova;
}

int retornaIdade(tPessoa *pessoa)
{
    return pessoa->idade;
}

int tamanhoPilha(tPilha *pilha)
{
    return pilha->qtd;
}

void destroiPessoa(tPessoa *pessoa)
{
    if (pessoa != NULL)
    {
        if (pessoa->nome != NULL)
        {
            free(pessoa->nome);
        }
        if (pessoa->end != NULL)
        {
            free(pessoa->end);
        }
    }
}

void destroiCelula(tCelula *celula)
{
    if (celula != NULL)
    {
        destroiPessoa(&celula->pessoa); // &?
        free(celula);
    }
}

tPilha *destroiPilha(tPilha *pilha)
{
    if (pilha != NULL)
    {
        while (!vaziaPilha(pilha))
        {
            destroiCelula(pop(pilha));
        }
    }
    free(pilha);
    return NULL;
}

void imprimePessoa(tPessoa *pessoa)
{
    if (pessoa != NULL)
    {
        printf("Pessoa: %s\n", pessoa->nome);
        printf("Idade: %d\n", pessoa->idade);
        printf("Endereco: %s\n", pessoa->end);
        printf("\n");
    }
}

void imprimeCelula(tCelula *celula)
{
    if (celula != NULL)
    {
        imprimePessoa(&celula->pessoa);
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

int vaziaPilha(tPilha *pilha)
{
    if (pilha->qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(tCelula *celula, tPilha *pilha)
{
    if (celula != NULL && pilha != NULL)
    {
        printf("deus SIM pushou no server\n");
        celula->prox = pilha->topo;
        pilha->topo = celula;
        pilha->qtd++;
    }
}

tCelula* pop(tPilha *pilha){
    if (pilha != NULL && !vaziaPilha(pilha)){
        tCelula *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        pilha->qtd--;
        aux->prox = NULL;
        return aux;
    }
    return NULL;
}

tPessoa *inicializaPessoa2(char* nome, int idade, char* endereco){
	tPessoa* nova = (tPessoa*) malloc (sizeof(tPessoa));

	nova->idade = idade;
	nova->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy (nova->end, endereco);
	nova->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy (nova->nome, nome);

	return nova;
}

tPessoa *inicializaPessoa(char *nome, int idade, char *endereco){
    tPessoa *nova = (tPessoa*) malloc(sizeof(tPessoa));
    if(nova == NULL) return NULL; //?????

    nova->nome = (char*) malloc((sizeof(char) * (strlen(nome) + 1)));
    if(nova->nome == NULL)  return NULL;
    nova->end = (char*) malloc((sizeof(char) * (strlen(endereco) + 1)));
    if(nova->end == NULL) return NULL;
    strcpy(nova->nome, nome);
    strcpy(nova->end, endereco);
    nova->idade = idade;
    return nova;

}

/* chatzim melhor q IRC < deus



*/
