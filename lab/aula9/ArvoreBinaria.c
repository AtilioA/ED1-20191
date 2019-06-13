#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} tNo;

ArvBin* cria_ArvBin()
{
    ArvBin *nova = (ArvBin *)malloc(sizeof(ArvBin));
    (*nova) = NULL;
    return nova;
}

int insere_ArvBin(ArvBin* raiz, int valor)
{
    if (raiz != NULL)
    {
        tNo *novo = malloc(sizeof(tNo));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = valor;
        tNo *aux = (*raiz);

        if ((*raiz) == NULL)
        {
            (*raiz) = novo;
            return 1;
        }

        while(aux->esq != NULL || aux->dir != NULL)
        {
            if (valor < aux->info)
            {
                if (aux->esq == NULL)
                {
                    break;
                }
                aux = aux->esq;
            }
            else if (valor > aux->info)
            {
                if (aux->dir == NULL)
                {
                    break;
                }
                aux = aux->dir;
            }
            else
            {
                return 0; // Valor já presente na árvore
            }

        }

        if (valor < aux->info)
        {
            aux->esq = novo;
            return 1;
        }
        else if (valor > aux->info)
        {
            aux->dir = novo;
            return 1;
        }

    }
    else
    {
        return 0;
    }
}

/** Imprime em pre-ordem */
void preOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        if((*raiz)->esq != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->esq));
        }
        if((*raiz)->dir != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->dir));
        }
    }
}

/** Imprime em-ordem */
void emOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz != NULL)
    {
        if((*raiz)->esq != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->esq));
        }
        printf("%d\n", (*raiz)->info);
        if((*raiz)->dir != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->dir));
        }
    }
}

/** Imprime em pós-ordem */
void posOrdem_ArvBin(ArvBin *raiz)
{
    if (raiz != NULL)
    {
        if((*raiz)->esq != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->esq));
        }
        if((*raiz)->dir != NULL)
        {
            preOrdem_ArvBin(&((*raiz)->dir));
        }
        printf("%d\n", (*raiz)->info);
    }
}

int consulta_ArvBin(ArvBin* raiz, int valor)
{
    tNo *aux = (*raiz);
    if (raiz != NULL)
    {
        while(aux->esq != NULL || aux->dir != NULL)
        {
            if (valor < aux->info)
            {
                if (aux->esq == NULL)
                {
                    break;
                }
                aux = aux->esq;
            }
            else if (valor > aux->info)
            {
                if (aux->dir == NULL)
                {
                    break;
                }
                aux = aux->dir;
            }
            else
            {
                return 1; // Valor presente na árvore
            }
        }

        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}

/** Libera em pós-ordem */
void libera_ArvBin(ArvBin *raiz)
{
    if (raiz != NULL)
    {
        if((*raiz)->esq != NULL)
        {
            libera_ArvBin(&((*raiz)->esq));
        }
        if((*raiz)->dir != NULL)
        {
            libera_ArvBin(&((*raiz)->dir));
        }
        free((*raiz));
    }
}
