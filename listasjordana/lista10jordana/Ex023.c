/* 3) Faça um programa que leia dados de 5 livros: título (máximo 30 letras), autor (máximo 15
letras) e ano, armazenando-os em um vetor. Procure um livro por título, perguntando ao usuário
qual título deseja buscar. Mostre os dados de todos os livros encontrados. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro
{
    char titulo[30];
    char autor[15];
    int ano;
};
typedef struct Livro Livro;

void printaLivro(Livro livro)
{
    printf("\nTitulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano: %i\n", livro.ano);
}

void buscaLivros(Livro *livros, int nLivros)
{
    int i = 0, nAchados = 0;
    char *livroBuscado;

    livroBuscado = (char *)malloc(30 * sizeof(char));
    printf("Informe o titulo a ser buscado: ");
    scanf("%s", &livroBuscado);

    for (i = 0; i < nLivros; i++)
    {
        if (strcmp(livroBuscado, livros[i].titulo) == 0)
        {
            printaLivro(livros[i]);
            nAchados++;
        }
    }

    if (nAchados == 0)
    {
        printf("O livro nao foi encontrado.\n");
    }

    free(livroBuscado);
}

Livro leLivro()
{
    Livro livro;

    printf("Informe o titulo: ");
    scanf("%s", &livro.titulo);

    printf("Informe o autor: ");
    scanf("%s", &livro.autor);

    printf("Informe o ano de lancamento: ");
    scanf("%i", &livro.ano);

    return livro;
}

Livro *leLivros(int nLivros)
{
    int i;
    Livro *livros;

    livros = (Livro *)malloc(nLivros * sizeof(nLivros));

    for (i = 0; i < nLivros; i++)
    {
        livros[i] = leLivro();
    }

    return livros;
}

int main()
{
    int nLivros;
    Livro *livros;

    printf("Informe o numero de livros: ");
    scanf("%i", &nLivros);

    printf("Informe os dados dos %i livros:\n", nLivros);
    livros = leLivros(nLivros);

    buscaLivros(livros, nLivros);

    free(livros);

    return 0;
}
