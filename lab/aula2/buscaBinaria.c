// isso ta bem errado rsrs

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printaVetor(int lista[], int tamLista)
{
    int i = 0, j = 0;

    for (i = 0; i < tamLista; i++)
    {
        printf("%i ", lista[i]);
    }
}

void bolhxSortX(int lista[], int tamLista)
{
    int i = 0, j = 0;

    for (i = 0; i < tamLista; i++)
    {
        for (j = 0; j < tamLista - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                troca(&lista[j], &lista[j + 1]);
            }
        }
    }
}

int buscxNaoBinarix(int lista[], int tamLista)
{
    int i = 0, inf = 0, sup = 9;
    int meio = 0, buscado = 0;

    printf("Informe o item a ser buscado: ");
    scanf("%i", &buscado);

    while (inf <= sup)
    {
        meio = (inf + sup) / 2;
        printf("meio: %i\n", meio);

        if (lista[meio] == buscado)
        {
            return meio;
        }

        if (lista[meio] > buscado)
        {
            sup = meio - 1;
        }

        else
        {
            inf = meio + 1;
        }

    }

    return -1;
}

int main()
{
    int a[10] = {5, 3, 2, 1, 24, 64, 8, 9, 0, 11};

    bolhxSortX(a, 10);
    printaVetor(a, 10);

    int cade = buscxNaoBinarix(a, 10);
    if (cade != -1)
    {
        printf("cade ta aki: posicao %i ou entao %io elemento\n\n", cade, cade + 1);
    }
    else
    {
        printf("tem nao fi\n\n");
    }
}
