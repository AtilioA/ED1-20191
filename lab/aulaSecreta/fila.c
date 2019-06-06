#include <stdlib.h>
#include "fila.h"
#include "pilha.h"
#include <stdio.h>

tCelula *inicializaCelula(tPessoa *pessoa){
    if(pessoa == NULL) return NULL;
    tCelula *nova = (tCelula*) malloc(sizeof(tCelula));
    if(nova == NULL) return NULL;
    nova->prox = NULL;
    nova->pessoa = *pessoa;
    return nova;
}

tFila *criaFila()
{
    tFila *nova = (tFila *)malloc(sizeof(tFila));

    nova->principal = criaPilha();
    nova->aux = criaPilha();

    return nova;
}

void insere(tCelula *celula, tFila *fila)
{
    push(celula, fila->principal);
}

tCelula *retira (tFila* fila)
{
    tCelula *p;
    if (fila->principal != NULL && fila->aux != NULL && fila != NULL)
    {
        while(!vaziaPilha(fila->principal))
        {
            push(pop(fila->principal), fila->aux);
        }

        p = pop(fila->aux);

        while(!vaziaPilha(fila->aux))
        {
            push(pop(fila->aux), fila->principal);
        }
        return p;
	}

    return NULL;
}

void imprimeFila(tFila *fila)
{
    imprimePilha(fila->principal);
}

int vaziaFila(tFila *fila)
{
    if (fila->principal->qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void separaFilas(tFila *fila, tFila *f_maiores, tFila *f_menores)
{

}

tFila *destroiFila(tFila *fila)
{
    if (fila != NULL)
    {
        if (fila->principal != NULL)
        {
            destroiPilha(fila->principal);
        }
        if (fila->aux != NULL)
        {
            destroiPilha(fila->aux);
        }

        free(fila);

        return NULL;
    }
}



/* chatzim melhor q IRC <-- deus







__=======__\|/   berilhes
||          \\
||            ^
||      -====
\\         //
    =======//

b) Implemente o mesmo TAD fila (definido no arquivo fila.h) com a
implementação de ponteiros que vimos em sala de aula. Teste sua
implementação com o mesmo testador progfila.c.
*/
