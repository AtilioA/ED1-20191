#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreAVL.h"

<<<<<<< HEAD
int main(int argc, char *argv[ ]){
    int N;


   int total;
=======
int main(int argc, char* argv[]){
    int N;

    
   int total; 
>>>>>>> 57334bbf13082ea6a35250ed4d161b5d2814145b

    if(argc != 2){
   	 printf("Parametros incorretos. Use os parametros: "
   	 "<qtd de elementos a buscar>  \n");
   	 return -1;
  	}
<<<<<<< HEAD

    ArvAVL* raiz = cria_ArvAVL();

=======
    
    ArvAVL* raiz = cria_ArvAVL();
   
>>>>>>> 57334bbf13082ea6a35250ed4d161b5d2814145b
    int qtdBusca = atoi(argv[1]);

    int j=0;
    scanf("%d", &total);
    int *aux =  malloc(sizeof(int)*(total+1));

<<<<<<< HEAD
    clock_t t;
    t = clock();
=======
    clock_t t; 
    t = clock(); 
>>>>>>> 57334bbf13082ea6a35250ed4d161b5d2814145b
    while ( 1 == scanf("%d", &N)  ){
        aux[j]= N;
        j++;
        insere_ArvAVL(raiz,N);
<<<<<<< HEAD

   }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

=======
	
   }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
>>>>>>> 57334bbf13082ea6a35250ed4d161b5d2814145b

    printf("%f ", time_taken);

//    srand(time(0));
    srand(100);
<<<<<<< HEAD
    t = clock();
    for(j =0; j < qtdBusca; j++){
	consulta_ArvAVL(raiz,aux[rand() % total]);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("%f\n", time_taken);
    free(aux);
=======
    t = clock(); 
    for(j =0; j < qtdBusca; j++){
	consulta_ArvAVL(raiz,aux[rand() % total]);	
    }
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

    printf("%f\n", time_taken);
    free(aux);  
>>>>>>> 57334bbf13082ea6a35250ed4d161b5d2814145b
   libera_ArvAVL(raiz);
    return 0;

}
