/* 3) Faça um programa para resolver os itens abaixo:
a) Gerar através de uma função, um vetor de N (definido como constante) componentes inteiras
cujos valores de cada componente são dados pela expressão
vetor[i] = rand()%100, i = 1, . . . ,n, com n < N.
b) fornecido um número inteiro entre 0 e 100, pelo teclado, procurá-lo no vetor construído no
item a), usando o algoritmo de pesquisa linear e indicando a primeira posição do vetor que o
número se encontra. Se o número não for encontrado, emita uma mensagem com essa
informação e insira o número na primeira posição do vetor.
Entrada: Um número inteiro indicando o valor de n < 50 e um valor x a ser procurado no vetor.
Saída: A mensagem indicando que o valor x não foi encontrado e a impressão do vetor com o
valor x incluído ou o valor da posição do vetor onde o valor x foi encontrado.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100 // "definido como constante"

void printaVet(int *vetor, int tam)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int pesquisaLinear(int *vetor, int pesquisado, int tam)
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        if (pesquisado == vetor[i])
        {
            printf("Valor %i encontrado na posicao de indice %i", pesquisado, i);
            return i;
        }
    }

    printf("Valor %i nao foi encontrado no vetor.", pesquisado);
    vetor[0] = pesquisado;
    printaVet(vetor, tam);

    return -1;
}

int *criaVetorAleatorio()
{
    int i = 0, *vetor;

    vetor = (int *)malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        vetor[i] = rand() % 100;
    }

    return vetor;
}

int main()
{
    int n, *vetorAleatorio;

    printf("Informe n: ");
    scanf("%i", &n);

    while (n <= 0 || n >= 100)
    {
        printf("Por favor, informe um numero entre 0 e 100: ");
        scanf("%i", &n);
    }

    vetorAleatorio = criaVetorAleatorio();
    pesquisaLinear(vetorAleatorio, n, N);

    free(vetorAleatorio);

    return 0;
}
