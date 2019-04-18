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

    printf("Quantidade de produtos: %i\n", quantidadeLista(&lista));
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
    tProduto p = buscaCodigo(&lista, 3);
    imprimeProduto(p);

    printf("\nProduto mais barato:\n");
    tProduto barato = maisBarato(&lista);
    imprimeProduto(barato);

    destroiLista(&lista);

    return 0;
}
