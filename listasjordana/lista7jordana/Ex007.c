/* 11) Escreva uma função que aceita como parâmetro um array de inteiros com N valores, e
determina o maior elemento do array e o número de vezes que este elemento ocorreu
no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8,
6, 15, a função deve retorna para o programa que a chamou o valor 15 e o número 3
(indicando que o número 15 ocorreu 3 vezes). A função deve ser do tipo void. */

#include <stdio.h>
#include <stdlib.h>

void leArray(int *array, int tamArray)
{
    int i = 0;

    for (i = 0; i < tamArray; i++)
    {
        scanf("%i", &array[i]);
    }
}

void printaArray(int *array, int tamArray)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tamArray; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void maiorArray(int *array, int tamArray, int *maior, int *qtdMaior)
{
    int i = 0;

    if (tamArray <= 0)
    {
        printf("Nao ha array\n");
        exit(1);
    }

    *maior = array[0];
    *qtdMaior = 1;

    for (i = 1; i < tamArray; i++)
    {
        if (array[i] > *maior)
        {
            *maior = array[i];
            *qtdMaior = 1;
        }
        else
        {
            if (array[i] == *maior)
            {
                *qtdMaior += 1;
            }
        }
    }
}

void main()
{
    int *array, tamArray, maior, qtdMaior;

    printf("Informe o tamanho do array: ");
    scanf("%i", &tamArray);

    array = (int *)malloc(tamArray * sizeof(int));

    leArray(array, tamArray);
    printaArray(array, tamArray);

    maiorArray(array, tamArray, &maior, &qtdMaior);
    printf("Maior elemento: %i, ocorrendo %i vez(es).\n", maior, qtdMaior);
}
