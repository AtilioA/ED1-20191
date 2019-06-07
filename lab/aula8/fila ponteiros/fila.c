#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

Pessoa inicializaPessoa(char* nome, int idade, char* endereco)
{
	Pessoa p;

	p.idade = idade;
	p.end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy (p.end, endereco);
	p.nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy (p.nome, nome);

	return p;
}

tCelula *inicializaC(char *nome, int idade, char *end)
{
    tCelula *nova;

    nova->pessoa = inicializaPessoa(nome, idade, end);
    nova->prox = NULL;
    return nova;
}

Fila* cria_fila()
{
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    nova->cabeca = NULL;
    nova->ultimo = NULL;

    return nova;
}

void insere(tCelula* celula, Fila *fila)
{
    if (fila != NULL && celula != NULL)
    {
        celula->prox = NULL;
        fila->ultimo->prox = celula->prox;
        fila->ultimo = celula;
        fila->qtd++;
    }
}

Pessoa* retira (Fila* fila)
{
    if (fila != NULL)
    {
        Pessoa* retirada;

        retirada = &(fila->cabeca->prox->pessoa);
        fila->cabeca->prox = fila->cabeca->prox->prox;

        return retirada;
	}

    return NULL;
}

Fila* destroi_fila(Fila* fila){
    if (fila != NULL)
    {
        tCelula *anterior = fila->cabeca;
        tCelula *atual = fila->cabeca->prox;
        while (atual != NULL) // CUIDADO AQUI
        {
            free(anterior);
            atual = atual->prox;
            anterior = atual;
        }
        free(fila);
    }
}

int Vazia_fila(Fila *fila)
{
    return fila->qtd == 0;
}

void imprime_fila(Fila *fila)
{
    if (fila != NULL && fila->qtd > 0)
    {
        tCelula *aux = fila->cabeca;

        while (aux != NULL)
        {
            printf("foi\n");
            // imprimePessoa(aux->pessoa);
            aux = aux->prox;
        }
    }
}

/*
void separa_filas(Fila* f, Fila* f_maiores, Fila* f_menores)
{
    if(f != NULL || f_maiores != NULL || f_menores != NULL)
    {
        Pessoa *p;

        while(!vazia_pilha(f->principal))
        {
            p = retira(f);
            if(retorna_idade(p) > 60)
            {
                insere(p, f_maiores);
            }
            else
            {
                insere(p, f_menores);
            }
        }
    }
}

*/
