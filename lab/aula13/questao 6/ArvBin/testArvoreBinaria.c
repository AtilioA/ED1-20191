#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreBinaria.h"

int iguais(ArvBin *n1, ArvBin *n2)
{
    if (n1 == n2)
    {
        return 1;
    }
    if (n1 == NULL || n2 == NULL)
    {
        return 0;
    }

    if ((*n1)->info != (*n2)->info)
    {
        return 0;
    }

    return iguais((*n1)->esq, (*n2)->esq) && iguais((*n1)->dir, (*n2)->dir);
}

int ehSubarvore(ArvBin *n1, ArvBin *n2)
{
    if (n2 == NULL)
    {
        return 1;
    }
    if (n1 == NULL)
    {
        return 0;
    }

    return iguais(&n1, &n2) || ehSubarvore(&(*n1)->esq, *n2) || ehSubarvore(&(*n1)->dir, *n2);
}

int main(int argc, char *argv[])
{

    ArvBin *a = cria_ArvBin();
    insere_ArvBin(a, 3);
    insere_ArvBin(a, 2);
    insere_ArvBin(a, 1);
    insere_ArvBin(a, 4);
    insere_ArvBin(a, 5);
    insere_ArvBin(a, 10);
    insere_ArvBin(a, 11);
    insere_ArvBin(a, 8);
    insere_ArvBin(a, 7);
    ArvBin *b = cria_ArvBin();
    insere_ArvBin(b, 10);
    insere_ArvBin(b, 8);
    insere_ArvBin(b, 11);

    preOrdem_ArvBin(a);
    printf("\n");
    preOrdem_ArvBin(b);
    int eh = ehSubarvore(a, b);
    printf("\n%i\n", eh);

    libera_ArvBin(a);
    libera_ArvBin(b);
    return 0;
}
