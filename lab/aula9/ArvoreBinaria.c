#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;

ArvBin* cria_ArvBin()
{
    ArvBin *nova = (ArvBin *)malloc(sizeof(ArvBin));

    // (*nova)->info = -1;
    // (*nova)->esq == NULL;
    // (*nova)->dir == NULL;

    return nova;
}

int insere_ArvBin(ArvBin* raiz, int valor)
{
    if (raiz != NULL)
    {
        NO *novo = malloc(sizeof(NO));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = valor;
        NO *aux = (*raiz);

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

// int insere_ArvBin2(ArvBin* raiz, int valor){
//     if(raiz == NULL){
//         return 0;
//     }
//     NO* novo = malloc(sizeof(NO));
//     novo->dir = NULL;
//     novo->esq = NULL;
//     novo->info = valor;
//     NO* aux = (*raiz);
//     if((*raiz) == NULL){
//         (*raiz) = novo;
//         return 1;
//     }else{
//         while(aux->esq != NULL || aux->dir != NULL ){
//             if(valor < aux->info){
//                 if(aux->esq == NULL){
//                     break;
//                 }
//                 aux = aux->esq;
//             }else{
//                 if(aux->dir == NULL){
//                     break;
//                 }
//                 aux = aux->dir;
//             }
//         }

//         if(valor < aux->info){
//             aux->esq = novo;
//         }else{
//             aux->dir = novo;
//         }
//         return 1;
//     }
// }


int consulta_ArvBin(ArvBin* raiz, int valor)
{
    NO *novo = malloc(sizeof(NO));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->info = valor;

    NO *aux = (*raiz);
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
        // if (valor < aux->info)
        // {
        //     aux->esq = novo;
        //     return 1;
        // }
        // else if (valor > aux->info)
        // {
        //     aux->dir = novo;
        //     return 1;
        // }

    }
    else
    {
        *raiz = novo;
        return 1;
    }

    return 0;
}
