#ifndef PILHA_H_
#define PILHA_H_

typedef struct pessoa
{
    char *nome;
    int idade;
    char *endereco;
} tPessoa;

typedef struct pilha
{
    int topo;
    tPessoa *stack[10];
} tPilha;

/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est� definida e vazia
*/
tPilha *criaPilha();

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(tPessoa *pessoa, tPilha *pilha);


/*Retira uma Pessoa do topo da Pilha (se pilha n�o vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
tPessoa *pop(tPilha *pilha);


void imprimePessoa(tPessoa *pessoa);
/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P n�o vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprimePilha(tPilha *pilha);


void liberaPessoa(tPessoa *pessoa);
/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
void destroiPilha(tPilha *pilha);

/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
tPessoa *inicializaPessoa(char* nome, int idade, char* endereco);


#endif /* PILHA_H_ */
