#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Júlio César, o imperador romano, usava a Cifra de César para enviar ordens secretas aos seus
generais. O código consistia em trocar cada letra de uma mensagem pela terceira letra seguinte. Ou
seja, a letra ‘a’ era substituída por ‘d’, ‘b’ era substituída por ‘e’, e assim por diante:
• ‘a’ ® ‘d’
• ‘b’ ® ‘e’
• ‘c’ ® ‘f’
• ....
• ‘x’ ® ‘a’
• ‘y’ ® ‘b’
• ‘z’ ® ‘c’
Escreva uma função que codifique uma mensagem de acordo com a Cifra de César, aplicando a
codificação apenas às letras da mensagem, maiúsculas ou minúsculas, e preservando os demais
caracteres. Essa função deve receber como parâmetro uma cadeia de caracteres com a mensagem a ser
codificada e retornar uma nova cadeia de caracteres, alocada dinamicamente, com a mensagem Universidade Federal do Espírito Santo – Centro Tecnológico
Departamento de Informática
Prof. Vinícius Fernandes Soares Mota
codificada. A cadeia de caracteres original não pode ser alterada. A função deve ter o seguinte
protótipo: char* cifra_cesar (char* msg);
*/

#define tamStr 125

int ehLetra(char c)
{
    if (c >= 'A' && c <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Verificar se é letra é desnecessário
int ehMinuscula(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ehMaiuscula(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ultrapassaAlfabeto(char c, int rot)
{
    if (ehMaiuscula(c))
    {
        if (c + rot > 'Z')
        {
            return (c - 'Z' + rot);
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (c + rot > 'z')
        {
            return (c - 'z' + rot);
        }
        else
        {
            return -1;
        }
    }
}

char *cifra_cesar(char *msg, int rot)
{
    int i = 0, trocaAtual = 0;
    char *cesar;

    cesar = (char *)malloc(tamStr * sizeof(char));
    strcpy(cesar, msg);

    for (i = 0; i < strlen(msg); i++)
    {
        if (ehLetra(msg[i]))
        {
            trocaAtual = ultrapassaAlfabeto(msg[i], rot);
            if (trocaAtual != -1)
            {
                if (ehMaiuscula(msg[i]))
                {
                    cesar[i] = 'A' + trocaAtual - 1;
                }
                else
                {
                    cesar[i] = 'a' + trocaAtual - 1;
                }
            }
            else
            {
                cesar[i] = msg[i] + rot;
            }
        }
    }

    return cesar;
}

int main()
{
    int i = 0, rot = 3;
    char *s, *cesar;

    s = (char *)malloc(tamStr * sizeof(char));

    fgets(s, tamStr, stdin);
    printf("%s\n", s);

    cesar = cifra_cesar(s, rot);
    printf("%s\n", cesar);

    free(s);
    free(cesar);
}

/* Qual o custo de complexidade da sua função?
1 malloc
1 fgets
2 print
2 free

1 cifra_cesar
    1 malloc
    1 strcpy

    1 for do tamanho da mensagem (n)
        1 verificação pra cada letra da mensagem
        pra cada verificação 3 verificações
            para cada subverificação 1 verificação

O for percorre toda a string realizando verificações; assim, teremos um múltiplo de n operações, além de constantes.
Portanto, o custo de complexidade mais próximo que teremos será O(n).
*/
