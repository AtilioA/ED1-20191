
/*
Baseado na implementa��o do livro Projeto de Algoritmos
Modifica��es: VM
========================================================================== */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX 10
/* ========================================================================== */


int main(int argc, char *argv[])
{ struct timeval t;

  tLista lista;
  tItem item;
  int vetor[MAX];
  tCelula *p;
  int i, j, k, n;
  float  tamanho=0;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  FLVazia(&lista);


  /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
  for(i = 0; i < MAX; i++) vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
    { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*insere cada chave na lista */
  for (i = 0; i < MAX; i++)
    { item.chave = vetor[i];
      insere(item, &lista);
      tamanho++;
      printf("Inseriu: %d \n", item.chave);
    }
  imprime(lista);

  /*Retira cada chave da lista */
  for(i = 0; i < MAX - 1; i++)
    { /*escolhe uma chave aleatoriamente */
      k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
      p = lista.primeiro;
      /*retira chave apontada */
      retira(p, &lista, &item);
      tamanho--;
      printf("Retirou: %d\n", item.chave);
    }
  imprime (lista);
  destroiLista(&lista);
  return(0);
}
