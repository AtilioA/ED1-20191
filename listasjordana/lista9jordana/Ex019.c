/* 5) Em uma cidade do interior, sabe-se que de janeiro a abril de 1990 (121 dias) não ocorreu
temperatura inferior a 15.5 graus centígrados nem superior a 39.7 graus centígrados. Considere
um arquivo texto (denominado “questao5.txt”) que contém todas as temperaturas ocorridas
nestes 121 dias (uma temperatura por linha). Faça um programa que calcule e apresente:
• a menor temperatura ocorrida;
• a maior temperatura ocorrida;
• a temperatura média;
• número de dias nos quais a temperatura foi inferior à temperatura média;
• número de dias nos quais a temperatura foi superior à temperatura média.
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

float menorVet(float *vetor, int tam)
{
    int i = 0, menor = vetor[0];

    for (i = 1; i < tam; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    return menor;
}

float maiorVet(float *vetor, int tam)
{
    int i = 0, maior = vetor[0];

    for (i = 1; i < tam; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }

    return maior;
}

int temperaturaAbaixoMedia(float *temperaturas, float media, int tam)
{
    int i = 0, nDiasAbaixo = 0;

    for (i = 0; i < tam; i++)
    {
        if (temperaturas[i] < media)
        {
            nDiasAbaixo++;
        }
    }

    return nDiasAbaixo;
}

int temperaturaAcimaMedia(float *temperaturas, float media, int tam)
{
    int i = 0, nDiasAcima = 0;

    for (i = 0; i < tam; i++)
    {
        if (temperaturas[i] > media)
        {
            nDiasAcima++;
        }
    }

    return nDiasAcima;
}

float mediaVet(float *vetor, int tam)
{
    int i = 0;
    float soma = 0, media = 0;

    for (i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }

    media = soma / tam;

    return media;
}

float *leArquivo(FILE *ftemps, int *tam)
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
    int nDias = 0, nDiasAcimaMedia, nDiasAbaixoMedia;
    float *temperaturas, mediaTemperaturas, maiorTemperatura, menorTemperatura;
    FILE *fTemps;

    fTemps = fopen("questao5.txt", "r");
    temperaturas = leArquivo(fTemps, &nDias);

    maiorTemperatura = maiorVet(temperaturas, nDias);
    menorTemperatura = menorVet(temperaturas, nDias);
    mediaTemperaturas = mediaVet(temperaturas, nDias);
    nDiasAcimaMedia = temperaturaAcimaMedia(temperaturas, mediaTemperaturas, nDias);
    nDiasAbaixoMedia = temperaturaAbaixoMedia(temperaturas, mediaTemperaturas, nDias);

    printf("Temperaturas:\n");
    printaVet(temperaturas, nDias);

    printf("\nMaior temperatura: %g\n", maiorTemperatura);
    printf("Menor temperatura: %g\n", menorTemperatura);
    printf("Media das temperaturas: %g\n", mediaTemperaturas);
    printf("Numero de dias com temperatura acima da media: %i\n", nDiasAcimaMedia);
    printf("Numero de dias com temperatura abaixo da media: %i\n", nDiasAbaixoMedia);

    fclose(fTemps);
    free(temperaturas);
}
