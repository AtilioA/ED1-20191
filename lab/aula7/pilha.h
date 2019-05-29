#ifndef PILHA_H_
#define PILHA_H_

typedef struct celula
{
    float n;
    struct celula *prox;
} tCelula;

typedef struct pilha
{
    tCelula *topo;
    int qtd;
} tPilha;

tCelula *criaCelula(float n);
tPilha *criaPilha();
float getN(tCelula *celula);

int push(tCelula *celula, tPilha *pilha);
tCelula *pop(tPilha *pilha);

void imprimeCelula(tCelula *celula);
void imprimePilha(tPilha *pilha);

int liberaCelula(tCelula *celula);
int destroiPilha(tPilha *pilha);

#endif /* PILHA_H_ */
