#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

int main()
{
    int p = 0, i = 0, nProdutos = 5, codigo = 0;
    TipoLista listaBonita;
    listaVazia(&listaBonita);

    if (estaVazia(listaBonita))
    {
        printf("Lista vazia criada com sucesso\n");
    }

    // Criando 5 produtos de teste
    for (i = 0; i < nProdutos; i++)
    {
        Insere(CriarProduto(), &listaBonita);
    }

    int tamanhoLista = Quantidade(listaBonita);
    printf("\nTamanho da lista: %i\n\n", tamanhoLista);

    // // Teste da função Recupera
    // printf("Informe a posicao do item a ser recuperado: ");
    // scanf("%i", &p);
    // produto itemRecuperado = Recupera(p, &listaBonita);
    // printf("\nProduto recuperado:\n");
    // ImprimeProduto(itemRecuperado);


    produto itemRetirado;
    // Teste da função Retira
    printf("Informe o codigo de um produto a ser removido da lista: ");
    scanf("%i", &codigo);
    if (Retira(codigo, &listaBonita, &itemRetirado))
    {
        printf("\nProduto retirado:\n");
        ImprimeProduto(itemRetirado);
    }

    printf("Informe o codigo de um produto a ser buscado na lista: ");
    scanf("%i", &codigo);
    produto produtoCodigo = buscaProdutoCodigo(&listaBonita, codigo);
    if (!(produtoCodigo.preco == 0)) // Se o preço for 0, o produto não foi encontrado
    {
        ImprimeProduto(produtoCodigo);
    }


    // Teste da função Retira2 removendo o segundo item
    // if (Retira2(prod2, &listaBonita, &itemRetirado))
    // {
    //     printf("\nProduto retirado:\n");
    //     ImprimeProduto(itemRetirado);
    // }


    printf("\n\nTodos os itens (produtos):\n");
    ImprimeLista(listaBonita);

    // // Teste da função maisBarato
    // produto produtoMaisBarato = maisBarato(&listaBonita);
    // printf("\nProduto mais barato:\n");
    // ImprimeProduto(produtoMaisBarato);

    return 0;
}
