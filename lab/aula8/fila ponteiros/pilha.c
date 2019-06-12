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


void destroi_pessoa(Pessoa* p){
    if (p != NULL)
    {
       free(p->nome);
       free(p->end);
       free(p);
    }
}

Pessoa* inicializaPessoa2(char* nome, int idade, char* endereco){
	Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));
	p->idade = idade;
	p->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy (p->end, endereco);
	p->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy (p->nome, nome);
	return p;
}

void imprimePessoa(Pessoa* p){
		printf ("Pessoa: %s\n", p->nome);
		printf ("Idade: %d\n", p->idade);
		printf ("Endereco: %s\n", p->end);
		printf ("\n");

}
