#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

Fila* cria_fila()
{
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    nova->principal = cria_pilha();
    nova->aux = cria_pilha();

    return nova;
}

void insere(Pessoa* pessoa, Fila *f){
    push(pessoa, f->principal);
}

Pessoa* retira (Fila* f)
{
    Pessoa* p;
    if (f->principal != NULL && f->aux != NULL && f != NULL)
    {
        while(!vazia_pilha(f->principal))
        {
            push(pop(f->principal), f->aux);
        }

        p = pop(f->aux);

        while(!vazia_pilha(f->aux))
        {
            push(pop(f->aux), f->principal);
        }
        return p;
	}

    return NULL;
}

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


Fila* destroi_fila(Fila* fila){
    if (fila != NULL)
    {
        destroi_pilha(fila->principal);
        destroi_pilha(fila->aux);
        free(fila);
    }
}

int Vazia_fila(Fila *fila)
{
    return (fila->principal == NULL && fila->aux == NULL);
}

void imprime_fila(Fila *f)
{
    imprime_pilha(f->principal);
}
