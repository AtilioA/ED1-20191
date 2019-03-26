/* Todas as funções devem estar em um único arquivo aula1.c. Submeter no AVA
até o final da aula.

Autor: Atílio Antônio Dadalto
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int ex3()
{
    int n1, n2;

    while (scanf("%d %d", &n1, &n2) == 2)
    {

        if (trocaInteiros(&n1, &n2))
        {
            printf("TROCADO: %d %d\n", n1, n2);
        }
        else
        {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }
    return 0;
}

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

// Exercício 6
void inverte(int n, int *vet)
{
    int i = 0, *vetAux;

    vetAux = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        *(vetAux + i) = *(vet + i);
    }

    for (i = 0; i < n; i++)
    {
        *(vet + i) = *(vetAux + n - i - 1);
    }

    free(vetAux);
}

int *leVetor(int n)
{
    int i = 0, *vet;

    vet = (int *)malloc(n * sizeof(int));

    printf("Informe os elementos do vetor:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%i", &vet[i]);
    }

    return vet;
}

void ex6()
{
    int n, *vet;

    printf("Informe o tamanho do vetor: ");
    scanf("%i", &n);

    vet = leVetor(n);

    printaVet(vet, n);
    inverte(n, vet);
    printaVet(vet, n);

    free(vet);
}

// Exercício 7
int verificaSubstring(char *s1, char *s2)
{
    int i = 0, j = 0, ocorre = 0;
    int tamS1 = strlen(s1), tamS2 = strlen(s2);

    for (i = 0; i < tamS1; i++)
    {
        if (*(s1 + i) == *(s2))
        {
            for (j = 0; j < tamS2; j++)
            {
                if (i + j >= tamS1)
                {
                    break;
                }

                if (*(s1 + i + j) == *(s2 + j)) // Comparando pedaços cada vez menores de S1 com S2
                {
                    ocorre++;
                }
            }

            if (ocorre == tamS2)
            {
                return 1;
            }
            else
            {
                ocorre = 0;
            }
        }
    }

    return 0;
}

void ex7()
{
    int tamS1, tamS2;
    char *s1, *s2;

    printf("Informe o tamanho da primeira string: ");
    scanf("%i", &tamS1);

    printf("Informe o tamanho da segunda string: ");
    scanf("%i", &tamS2);

    s1 = (char *)malloc(tamS1 * sizeof(char));
    s2 = (char *)malloc(tamS2 * sizeof(char));

    printf("Informe a primeira string: ");
    getchar(); // Para não pular o fgets
    fgets(s1, tamS1 + 1, stdin);
    printf("Informe a segunda string: ");
    fgets(s2, tamS2 + 1, stdin);

    // Remove '\n' do fgets
    strtok(s1, "\n");
    strtok(s2, "\n");

    printf("\nS1: %s\n", s1);
    printf("S2: %s\n", s2);

    if (verificaSubstring(s1, s2))
    {
        printf("S2 eh substring de S1.\n");
    }
    else
    {
        printf("S2 NAO eh substring de S1.\n");
    }

    free(s1);
    free(s2);
}

void main()
{
    // ex1();
    // ex2();
    // ex3();
    // ex4();
    // ex6();
    // ex7();
}
