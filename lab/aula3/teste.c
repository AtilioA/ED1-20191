#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    TipoLista listosa;
    listaVazia(&listosa);

    Insere(CriarProduto(), &listosa);
    Insere(CriarProduto(), &listosa);
    Imprime(listosa);

    produto produtoMaisBarato = maisBarato(&listosa);
    ImprimeProduto(&produtoMaisBarato);


    return 0;
}
