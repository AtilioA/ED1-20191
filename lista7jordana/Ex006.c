/* 10) Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmética de ponteiros, leia os valores desse array do teclado e imprima o dobro
de cada valor lido. */

#include <stdio.h>
#include <stdlib.h>

void leArray(int *array, int tamArray)
{
    int i = 0;

    printf("Informe os valores do array:\n");
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
}

void dobraArray(int *array, int tamArray)
{
    int i = 0;

    for (i = 0; i < tamArray; i++)
    {
        *(array + i) = 2 * *(array + i);
    }
}

int main()
{
    int *array, tamArray = 5;

    array = (int *)malloc(tamArray * sizeof(int));

    leArray(array, tamArray);
    printaArray(array, tamArray);
    dobraArray(array, tamArray);
    printaArray(array, tamArray);

    free(array);
}
