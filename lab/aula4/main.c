#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main()
{

    tLista lista;
    tProduto item;

    FLVazia(&lista);
    printf("Lista vazia criada com sucesso.\n");

    printf("Inserindo itens:\n");
    item = criaProduto(1,"Sabonete", 10, 3.90);
    insere(item, &lista);
    item = criaProduto(2,"Arroz", 20, 13.90);
    insere(item, &lista);
    item = criaProduto(3,"Feijao", 1, 17.90);
    insere(item, &lista);
    item = criaProduto(4,"Tomate", 0, 10);
    insere(item, &lista);
    item = criaProduto(5,"Uva", 5, 8);
    insere(item, &lista);
    imprimeLista(&lista);

    printf("\nRetirando item de codigo 4:\n");
    retira(4, &lista, &item);

    imprimeLista(&lista);

    // tCelula *p = BuscaCodigo(3, &lista);
    // ImprimeProduto(p->Item);
    printf("\nProduto mais barato:\n");
    tProduto barato = maisBarato(&lista);
    imprimeProduto(barato);

    destroiLista(&lista);

    return 0;
}
