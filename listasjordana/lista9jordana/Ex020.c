/* 6) Faça um programa que apure o resultado de uma eleição que possua, 100 eleitores. Suponha
que existam 5 candidatos cujos códigos de identificação são: 1, 2, 3, 4, 5. Considere um arquivo
texto (denominado “votos.txt”) que contém, em cada linha, um determinado voto (um voto é
representado pelo código de identificação do candidato).
O programa deverá apresentar, como resultado, o código de identificação e a quantidade de
votos do candidato mais votado, o código de identificação e a quantidade de votos do candidato
menos votado e a quantidade de votos nulos (um voto nulo é um voto cujo código de
identificação é inválido)
*/

#include <stdio.h>
#include <stdlib.h>

void printaVet(float *v, int tam)
{
    int i;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");
}

int *leVotos(FILE *fVotos, int *votos, int *tam)
{
    int pos = 0;
    int *votos;
    votosVet = (float *)malloc(sizeof(float));

    while(!feof(fVotos))
    {
        fscanf(fVotos, "%i", votosVet[pos]);
        pos++;
        votosVet = (int *)malloc((pos + 1) * sizeof(int));
    }

    *tam = pos;

    return votosVet;
}

int main()
{
    FILE *fVotos;
    int *candidatos, *votos, nVotos = 0;

    candidatos = (int *)malloc(5 * sizeof(int));

    fVotos = fopen("votos.txt", "r");

    votos = leVotos(votos, &nVotos);

    fclose(fVotos);
}
