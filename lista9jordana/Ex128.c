/* 5) Em uma cidade do interior, sabe-se que de janeiro a abril de 1990 (121 dias) não ocorreu
temperatura inferior a 15.5 graus centígrados nem superior a 39.7 graus centígrados. Considere
um arquivo texto (denominado “questao5.txt”) que contém todas as temperaturas ocorridas
nestes 121 dias (uma temperatura por linha). Faça um programa que calcule e apresente:
• a menor temperatura ocorrida;
• a maior temperatura ocorrida;
• a temperatura média;
• número de dias nos quais a temperatura foi inferior à temperatura média;
• número de dias nos quais a temperatura foi superior à temperatura média. */

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

float somaElementosVet(float *v, int tam)
{
    int i;
    float soma = 0;

    for (i = 0; i < tam; i++)
    {
        soma += v[i];
    }

    return soma;
}

float mediaVet(float *v, int tam)
{
    int i;
    float media, soma;

    soma = somaElementosVet(v, tam);

    media = soma / tam;

    return media;
}

float menorVet(float *v, int tam)
{
    int i;
    float menor;

    menor = v[0];

    for (i = 0; i < tam; i++)
    {
        if (v[i] < menor)
        {
            menor = v[i];
        }
    }

    return menor;
}

float maiorVet(float *v, int tam)
{
    int i;
    float maior;

    maior = v[0];

    for (i = 0; i < tam; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
        }
    }

    return maior;
}

float *abaixoMedia(float *v, float media, int *nAbaixo, int tam)
{
    int i, k = 0;
    float *abaixoMedia;
    abaixoMedia = (float *)malloc(sizeof(float));

    for (i = 0; i < tam; i++)
    {
        if (v[i] < media)
        {
            abaixoMedia[k] = v[i];
            k++;
            abaixoMedia = realloc(abaixoMedia, (k + 1) * sizeof(float));
        }
    }

    *nAbaixo = k;

    return abaixoMedia;
}

float *acimaMedia(float *v, float media, int *nAcima, int tam)
{
    int i, k = 0;
    float *acimaMedia;
    acimaMedia = (float *)malloc(sizeof(float));

    for (i = 0; i < tam; i++)
    {
        if (v[i] > media)
        {
            acimaMedia[k] = v[i];
            k++;
            acimaMedia = realloc(acimaMedia, (k + 1) * sizeof(float));
        }
    }

    *nAcima = k;

    return acimaMedia;
}

float *leTemp(FILE *ftemps, int *tam)
{
    int i, pos = 0;
    float *tempVet;
    tempVet = (float *)malloc(sizeof(float));

    while (!feof(ftemps))
    {
        fscanf(ftemps, "%f", &tempVet[pos]);
        pos++;
        tempVet = realloc(tempVet, (pos + 1) * sizeof(float));
    }

    *tam = pos;

    return tempVet;
}

int main()
{
    FILE *ftemps;
    int i, nAbaixo, nAcima, tam;
    float *tempVet, mediaTemp, menorTemp, maiorTemp, *abaixoMediaVet, *acimaMediaVet;

    // abaixoMediaVet = (float *)malloc(sizeof(float));
    // acimaMediaVet = (float *)malloc(sizeof(float));
    // tempVet = (float *)malloc(sizeof(float));

    ftemps = fopen("questao5.txt", "r");
    tempVet = leTemp(ftemps, &tam);

    mediaTemp = mediaVet(tempVet, tam);
    menorTemp = menorVet(tempVet, tam);
    maiorTemp = maiorVet(tempVet, tam);
    abaixoMediaVet = abaixoMedia(tempVet, mediaTemp, &nAbaixo, tam);
    acimaMediaVet = acimaMedia(tempVet, mediaTemp, &nAcima, tam);

    printf("Menor temperatura: %.2f\n", menorTemp);
    printf("Maior temperatura: %.2f\n", maiorTemp);
    printf("Temperatura media: %.2f\n", mediaTemp);
    printf("Numero de dias com temperaturas abaixo da media: %i\n", nAbaixo);
    printf("Numero de dias com temperaturas acima da media: %i\n", nAcima);
    printf("\nTemperaturas abaixo da media:");
    printaVet(abaixoMediaVet, nAbaixo);
    printf("\nTemperaturas acima da media:");
    printaVet(acimaMediaVet, nAcima);

    free(tempVet);
    free(abaixoMediaVet);
    free(acimaMediaVet);
    fclose(ftemps);

    return 0;
}
