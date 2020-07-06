#ifndef LISTA_H_
#define LISTA_H_

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
typedef struct tipoitem TipoItem;

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista COM Sentinela
  */
typedef struct celula Celula;
typedef struct tipolista TipoLista;

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
TipoLista *InicializaLista();

/*Insere um aluno na primeira posição da lista de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: aluno e lista não são nulos
* pos-condicao: lista contém o aluno inserido na primeira posição
*/
void Insere(TipoItem *aluno, TipoLista *lista);

/*Retira um aluno de matrícula mat da lista de alunos
* inputs: a lista e a matrícula do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o aluno de matrícula mat
*/
TipoItem *Retira(TipoLista *lista, int mat);

/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime(TipoLista *lista);

/*Libera toda a memória alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoLista *Libera(TipoLista *lista);

/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco);

void *DeletaTipoItem(TipoItem *item);

#endif /* LISTA_H_ */