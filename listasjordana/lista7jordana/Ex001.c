/* 1) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira.
*/
// Com alocação dinâmica


#define TAM 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s1, *s2;

    s1 = (char*)malloc(TAM * sizeof(char));
    s2 = (char*)malloc(TAM * sizeof(char));

    printf("Informe a primeira string: ");
    fgets(s1, TAM, stdin);
    printf("Informe a segunda string: ");
    fgets(s2, TAM, stdin);

    // Remove '\n' do fgets
    strtok(s1, "\n");
    strtok(s2, "\n");

    printf("\nS1: %s\n", s1);
    printf("S2: %s\n", s2);

    if (strstr(s1, s2) == 0) // Retorna 0 se s2 não estiver em s1
    {
        printf("A segunda string nao ocorre na primeira.\n");
    }
    else
    {
        printf("A segunda string ocorre na primeira.\n");
    }

    free(s1);
    free(s2);

    return 0;
}
