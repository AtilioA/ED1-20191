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


tCelula *criaCelula(float n)
{
    tCelula *celula = (tCelula *)malloc(sizeof(tCelula));

    if (celula != NULL)
    {
        celula->pessoa.nome = NULL;
        celula->pessoa.end = NULL;
        celula->pessoa.idade = -1;
        celula->prox = NULL;
    }

    return celula;
}

void push(tCelula* celula, Pilha* pilha){
    celula->prox = pilha->topo;
    pilha->topo = celula;
    pilha->qtd++;
}

Pessoa* pop(Pilha* pilha){
    if (vazia_pilha (pilha))
    {
        return NULL;
    }

    Pessoa* p = NULL;

    p = pilha->topo->pessoa;
    pilha->topo = pilha->topo->prox;
    pilha->qtd--;

    return p;
}

void destroi_pessoa(Celula* p){
    if (p != NULL)
    {
       free(p->nome);
       free(p->end);
       free(p);
    }
}

Pilha* destroi_pilha(Pilha* pilha){
  while (!vazia_pilha(pilha)){

   destroi_pessoa(pop(pilha));
  }
  free(pilha);
  return NULL;
}

int vazia_pilha (Pilha* pilha){
   return (pilha->topo == NULL);
}

int tamanho_pilha (Pilha* p){
   return p->qtd;
}

tCelula *inicializaCelula(char* nome, int idade, char* endereco){
	tCelula* p = (tCelula*) malloc (sizeof(tCelula));
	p->idade = idade;
	p->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy (p->end, endereco);
	p->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy (p->nome, nome);
	return p;
}

void imprimeCelula(tCelula *celula)
{
    if (celula != NULL)
    {
        printf ("Pessoa: %s\n", celula);
        printf ("Idade: %d\n", celula);
        printf ("Endereco: %s\n", celula);
        printf ("\n");
    }
}

void imprime_pilha(tPilha *pilha)
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

int retorna_idade (Pessoa* p){
    return p->idade;
}
