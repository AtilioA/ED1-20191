/* 2) Faça um programa que receba do usuário o tamanho de uma string e chame uma função
para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o
conteúdo dessa string. O programa deve imprimir a string sem suas vogais
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int tamStr;

    printf("Informe o tamanho da string: ");
    scanf("%i", &tamStr);

    str = (char *)malloc(tamStr * sizeof(char));

    printf("Informe o conteudo da string:\n");
    getchar();
    fgets(str, tamStr + 1, stdin);

    printf("String: %s", str);

    free(str);

    return 0;
}
