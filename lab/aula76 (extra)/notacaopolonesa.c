#include "pilha.h"
#include "notacaopolonesa.h"

void add(tPilha *pilha)
{
    soma = pilha[getTopo(pilha)] + pilha[getTopo(pilha) - 1];
    popBolado(pilha);
    pilha[topo] = soma;
}
