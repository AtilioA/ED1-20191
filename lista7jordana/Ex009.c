/* 13) Crie uma função para somar dois arrays. Esta função deve receber dois arrays e retornar
a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja
diferente então a função retornará ZERO (0). Caso a função seja concluída com sucesso
a mesma deve retornar o valor UM (1). Utilize aritmética de ponteiros para manipulação
do array */

#include <stdio.h>
#include <stdlib.h>

int somaArrays(int *A, int *B, int *C, int tam)
{
    int i = 0;

    for (i = 0; i < tam; i++)
    {
        *(C + i) = *(A + i) + *(B + i);
    }

    return 1;
}

void leArray(int *array, int tamArray)
{
    int i;

    printf("Informe os valores do array:\n");
    for (i = 0; i < tamArray; i++)
    {
        scanf("%i", &array[i]);
    }
}

void printaArray(int *array, int tamArray)
{
    int i;

    printf("\n");
    for (i = 0; i < tamArray; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int main()
{
    int *A, *B, *C;
    int t1, t2, t3;

    printf("Informe o tamanho do primeiro array: ");
    scanf("%i", &t1);

    printf("Informe o tamanho do segundo array: ");
    scanf("%i", &t2);

    // Fica melhor fazendo a verificação antes
    if (t1 != t2)
    {
        return 0;
    }
    t3 = t1;

    A = (int *)malloc(t1 * sizeof(int));
    B = (int *)malloc(t2 * sizeof(int));
    C = (int *)malloc(t3 * sizeof(int));

    printf("Primeiro array:\n");
    leArray(A, t1);
    printf("Segundo array:\n");
    leArray(B, t2);

    somaArrays(A, B, C, t3);

    printf("\nA:");
    printaArray(A, t1);
    printf("B:");
    printaArray(B, t2);
    printf("C (soma):");
    printaArray(C, t3);

    free(A);
    free(B);
    free(C);
}
