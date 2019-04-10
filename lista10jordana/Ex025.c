/* 5) Faça um programa que leia um inteiro N e:
• Crie e leia um vetor com os dados de N carros: marca (máximo 15 letras), ano e preço.
• Leia um valor P e mostre as informações de todos os carros com preço menor que P. Repita este processo atéque seja lido um valor P = 0
*/

#include <stdio.h>
#include <stdlib.h>

struct carro
{
    char marca[15];
    int ano;
    float preco;
};
typedef struct carro tCarro;

void printaCarro(tCarro carro)
{
    printf("Marca do carro: %s\n", carro.marca);
    printf("Ano do carro: %i\n", carro.ano);
    printf("Preco do carro: %f\n\n", carro.preco);
}

void printaCarros(tCarro *carros, int nCarros)
{
    int i = 0;

    for (i = 0; i < nCarros; i++)
    {
        printf("%io carro:\n", i + 1);
        printaCarro(carros[i]);
    }
}

tCarro leCarro()
{
    tCarro carro;

    printf("Informe a marca do carro: ");
    getchar();
    fgets(carro.marca, 15, stdin);
    printf("Informe o ano do carro: ");
    scanf("%i", &carro.ano);
    printf("Informe o preco do carro: ");
    scanf("%f", &carro.preco);

    return carro;
}

tCarro *leCarros(int nCarros)
{
    tCarro *carros;
    int i = 0;

    carros = (tCarro *)malloc(nCarros * sizeof(tCarro));

    for (i = 0; i < nCarros; i++)
    {
        printf("%io carro:\n", i + 1);
        carros[i] = leCarro();
    }

    return carros;
}

tCarro *carrosPrecoMenorP(tCarro *carros, int nCarros, int *nCarrosBaratos, float preco)
{
    tCarro *carrosMaisBaratosP;
    int i, k = 0;

    for (i = 0; i < nCarros; i++)
    {
        if (carros[i].preco < preco)
        {
            carrosMaisBaratosP = (tCarro *)malloc((k + 1) * sizeof(tCarro));
            carrosMaisBaratosP[k] = carros[i];
            k++;
        }
    }

    *nCarrosBaratos = k;

    return carrosMaisBaratosP;
}


void main()
{
    int nCarros = 0, nCarrosBaratos = 0;
    float preco;
    tCarro *carros, *carrosMaisBaratosP;

    printf("Informe o numero de carros: ");
    scanf("%i", &nCarros);

    carros = leCarros(nCarros);

    printf("Informe um preco para buscar na lista de carros: ");
    scanf("%f", &preco);
    do
    {
        carrosMaisBaratosP = carrosPrecoMenorP(carros, nCarros, &nCarrosBaratos, preco);
        printaCarros(carrosMaisBaratosP, nCarrosBaratos);
        printf("Informe outro preco para buscar na lista de carros: ");
        scanf("%f", &preco);
    } while (preco != 0);


    free(carros);
    free(carrosMaisBaratosP);
}
