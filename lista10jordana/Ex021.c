/* 1) Considerando a estrutura
struct Vetor{
    float x;
    float y;
    float z;
    };
    para representar um vetor no R3, implemente um programa que calcule a soma de dois vetores e imprima o resultado.
*/

#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    float x;
    float y;
    float z;
};
typedef struct Vetor Vetor;

void printaVetR3(Vetor vet)
{
    printf("x: %g\n", vet.x);
    printf("y: %g\n", vet.y);
    printf("z: %g\n", vet.z);
}

Vetor leVetR3()
{
    Vetor vet;

    printf("Informe x: ");
    scanf("%f", &vet.x);

    printf("Informe y: ");
    scanf("%f", &vet.y);

    printf("Informe z: ");
    scanf("%f", &vet.z);

    return vet;
}

Vetor somaVetR3(Vetor v1, Vetor v2)
{
    Vetor vSoma;

    vSoma.x = v1.x + v2.x;
    vSoma.y = v1.y + v2.y;
    vSoma.z = v1.z + v2.z;

    return vSoma;
}

int main()
{
    Vetor v1, v2, v3;

    printf("Vetor 1:\n");
    v1 = leVetR3();
    printf("Vetor 2:\n");
    v2 = leVetR3();

    printf("Resultado da soma:\n");
    v3 = somaVetR3(v1, v2);
    printaVetR3(v3);

    return 0;
}
