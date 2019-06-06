#ifndef PILHA_H_
#define PILHA_H_

typedef struct pessoa
{
    char *nome;
    char *end;
    int idade;
} tPessoa;

typedef struct celula
{
    tPessoa pessoa;
    struct celula *prox;
} tCelula;

typedef struct pilha
{
    tCelula *topo;
    int qtd;
} tPilha;

/*Inicializa a tPilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P est definida e vazia
*/
tPilha *criaPilha(); // OK

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da fun��o, a pilha tem E como o elemento
do topo
*/
void push(tCelula *celula, tPilha *pilha); // OK

/*Retira uma Celuloide amem sem or do topo da tPilha (se pilha n�o vazia)
* inputs: a tPilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: tPilha n�o � nula e n�o � vazia
* pos-condicao: pilha n�o cont�m o elemento retirado do topo
*/
tCelula *pop(tPilha *pilha); // OK

void destroiCelula(tCelula *celula);
void destroiPessoa(tPessoa *pessoa);

/*Libera a memoria ocupada pela pilha
* inputs: a tPilha
* output: NULL
* pre-condicao: tPilha n�o � nula
* pos-condicao: Toda memoria eh liberada
*/
tPilha *destroiPilha(tPilha *pilha); // OK

/*Verifica se a pilha estah vazia
* inputs: a tPilha
* output: 1 (se vazia), 0 (caso contrario)
* pre-condicao: tPilha n�o � nula
* pos-condicao: tPilha permanece inalterada
*/
int vaziaPilha(tPilha *pilha); // OK

/*Retorna o numero de elementos da pilha
* inputs: a tPilha
* output: o numero de elementos da pilha
* pre-condicao: tPilha n�o � nula
* pos-condicao: tPilha permanece inalterada
*/
int tamanhoPilha(tPilha *pilha); // OK

/*Inicializa um TipoItem tPessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
tPessoa *inicializaPessoa(char *nome, int idade, char *endereco); //OK

/*Imprime as pessoas da pilha
* inputs: a pilha
* output: nenhum
* pre-condicao: pilha P n�o vazia
* pos-condicao: tPilha permanece inalterada
*/
void imprimePilha(tPilha *pilha); // OK

/*Imprime os dados de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: tPessoa P n�o nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
void imprimePessoa(tPessoa *p); // OK

/*Retorna a idade de uma pessoa
* inputs: Uma estrutura pessoa
* output: nenhum
* pre-condicao: tPessoa P n�o nula
* pos-condicao: Os dados da pessoa permanecem inalterados
*/
int retornaIdade(tPessoa *p); // OK

#endif /* PILHA_H_ */
