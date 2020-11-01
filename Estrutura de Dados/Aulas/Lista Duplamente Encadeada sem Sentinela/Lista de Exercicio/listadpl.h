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
  Usar lista duplamente encadeada sem Sentinela
  */
typedef struct tipolistadpl TipoListaDpl;

/*Insere um aluno na primeira posição da lista duplamente encadeada de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: aluno e lista não são nulos
* pos-condicao: lista contém o aluno inserido na primeira posição
*/
TipoListaDpl *Insere(TipoItem *aluno, TipoListaDpl *lista);

/*Retira um aluno de nome "nome" da lista de alunos
* inputs: a lista e o nome do aluno a ser retirado da lista
* output: lista sem o aluno
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o aluno de nome "nome"
*/
TipoListaDpl *Retira(TipoListaDpl *lista, char *nome);

/*Imprime os dados de todos os alunos da lista duplamente encadeada
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime(TipoListaDpl *lista);

/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco);

/*Libera toda a memória alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista duplamente encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl *libera(TipoListaDpl *lista);

#endif /* LISTA_H_ */