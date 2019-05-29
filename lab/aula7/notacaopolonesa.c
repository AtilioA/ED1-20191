#include "notacaopolonesa.h"

void add(tPilha *pilha)
{
    pilha->topo->prox->n = pilha->topo->n + pilha->topo->prox->n;
    pop(pilha);
}

void sub(tPilha *pilha)
{
    pilha->topo->prox->n = pilha->topo->n - pilha->topo->prox->n;
    pop(pilha);
}

void mult(tPilha *pilha)
{
    pilha->topo->prox->n = pilha->topo->n * pilha->topo->prox->n;
    pop(pilha);
}

int divi(tPilha *pilha)
{
    if (pilha->topo->prox->n != 0)
    {
        pilha->topo->prox->n = pilha->topo->n / pilha->topo->prox->n;
        pop(pilha);

        return 1;
    }

    return 0;
}
