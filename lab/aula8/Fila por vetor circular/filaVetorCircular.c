#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaVetorCircular.h"

tFila *criaFila()
{
    tFila *nova = (tFila *)malloc(sizeof(tFila));
    if (nova == NULL)
    {
        return NULL;
    }

    nova->cabeca = 0;
    nova->ultimo = 0;
    nova->qtd = 0;

    return nova;
}

int vaziaFila(tFila *fila)
{
    if (fila == NULL)
    {
        return 1;
    }
    else
    {
        return (fila->cabeca == fila->ultimo) == fila->qtd;
    }
}

void insere(tPessoa *pessoa, tFila *fila)
{
    if (fila != NULL && pessoa != NULL && fila->qtd < MAXTAM)
    {
        fila->pessoas[fila->ultimo] = pessoa;
        fila->ultimo = (fila->ultimo + 1) % MAXTAM;
        fila->qtd++;
    }
}

tPessoa *retira(tFila *fila)
{
    if (fila != NULL && fila->qtd > 0)
    {
        tPessoa *retirada = fila->pessoas[fila->cabeca];

        fila->cabeca = (fila->cabeca + 1) % MAXTAM;
        fila->qtd--;

        return retirada;
    }
    else
    {
        return NULL;
    }
}

void imprimePessoa(tPessoa *p)
{
    printf("Pessoa: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Endereco: %s\n", p->end);
    printf("\n");
}

void imprimeFila(tFila *fila)
{
    if (!vaziaFila(fila))
    {
        for (int i = 0; i < fila->qtd; i++)
        {
            imprimePessoa(fila->pessoas[(fila->cabeca + i) % MAXTAM]);
        }
    }
}

tPessoa *inicializaPessoa(char *nome, int idade, char *endereco)
{
    tPessoa *pessoa = (tPessoa *)malloc(sizeof(tPessoa));

    pessoa->idade = idade;
    pessoa->end = (char *)malloc((strlen(endereco) + 1) * sizeof(char));
    strcpy(pessoa->end, endereco);
    pessoa->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(pessoa->nome, nome);

    return pessoa;
}

void destroiPessoa(tPessoa *pessoa)
{
    if (pessoa != NULL)
    {
        free(pessoa->nome);
        free(pessoa->end);
        free(pessoa);
    }
}

tFila *destroiFila(tFila *fila)
{
    if (fila == NULL)
    {
        return NULL;
    }

    while (fila->qtd > 0)
    {
        destroiPessoa(retira(fila));
    }
    fila->qtd = -1;
    free(fila);
    return NULL;
}

int retornaIdade(tPessoa *pessoa)
{
    return pessoa->idade;
}

void separaFilas(tFila *fila, tFila *filaMaiores, tFila *filaMenores)
{
    if (fila != NULL && filaMaiores != NULL && filaMenores != NULL)
    {
        tPessoa *pessoa;

        while(fila->qtd > 0)
        {
            pessoa = retira(fila);
            if (retornaIdade(pessoa) > 60)
            {
                insere(pessoa, filaMaiores);
            }
            else
            {
                insere(pessoa, filaMenores);
            }
        }
    }
}
