#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
struct tipoitem
{
  char *nome;
  int matricula;
  char *endereco;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista duplamente encadeada sem Sentinela
  */
struct tipolistadpl
{
  TipoItem *item;
  TipoListaDpl *anterior;
  TipoListaDpl *proxima;
};

/*Insere um aluno na primeira posição da lista duplamente encadeada de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: aluno e lista não são nulos
* pos-condicao: lista contém o aluno inserido na primeira posição
*/
TipoListaDpl *Insere(TipoItem *aluno, TipoListaDpl *lista)
{
  TipoListaDpl *nova = (TipoListaDpl *)malloc(sizeof(TipoListaDpl));
  nova->item = aluno;
  nova->anterior = NULL;
  nova->proxima = lista;
  if (lista != NULL)
    lista->anterior = nova;
  return nova;
}

/*
Função verifica se a chave passada corresponde a algum elemento da lista
* inputs: a chave e a lista
* output: retorna o elemento encontrado, ou null
* pre-condicao: lista não é nula
* pos-condicao: --
*/
static TipoListaDpl *Busca(TipoListaDpl *lista, char *nome)
{
  for (TipoListaDpl *i = lista; i != NULL; i = i->proxima)
  {
    if (strcmp(i->item->nome, nome) == 0)
    {
      return i; //encontrado
    }
  }
  return NULL; //não encontrado
}

/*Retira um aluno de nome "nome" da lista de alunos
* inputs: a lista e o nome do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o aluno de nome "nome"
*/
TipoListaDpl *Retira(TipoListaDpl *lista, char *nome)
{
  TipoListaDpl *res = Busca(lista, nome);
  if (res == NULL)
    return lista;

  if (res->anterior != NULL)
  {
    res->anterior->proxima = res->proxima;
  }
  else
  {
    lista = res->proxima;
  }

  if (res->proxima != NULL)
  {
    res->proxima->anterior = res->anterior;
  }
  else
  {
  }

  free(res->item->nome);
  free(res->item->endereco);
  free(res->item);
  free(res);
  return lista;
}

/*Imprime os dados de todos os alunos da lista duplamente encadeada
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime(TipoListaDpl *lista)
{
  for (TipoListaDpl *i = lista; i != NULL; i = i->proxima)
  {
    printf("NOME: %s, MATRICULA %d, ENDERECO:%s\n", i->item->nome, i->item->matricula, i->item->endereco);
  }
}

/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco)
{
  TipoItem *nova = (TipoItem *)malloc(sizeof(TipoItem));
  nova->nome = strdup(nome);
  nova->matricula = matricula;
  nova->endereco = strdup(endereco);
  return nova;
}

/*Libera toda a memória alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista duplamente encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl *libera(TipoListaDpl *lista)
{
  TipoListaDpl *p = lista, *t;

  while (p != NULL)
  {
    t = p->proxima;
    free(p->item->nome);
    free(p->item->endereco);
    free(p->item);
    free(p);
    p = t;
  }
  return NULL;
}
