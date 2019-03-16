/* 4) Faça um programa para associar nomes às linhas de uma matriz de caracteres. O usuário
irá informar o número máximo de nomes que poderão ser armazenados. Cada nome
poderá ter até 30 caracteres com o '\0'. O usuário poderá usar 5 opções diferentes para
manipular a matriz:
(a) Gravar um nome em uma linha da matriz;
(b) Apagar o nome contido em uma linha da matriz;
(c) Informar um nome, procurar a linha onde ele se encontra e substituir por outro
nome;
(d) Informar um nome, procurar a linha onde ele se encontra e apagar;
(e) Pedir para recuperar o nome contido em uma linha da matriz;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mallocaLinha(int colunas)
{
    char *linha;

    linha = (char *)malloc(colunas * sizeof(char));

    return linha;
}

char **mallocaMatriz(int linhas, int colunas)
{
    int i = 0;
    char **matriz;

    matriz = (char **)malloc(linhas * sizeof(char *));

    for (i = 0; i < linhas; i++)
    {
        matriz[i] = mallocaLinha(colunas);
    }

    return matriz;
}

void printaVetor(char *vetor, int tam)
{
    int i = 0;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

int procuraNomes(char **nomes, char *nomeBuscado, int maxNomes, int tamanhoNomes)
{
    int i = 0;

    for (i = 0; i < maxNomes; i++)
    {
        if (strcmp(nomeBuscado, nomes[i]) == 0)
        {
            return i;
        }
    }


    return -1;
}

// Para retirar lixo das linhas não inicializadas (sem nome)
void inicializaMat(char **matriz, int linhas, int tamanhoColunas)
{
    int jordana;

    for (jordana = 0; jordana < linhas; jordana++)
    {
        memset(matriz[jordana], 0, tamanhoColunas);
    }
}

// Função para gravar nome de uma linha
void gravaNomeLinha(char **nomes, int maxNomes, int tamanhoNomes)
{
    int linhaAlvo;

    printf("Escrever nome em qual linha? (Linha maxima: %i)\n", maxNomes);
    scanf("%i", &linhaAlvo);
    while (linhaAlvo <= 0 || linhaAlvo > maxNomes)
    {
        printf("Por favor, escolha uma linha entre 1 e %i. (Voce escolheu %i)\n", maxNomes, linhaAlvo);
        scanf("%i", &linhaAlvo);
    }

    printf("Informe o nome:\n");
    getchar();
    fgets(nomes[linhaAlvo - 1], tamanhoNomes, stdin);
}

// Função para apagar nome de uma linha
void apagaNomeLinha(char **nomes, int maxNomes, int tamanhoNomes)
{
    int linhaAlvo;

    printf("Escrever nome em qual linha? (Linha maxima: %i)\n", maxNomes);
    scanf("%i", &linhaAlvo);
    while (linhaAlvo <= 0 || linhaAlvo > maxNomes)
    {
        printf("Por favor, escolha uma linha entre 1 e %i. (Voce escolheu %i)\n", maxNomes, linhaAlvo);
        scanf("%i", &linhaAlvo);
    }

    memset(nomes[linhaAlvo - 1], 0, tamanhoNomes);
}

// Função para exibir nome de uma linha
void exibeNomeLinha(char **nomes, int maxNomes, int tamanhoNomes)
{
    int i = 0, linhaAlvo;

    printf("Escrever nome em qual linha? (Linha maxima: %i)\n", maxNomes);
    scanf("%i", &linhaAlvo);
    while (linhaAlvo <= 0 || linhaAlvo > maxNomes)
    {
        printf("Por favor, escolha uma linha entre 1 e %i. (Voce escolheu %i)\n", maxNomes, linhaAlvo);
        scanf("%i", &linhaAlvo);
    }

    printaVetor(nomes[linhaAlvo - 1], tamanhoNomes);
}

// Função para substituir nome procurando por ele
int buscaNomeSubstitui(char **nomes, int maxNomes, int tamanhoNomes)
{
    int posicaoNomeBuscado; // ou linhaAlvo
    char *nomeBuscado, *novoNome;

    nomeBuscado = (char *)malloc(tamanhoNomes * sizeof(char));

    getchar();
    printf("Informe o nome:\n");
    fgets(nomeBuscado, tamanhoNomes, stdin);

    posicaoNomeBuscado = procuraNomes(nomes, nomeBuscado, maxNomes, tamanhoNomes);

    if (posicaoNomeBuscado == -1) // Caso o nome não exista na matriz
    {
        return -1;
    }

    printf("Informe o novo nome:\n");
    fgets(nomes[posicaoNomeBuscado], 30, stdin);

    return 0;
}
// Função para apagar nome procurando por ele
int buscaNomeApaga(char **nomes, int maxNomes, int tamanhoNomes)
{
    int posicaoNomeBuscado; // ou linhaAlvo
    char *nomeBuscado;

    nomeBuscado = (char *)malloc(tamanhoNomes * sizeof(char));

    getchar();
    printf("Informe o nome:\n");
    fgets(nomeBuscado, tamanhoNomes, stdin);

    posicaoNomeBuscado = procuraNomes(nomes, nomeBuscado, maxNomes, tamanhoNomes);
    if (posicaoNomeBuscado == -1) // Caso o nome não exista na matriz
    {
        return -1;
    }
    memset(nomes[posicaoNomeBuscado], 0, tamanhoNomes);

    return 0;
}

void menuGaludao(char **nomes, int maxNomes, int tamanhoNomes)
{
    char op;

    do
    {
        printf("\n-- MATRIZ DE NOMES --\n");
        printf("------ OPCOES: ------\n\n");
        printf("[a] Gravar um nome em uma linha da matriz\n");
        printf("[b] Apagar o nome contido em uma linha da matriz\n");
        printf("[c] Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome\n");
        printf("[d] Informar um nome, procurar a linha onde ele se encontra e apagar\n");
        printf("[e] Pedir para recuperar o nome contido em uma linha da matriz\n");
        printf("[f] Sair\n");

        scanf(" %c", &op);

        switch (op)
        {
        case 'a':
            gravaNomeLinha(nomes, maxNomes, tamanhoNomes);
            break;

        case 'b':
            apagaNomeLinha(nomes, maxNomes, tamanhoNomes);
            break;

        case 'c':
            buscaNomeSubstitui(nomes, maxNomes, tamanhoNomes);
            break;

        case 'd':
            buscaNomeApaga(nomes, maxNomes, tamanhoNomes);
            break;

        case 'e':
            exibeNomeLinha(nomes, maxNomes, tamanhoNomes);
            break;

        case 'f': // Para não dar erro no 'do while'
            break;

        default:
            printf("Entrada invalida (%c)! Tente novamente.\n", op);
        }

    } while (op != 'f');
}

int main()
{
    int i = 0, maxNomes, tamanhoNomes = 30; // "Cada nome poderá ter até 30 caracteres"
    char **nomes;

    printf("Informe o numero maximo de nomes na matriz: ");
    scanf("%i", &maxNomes);

    nomes = mallocaMatriz(maxNomes, tamanhoNomes);
    inicializaMat(nomes, maxNomes, tamanhoNomes);

    menuGaludao(nomes, maxNomes, tamanhoNomes);

    for (i = 0; i < maxNomes; i++)
    {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
