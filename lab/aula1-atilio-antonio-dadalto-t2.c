/* Todas as funções devem estar em um único arquivo aula1.c. Submeter no AVA
até o final da aula.

Autor: Atílio Antônio Dadalto

1 - Escreva um programa que declare um inteiro, um real e um char, e ponteiros
para inteiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique os
valores de cada variável usando os ponteiros. Imprima os valores das variáveis
antes e após a modificação.

2 - Escreva um programa que contenha duas variáveis inteiras. Compare seus
endereços e exiba o maior endereço.

*/


#include <stdio.h>
#include <stdlib.h>

// Exercício 1
void ex1()
{
    int inteiro, *pInteiro;
    float real, *pReal;
    char caractere, *pChar;

    printf("Informe o valor do inteiro: ");
    scanf("%i", &inteiro);

    printf("Informe o valor do float: ");
    scanf("%f", &real);

    printf("Informe o valor do caractere: ");
    scanf(" %c", &caractere);

    pInteiro = &inteiro;
    pReal = &real;
    pChar = &caractere;

    printf("\nValores antigos:\n");
    printf("Inteiro: %i\n", inteiro);
    printf("Real: %f\n", real);
    printf("Caractere: %c\n\n", caractere);

    *pInteiro = 2832;
    *pReal += 3.1415;
    *pChar = 's';

    printf("Novos valores:\n");
    printf("Inteiro: %i\n", inteiro);
    printf("Real: %g\n", real);
    printf("Caractere: %c\n\n", caractere);
}

// Exercício 2
void ex2()
{
    int var1 = 0, var2 = 0, *maiorEnd;

    var1 = rand();
    printf("\n\n%i\n\n", var1);
    if (&var1 > &var2)
    {
        maiorEnd = &var1;
    }
    else
    {
        maiorEnd = &var2;
    }

    printf("Endereco 1: %p\n\n", &var1);
    printf("Endereco 2: %p\n\n", &var2);
    printf("Maior endereco: %p\n\n", maiorEnd);
}

// Exercício 3
int trocaInteiros(int *a, int *b)
{
    int swap;

    if (*a > *b)
    {
        swap = *a;
        *a = *b;
        *b = swap;
        return 1;
    }
    else
    {
        return 0;
    }
}

void ex3()
{
    int n1, n2;

    // printf("Informe n1 e n2: ");
    while (1)
    {
        printf("Informe n1 e n2: ");
        scanf("%i %i", &n1, &n2);

        if (trocaInteiros(&n1, &n2))
        {
            printf("TROCADO: %i %i\n\n", n1, n2);
        }
        else
        {
            printf("ORIGINAL: %i %i\n\n", n1, n2);
        }
    }
}

/*
4 - Crie uma função que receba três parâmetros: um array, o tamanho do array e
um valor do mesmo tipo do array. A função deverá preencher os elementos de
array com esse valor. Não utilize índices para percorrer o array, apenas
aritmética de ponteiros.
*/
// Exercício 4
void printaVet(int *vet, int tamArray)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tamArray; i++)
    {
        printf("%i ", *(vet + i));
    }
    printf("\n");
}

void ex4()
{
    // Tipo inteiro
    int i = 0, *array, tamArray, valorSubstituto;

    printf("Informe o tamanho do array: ");
    scanf("%i", &tamArray);

    printf("Informe o valor a substituir no array: ");
    scanf("%i", &valorSubstituto);

    array = (int *)malloc(tamArray * sizeof(int));

    for (i = 0; i < tamArray; i++)
    {
        *(array + i) = valorSubstituto;
    }

    printaVet(array, tamArray);

    free(array);
}

void main()
{
    // ex1();
    // ex2();
    // ex3();
    ex4();
    // ex6();
    // ex7();
}
