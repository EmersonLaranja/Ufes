#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct lista
{
  Celula *inicio;
  Celula *fim;
};

TLista *CriaLista()
{
  TLista *lista = (TLista *)malloc(sizeof(TLista));
  lista->inicio = lista->fim = NULL;
  return lista;
}

TAluno *InicializaAluno(char *nome, int matricula)
{
  TAluno *aluno = (TAluno *)malloc(sizeof(TAluno));
  aluno->matricula = matricula;
  aluno->nome = strdup(nome);
  return aluno;
}

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

TAluno *Retira(TLista *lista, int mat)
{
  TAluno *alunoAux = NULL;
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

TLista *Merge(TLista *turma1, TLista *turma2)
{
  Celula *i = turma1->inicio, *j = turma2->inicio, *aux;
  TLista *lista = CriaLista();

  while (i != NULL && j != NULL)
  {
    InsereAluno(lista, i->aluno);
    aux = i;
    i = i->prox;
    Retira(turma1, aux->aluno->matricula);
    InsereAluno(lista, j->aluno);
    aux = j;
    j = j->prox;
    Retira(turma2, aux->aluno->matricula);
  }

  if (i != NULL)
  {
    while (i != NULL)
    {

      InsereAluno(lista, i->aluno);
      aux = i;
      i = i->prox;
      Retira(turma1, aux->aluno->matricula);
    }
  }
  if (j != NULL)
  {
    while (j != NULL)
    {

      InsereAluno(lista, j->aluno);
      aux = j;
      j = j->prox;
      Retira(turma2, aux->aluno->matricula);
    }
  }
  return lista;
}

void LiberaAluno(TAluno *aluno)
{
  if (aluno != NULL)
  {
    if (aluno->nome != NULL)
      free(aluno->nome);
    free(aluno);
  }
}

void Imprime(TLista *lista)
{
  if (lista->inicio != NULL)
    for (Celula *i = lista->inicio; i != NULL; i = i->prox)
    {
      printf("NOME: %s, MATRICULA: %d\n", i->aluno->nome, i->aluno->matricula);
    }
}

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
