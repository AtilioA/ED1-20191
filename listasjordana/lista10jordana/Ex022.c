/* 2) Crie  uma  estrutura  representando  os  alunos  do  curso  de Programação  II.
A  estrutura  deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
//(a) Permita ao usuário entrar com os dados de *n* alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral.
//(e)  Para  cada  aluno  diga  se  ele  foi  aprovado  ou  reprovado,  considerando  o  valor 7.0 para aprovação. */

#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char nome[50];
    int matricula;
    float p1;
    float p2;
    float p3;
    float media;
    char aprovado;
};
typedef struct Aluno Aluno;

void printaAluno(Aluno *aluno)
{
    printf("\nNome: %s", (*aluno).nome);
    printf("Matricula: %i\n", (*aluno).matricula);
    printf("Nota da P1: %g\n", (*aluno).p1);
    printf("Nota da P2: %g\n", (*aluno).p2);
    printf("Nota da P3: %g\n", (*aluno).p3);
    printf("Media: %g\n", (*aluno).media);
    printf("Aprovado? %c\n", (*aluno).aprovado);
}

void printaAlunos(Aluno *alunos, int nAlunos)
{
    int i;

    for (i = 0; i < nAlunos; i++)
    {
        printaAluno(&alunos[i]);
    }
}

int foiAprovado(Aluno aluno)
{
    if (aluno.media > 7)
    {
        return 1;
    }

    return 0;
}

void alunosAprovados(Aluno *alunos, int nAlunos)
{
    int i = 0;

    for (i = 0; i < nAlunos; i++)
    {
        if (foiAprovado(alunos[i]) == 1)
        {
            alunos[i].aprovado = 'S';
        }
        else
        {
            alunos[i].aprovado = 'N';
        }
    }
}

float mediaAluno(Aluno aluno)
{
    float media;
    media = (aluno.p1 + aluno.p2 + aluno.p3) / 3;

    return media;
}

Aluno leAluno()
{
    Aluno aluno;

    printf("Informe o nome: ");
    getchar();
    fgets(aluno.nome, 50, stdin);
    printf("Informe a matricula: ");
    scanf("%i", &aluno.matricula);
    printf("Informe a nota da P1: ");
    scanf("%f", &aluno.p1);
    printf("Informe a nota da P2: ");
    scanf("%f", &aluno.p2);
    printf("Informe a nota da P3: ");
    scanf("%f", &aluno.p3);

    aluno.media = mediaAluno(aluno);

    return aluno;
}

Aluno leAlunos(Aluno *alunos, int nAlunos)
{
    int i = 0;

    for (i = 0; i < nAlunos; i++)
    {
        alunos[i] = leAluno();
    }
}

int main()
{
    Aluno *alunos;
    int nAlunos;

    printf("Informe a quantidade de alunos: ");
    scanf("%i", &nAlunos);

    alunos = (Aluno *)malloc(nAlunos * sizeof(Aluno));

    leAlunos(alunos, nAlunos);
    alunosAprovados(alunos, nAlunos);
    printaAlunos(alunos, nAlunos);


    free(alunos);
    return 0;
}
