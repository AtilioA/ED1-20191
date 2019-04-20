#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main()
{
    tLista lista;
    tProduto item;

    FLVazia(&lista);
    printf("Lista vazia criada com sucesso!\n");

    printf("Inserindo itens...\n");
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
    item = criaProduto(3,"Beterraba", 28, 32);
    insere(item, &lista);

    printf("Imprimindo a lista:\n");
    imprimeLista(&lista);

    printf("\nRetirando item de codigo 4...\n");
    retira(4, &lista, &item);
    printf("\nRetirando item de codigo 1...\n");
    retira(1, &lista, &item);
    printf("\nRetirando item de codigo 5...\n");
    retira(5, &lista, &item);
    printf("\nRetirando item de codigo 6...\n");
    retira(6, &lista, &item);

    printf("\nLista apos remover itens:\n");
    imprimeLista(&lista);

    printf("\nBuscando produto de codigo 3:\n");
    tProduto p1 = buscaCodigo(&lista, 3);
    imprimeProduto(p1);
    // Produto 4 foi removido
    printf("\nBuscando produto de codigo 4:\n");
    tProduto p2 = buscaCodigo(&lista, 4);
    imprimeProduto(p2);
    printf("\nBuscando produto de codigo 7:\n");
    tProduto p3 = buscaCodigo(&lista, 7);
    imprimeProduto(p3);

    printf("\nProduto mais barato:\n");
    tProduto barato = maisBarato(&lista);
    imprimeProduto(barato);

    printf("\n\n");
    destroiLista(&lista);
    printf("Lista destruida com sucesso!\n");

    return 0;
}
