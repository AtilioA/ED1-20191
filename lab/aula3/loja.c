#include "loja.h"

int listaEPosicaoValidos(TipoLista *lista, Posicao p)
{
    if (estaVazia(*lista) || p >= lista->ultimo)
    {
        printf("Erro! Posicao nao existe.\n");
        return 0;
    }

    return 1;
}

int codigoRepetido(TipoLista *lista, produto x)
{
    int i = 0;

    for (i = lista->primeiro - 1; i < lista->ultimo - 1; i++)
    {
        if (x.codigo == lista->itens[i].codigo)
        {
            return 1;
        }
    }

    return 0;
}

int codigoRepetidoIndice(TipoLista *lista, produto x)
{
    int i = 0;

    for (i = lista->primeiro - 1; i < lista->ultimo - 1; i++)
    {
        if (x.codigo == lista->itens[i].codigo)
        {
            return i;
        }
    }

    return 0;
}

/* Faz a lista ficar vazia */
void listaVazia(TipoLista *lista)
{
    lista->primeiro = INICIO;
    lista->ultimo = lista->primeiro;
}

void Insere(produto x, TipoLista *lista)
{
    if ((lista->ultimo + 1) > MAXTAM)
    {
        printf("A lista esta cheia.\n");
    }

    else if (!(codigoRepetido(lista, x)))
    {
        printf("Adicionando...\n");
        lista->itens[lista->ultimo - 1] = x;
        lista->ultimo++;
    }
    else
    {
        printf("Codigo ja existente!\n");
    }
}

int estaVazia(TipoLista lista)
{
    return (lista.primeiro == lista.ultimo);
}

produto CriarProduto()
{
    produto nossoProdutoLindo;

    printf("Informe o codigo: ");
    scanf("%i", &nossoProdutoLindo.codigo);

    printf("Informe o nome: ");
    getchar();
    fgets(nossoProdutoLindo.nome, 30, stdin);

    printf("Informe o preco: ");
    scanf("%f", &nossoProdutoLindo.preco);

    printf("Informe a quantidade: ");
    scanf("%i", &nossoProdutoLindo.qtd);

    return nossoProdutoLindo;
}

void ImprimeProduto(produto produto)
{
    printf("Codigo do produto: %i.\n", produto.codigo);
    printf("Nome do produto: %s", produto.nome); // string do fgets possui \n
    printf("Preco do produto: %g.\n", produto.preco);
    printf("Quantidade do produto: %i.\n", produto.qtd);
}

int Retira(int codigo, TipoLista *lista, produto *itemRetirado)
{
    if (lista->ultimo == lista->primeiro)
    {
        printf("A lista esta vazia!");
        return 0;
    }

    int indiceCodigo = buscaIndiceCodigo(lista, codigo);

    *itemRetirado = lista->itens[indiceCodigo];
    if (itemRetirado->qtd > 0)
    {
        printf("\nProduto em estoque nao pode ser removido!\n");
        return 0;
    }

    lista->ultimo--;

    for (int i = indiceCodigo; i < lista->ultimo; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }

    return 1;
}

int Retira2(produto x, TipoLista *lista, produto *itemRetirado)
{
    if (lista)

        if (x.qtd > 0)
        {
            printf("Produto em estoque nao pode ser removido!\n");
            return 0;
        }

    int indiceCodigo = codigoRepetidoIndice(lista, x);

    *itemRetirado = lista->itens[indiceCodigo];
    lista->ultimo--;

    for (int i = indiceCodigo; i < lista->ultimo; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }

    return 1;
}

produto Recupera(Posicao p, TipoLista *lista)
{
    if (estaVazia(*lista))
    {
        printf("Lista vazia!\n");
        return;
    }

    produto itemRecuperado = lista->itens[p - 1];
    return itemRecuperado;
}

void ImprimeCodigos(TipoLista Lista)
{
    int i = 0;

    for (i = Lista.primeiro - 1; i <= (Lista.ultimo - 2); i++)
    {
        printf("%d\n", Lista.itens[i].codigo);
    }
}

void ImprimeLista(TipoLista Lista)
{
    int i = 0;

    for (i = Lista.primeiro - 1; i <= (Lista.ultimo - 2); i++)
    {
        printf("Codigo do produto: %d\n", Lista.itens[i].codigo);
        printf("Nome do produto: %s", Lista.itens[i].nome);
        printf("Preco do produto: %g.\n", Lista.itens[i].preco);
        printf("Quantidade do produto: %i.\n\n", Lista.itens[i].qtd);
    }
}

int Quantidade(TipoLista Lista)
{
    if (estaVazia(Lista))
    {
        return 0;
    }

    return Lista.ultimo - 1;
}

int buscaIndiceCodigo(TipoLista *lista, int codigo)
{
    int i = 0;

    for (i = lista->primeiro - 1; i < lista->ultimo - 1; i++)
    {
        if (codigo == lista->itens[i].codigo)
        {
            return i;
        }
    }

    return -1;
}

// Retorna um produto na lista com um código de entrada, se este código existir na lista
produto buscaProdutoCodigo(TipoLista *lista, int codigo)
{
    int indiceProduto = buscaIndiceCodigo(lista, codigo);
    produto produtoBuscado;

    if (indiceProduto >= 0)
    {
        produtoBuscado = lista->itens[indiceProduto];
        return produtoBuscado;
    }
    else
    {
        printf("Nenhum produto na lista possui o codigo fornecido.\n");
        return;
    }
}

int indiceMaisBarato(TipoLista *lista)
{
    int i = lista->primeiro - 1, indiceMaisBarato = 0;

    float menorPreco = lista->itens[lista->primeiro - 1].preco;

    for (i = lista->primeiro; i < lista->ultimo - 1; i++)
    {
        if (lista->itens[i].preco < menorPreco)
        {
            menorPreco = lista->itens[i].preco;
            indiceMaisBarato = i;
        }
    }

    return indiceMaisBarato;
}

produto maisBarato(TipoLista *lista)
{
    produto maisBarato;

    int maisBaratoIndice = indiceMaisBarato(lista);

    maisBarato = lista->itens[maisBaratoIndice];

    return maisBarato;
}
