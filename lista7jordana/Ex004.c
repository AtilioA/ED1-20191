/* 7) Escreva um programa que declare um inteiro, um float e um char, e ponteiros para
inteiro, float, e char. Leia os valores do inteiro, float e char do teclado, armazene nas
variáveis e depois associe as variáveis aos ponteiros (use &). Modifique os valores de
cada variável usando os ponteiros. Imprima os valores das variáveis antes e após a
modificação. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int meuInt, *ptPrMeuInt;
    float meuFloat, *ptPrMeuFloat;
    char meuChar, *ptPrMeuChar;

    printf("Informe o valor do inteiro: ");
    scanf("%i", &meuInt);

    printf("Informe o valor do float: ");
    scanf("%f", &meuFloat);

    printf("Informe o valor do char: ");
    scanf(" %c", &meuChar);

    // Associa as variáveis aos ponteiros
    ptPrMeuInt = &meuInt;
    ptPrMeuFloat = &meuFloat;
    ptPrMeuChar = &meuChar;

    printf("\nmeuInt: %i\n", meuInt);
    printf("meuFloat: %g\n", meuFloat);
    printf("meuChar: %c\n\n", meuChar);

    printf("Alterando valores atraves de ponteiros...\n");
    *ptPrMeuInt += 5;
    *ptPrMeuFloat += 3.1415;
    *ptPrMeuChar = 's';

    printf("meuInt: %i\n", meuInt);
    printf("meuFloat: %g\n", meuFloat);
    printf("meuChar: %c\n", meuChar);

    free(ptPrMeuInt);
    free(ptPrMeuFloat);
    free(ptPrMeuChar);

    return 0;
}
