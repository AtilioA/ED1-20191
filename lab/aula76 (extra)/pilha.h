#ifndef PILHA_H_
#define PILHA_H_

typedef struct celula
{
    float n;
    tCelula *prox;
} tCelula;

typedef struct pilha
{
    tCelula topo;
    int qtd;
} tPilha;

tPilha *criaPilha();

void push(tCelula *celula, tPilha *pilha);

tCelula *pop(tPilha *pilha);

void imprimePessoa(tCelula *celula);
void imprimePilha(tPilha *pilha);

void liberaPessoa(tCelula *celula);
void destroiPilha(tPilha *pilha);

tCelula *inicializaPessoa(char* nome, int idade, char* endereco);

#endif /* PILHA_H_ */
