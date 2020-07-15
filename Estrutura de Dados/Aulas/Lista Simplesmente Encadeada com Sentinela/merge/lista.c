#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
struct aluno
{
  char *nome;
  int matricula;
};

typedef struct celula Celula;

struct celula
{
  TAluno *aluno;
  Celula *prox;
};
/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */
struct lista
{
  Celula *inicio;
  Celula *fim;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista *CriaLista()
{
  TLista *lista = (TLista *)malloc(sizeof(TLista));
  lista->inicio = lista->fim = NULL;
  return lista;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno *InicializaAluno(char *nome, int matricula)
{
  TAluno *aluno = (TAluno *)malloc(sizeof(TAluno));
  aluno->matricula = matricula;
  aluno->nome = strdup(nome);
  return aluno;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno(TLista *lista, TAluno *aluno)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->aluno = aluno;
  nova->prox = lista->inicio;
  lista->inicio = nova;
  if (lista->fim == NULL)
  {
    lista->fim = nova;
    nova->prox = NULL;
  }
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno *Retira(TLista *lista, int mat)
{
  TAluno *alunoAux;
  Celula *aux = lista->inicio, *ant = NULL;

  while (aux != NULL && aux->aluno->matricula != mat)
  {
    ant = aux;
    aux = aux->prox;
  }

  if (aux == NULL)
  {
    return NULL;
  }

  alunoAux = aux->aluno;

  if (aux == lista->inicio && aux == lista->fim)
  {
    lista->inicio = lista->fim = NULL;
  }
  else if (aux == lista->inicio)
  {
    lista->inicio = aux->prox;
  }
  else if (aux == lista->fim)
  {
    ant->prox = NULL;
    lista->fim = ant;
  }
  else
  {
    ant->prox = aux->prox;
  }

  free(aux);
  return alunoAux;
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos(TLista *lista)
{
  int cont = 0;
  Celula *aux;
  for (Celula *i = lista->inicio; i != NULL;)
  {
    for (Celula *j = i; j != NULL; j = j->prox)
    {
      if (i->aluno->matricula == j->aluno->matricula)
      {
        cont++;
      }
    }
    if (cont > 1)
    {
      aux = i->prox;
      Retira(lista, i->aluno->matricula);
      i = aux;
    }
    else
    {
      i = i->prox;
    }
    cont = 0;
  }
}

/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista *Merge(TLista *turma1, TLista *turma2)
{
  Celula *i = turma1->inicio, *j = turma2->inicio, *aux;
  TLista *lista = (TLista *)malloc(sizeof(TLista));

  for (i, j; i != NULL && j != NULL;)
  {
    if (i != NULL)
    {
      InsereAluno(lista, i->aluno);
      aux = i;
      i = i->prox;
      Retira(turma1, aux->aluno->matricula);
    }

    if (j != NULL)
    {
      InsereAluno(lista, j->aluno);
      aux = j;
      j = j->prox;
      Retira(turma2, aux->aluno->matricula);
    }
  }

  turma1->inicio = turma1->fim = NULL;
  turma2->inicio = turma2->fim = NULL;

  return lista;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno(TAluno *aluno)
{
  if (aluno != NULL)
  {
    if (aluno->nome != NULL)
      free(aluno->nome);
    free(aluno);
  }
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime(TLista *lista)
{
  if (lista->inicio != NULL)
    for (Celula *i = lista->inicio; i != NULL; i = i->prox)
    {
      printf("NOME: %s, MATRICULA: %d\n", i->aluno->nome, i->aluno->matricula);
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista(TLista *lista)
{
  Celula *p = lista->inicio, *t;
  while (p != NULL)
  {
    t = p->prox;
    LiberaAluno(p->aluno);
    free(p);
    p = t;
  }
  free(lista);
}
