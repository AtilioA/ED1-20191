#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

tPilha *criaPilha()
{
    tPilha *pilha;

    pilha = (tPilha *)malloc(sizeof(tPilha));
    pilha->topo = 0;

    return pilha;
}

char *getNome(tPessoa *pessoa)
{
    return pessoa->nome;
}

int getIdade(tPessoa *pessoa)
{
    return pessoa->idade;
}

char *getEnd(tPessoa *pessoa)
{
    return pessoa->endereco;
}

int getTopo(tPilha *pilha)
{
    return pilha->topo;
}

void imprimePessoa(tPessoa *pessoa)
{
    printf("Nome: %s\n", getNome(pessoa));
    printf("Idade: %i\n", getIdade(pessoa));
    printf("Endereco: %s\n", getEnd(pessoa));
}

void imprimePilha(tPilha *pilha)
{
    int i;

    if (pilha != NULL && getTopo(pilha) != 0)
    {
        for (i = 1; i < getTopo(pilha); i++)
        {
            imprimePessoa(pilha->stack[i]);
        }
    }
}

tPessoa *pop(tPilha *pilha)
{
    if (pilha != NULL)
    {
        pilha->topo--;
        return pilha->stack[pilha->topo];
    }

    return NULL;
}

void push(tPessoa *pessoa, tPilha *pilha)
{
    if (pilha != NULL && pessoa != NULL)
    {
        if (getTopo(pilha) < 10)
        {
            pilha->stack[getTopo(pilha)] = pessoa;
            pilha->topo++;
        }
        else
        {
            printf("Pilha cheia\n");
        }
    }
}

void liberaPessoa(tPessoa *pessoa)
{
    free(pessoa->nome);
    pessoa->idade = -1;
    free(pessoa->endereco);
}

void destroiPilha(tPilha *pilha)
{
    int i;

    for (i = 0; i > getTopo(pilha); i++)
    {
        liberaPessoa(pilha->stack[i]);
        free(pilha->stack[i]);
    }
    free(pilha);
}

/* Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
tPessoa *inicializaPessoa(char *nome, int idade, char *endereco)
{
    tPessoa *renanM = (tPessoa *)malloc(sizeof(tPessoa));

    renanM->nome = (char *)malloc(strlen(nome) * sizeof(char) + 1);
    strcpy(renanM->nome, nome);

    renanM->idade = idade;

    renanM->endereco = (char *)malloc(strlen(endereco) * sizeof(char) + 1);
    strcpy(renanM->endereco, endereco);

    return renanM;
}
