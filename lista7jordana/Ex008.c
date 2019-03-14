/* 12) Implemente uma função que receba como parâmetro um array de números reais de
tamanho N e retorne quantos números negativos há nesse array. Essa função deve
obedecer ao protótipo:
int negativos(float *vet, int N); */

#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N)
{
    int i = 0, nNegativos = 0;

    for (i = 0; i < N; i++)
    {
        if (vet[i] < 0)
        {
            nNegativos++;
        }
    }

    return nNegativos;
}

void leArray(float *vet, int N)
{
    int i = 0;

    printf("Informe os valores do array:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%f", &vet[i]);
    }
}

int main()
{
    float *array;
    int tamArray, nNegativos = 0;

    printf("Informe o tamanho do array: ");
    scanf("%i", &tamArray);

    array = (float *)malloc(tamArray * sizeof(float));

    leArray(array, tamArray);

    nNegativos = negativos(array, tamArray);

    if (nNegativos <= 0)
    {
        printf("O array NAO contem numeros negativos.\n");
    }
    else
    {
        printf("O array contem %i numero(s) negativo(s).\n", nNegativos);
    }

    return 0;
}
