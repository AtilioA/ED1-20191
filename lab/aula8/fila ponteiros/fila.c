#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila *cria_fila(void)
{
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    if (nova == NULL)
    {
        return NULL;
    }

    nova->qtd = 0;
    nova->cabeca = nova->ultimo = NULL;

    return nova;
}

tCelula *inicializaCelula(Pessoa *p)
{
    if (p == NULL)
    {
        return NULL;
    }

    tCelula *nova = (tCelula *)malloc(sizeof(tCelula));
    if (nova == NULL)
    {
        return NULL;
    }

    nova->pessoa = p;
    nova->prox = NULL;

    return nova;
}

void insere(Pessoa *pessoa, Fila *fila)
{
    if (fila != NULL && pessoa != NULL)
    {
        tCelula *nova = (tCelula *)malloc(sizeof(tCelula));
        nova->pessoa = pessoa;
        nova->prox = NULL;

        if (fila->qtd == 0)
        {
            fila->cabeca = nova;
            fila->ultimo = fila->cabeca;
        }
        else
        {
            fila->ultimo->prox = nova;
            fila->ultimo = nova;
        }

        fila->qtd++;
    }
}

Pessoa *retira(Fila *fila)
{
    if (fila != NULL)
    {
        Pessoa *retirada = fila->cabeca->pessoa;
        tCelula *celula = fila->cabeca;

        fila->cabeca = fila->cabeca->prox;
        free(celula);

        fila->qtd--;

        return retirada;
    }

    return NULL;
}

void destroiPessoa(Pessoa *p)
{
    if (p != NULL)
    {
        free(p->nome);
        free(p->end);
        free(p);
    }
}

Fila *destroi_fila(Fila *fila)
{
    if (fila == NULL)
    {
        return NULL;
    }

    while (fila->cabeca != NULL)
    {
        destroiPessoa(retira(fila));
    }
    fila->qtd = -1;
    free(fila);

    return fila;
}

int Vazia_fila(Fila *fila)
{
    return (fila->qtd == 0);
}

void imprimeFila(Fila *fila)
{
    if (fila != NULL)
    {
        tCelula *aux = fila->cabeca;

        while (aux != NULL)
        {
            imprimePessoa(aux->pessoa);
            aux = aux->prox;
        }
    }
}

void separa_filas(Fila *f, Fila *f_maiores, Fila *f_menores)
{
    if (f != NULL || f_maiores != NULL || f_menores != NULL)
    {
        Pessoa *p;

        while (!Vazia_fila(f))
        {
            p = retira(f);

            if (retorna_idade(p) > 60)
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

Pessoa *inicializaPessoa(char *nome, int idade, char *endereco)
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    p->idade = idade;
    p->end = (char *)malloc((strlen(endereco) + 1) * sizeof(char));
    strcpy(p->end, endereco);
    p->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(p->nome, nome);
    return p;
}

void imprimePessoa(Pessoa *p)
{
    printf("Pessoa: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Endereco: %s\n", p->end);
    printf("\n");
}

int retorna_idade(Pessoa *pessoa)
{
    return pessoa->idade;
}
