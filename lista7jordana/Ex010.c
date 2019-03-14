/* 15) Crie um programa para manipular vetores. O seu programa deve implementar uma
função chamada inverte_vetor, que recebe como parâmetro dois vetores V1 e V2,
ambos de tamanho N. A função deve copiar os elementos de V1 para V2 na ordem
inversa. Ou seja, se a função receber V1 = {1,2,3,4,5}, a função deve copiar os elementos
para V2 na seguinte ordem: V2 = {5,4,3,2,1}. Além disso, a função também deve retornar
o maior valor encontrado em V1. A função deve obedecer ao seguinte protótipo:
int inverte_vetor(int *v1, int *v2, int n); */

#include <stdio.h>
#include <stdlib.h>

void le_vetor(int *vetor, int tamVetor)
{
    int i = 0;

    printf("Informe os valores do vetor:\n");
    for (i = 0; i < tamVetor; i++)
    {
        scanf("%i", &vetor[i]);
    }
}

void printa_vetor(int *vetor, int tamVetor)
{
    int i;

    printf("\n");
    for (i = 0; i < tamVetor; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int inverte_vetor(int *v1, int *v2, int *maiorV1, int n)
{
    int i = 0, k = n - 1;

    *maiorV1 = v1[0];
    for (i = 0; i < n; i++)
    {
        v2[k - i] = v1[i];

        if (*maiorV1 < v2[k - i])
        {
            *maiorV1 = v2[k - i];
        }
    }
}

int main()
{
    int *v1, *v2, maiorV1 = 0, n;

    printf("Informe o tamanho dos vetores: ");
    scanf("%i", &n);

    v1 = (int *)malloc(n * sizeof(int));
    v2 = (int *)malloc(n * sizeof(int));

    printf("V1:\n");
    le_vetor(v1, n);

    inverte_vetor(v1, v2, &maiorV1, n);
    printa_vetor(v1, n);
    printa_vetor(v2, n);
    printf("Maior elemento de V1: %i\n", maiorV1);

    free(v1);
    free(v2);
}
