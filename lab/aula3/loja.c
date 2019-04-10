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

    for (i = lista->primeiro - 1; i < lista->ultimo; i++)
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

    for (i = lista->primeiro - 1; i < lista->ultimo; i++)
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
        printf("Item ja existe!\n");
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

void ImprimeProduto(produto *produto)
{
    printf("Codigo do produto: %i.\n", produto->codigo);
    printf("Nome do produto: %s.\n", produto->nome);
    printf("Codigo do produto: %f.\n", produto->preco);
    printf("Quantidade do produto: %i.\n", produto->qtd);
}

void Retira(produto x, TipoLista *lista, produto *ItemRecuperado)
{
    if (lista)


    if (x.qtd > 0)
    {
        printf("Produto em estoque não pode ser removido.\n");
    }

    int codigoBuscado = x.codigo;
    int indiceCodigo = codigoRepetidoIndice(lista, x);

    *ItemRecuperado = lista->itens[indiceCodigo];
    lista->ultimo--;

    for (int i = indiceCodigo; i < lista->ultimo; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }
}

produto Recupera(Posicao p, TipoLista *lista)
{
    if (estaVazia(*lista))
    {
        return;
    }

    produto itemRecuperado = lista->itens[p - 1];
    return itemRecuperado;
}

void Imprime(TipoLista Lista)
{
    int i = 0;

    for (i = Lista.primeiro - 1; i <= (Lista.ultimo - 2); i++)
    {
        printf("%d\n", Lista.itens[i].codigo);
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

void copiaLista(TipoLista *ListaOrigem, TipoLista *ListaDestino)
{
    // if (Vazia(*ListaOrigem))
    // {
    //     printf("Erro! Lista de origem vazia.\n");
    //     return;
    // }

    // FLVazia(ListaDestino);

    // // ( int p = ListaOrigem->Primeiro-1; p < ListaOrigem->Ultimo-1; p++)
    // for (int i = 0; i < Quantidade(*ListaOrigem); i++)
    // {
    //     Insere(Recupera(i, ListaOrigem), ListaDestino);
    // }
}

produto maisBarato(TipoLista *lista)
{
    int i = lista->primeiro - 1;

    produto maisBarato;
    maisBarato.preco = lista->itens[lista->primeiro - 1].preco;

    for (i = lista->primeiro - 1; i < lista->ultimo; i++)
    {
        if (lista->itens[i].preco < maisBarato.preco)
        {
            maisBarato.preco = lista->itens[i].preco;
        }
    }

    return maisBarato;
}
