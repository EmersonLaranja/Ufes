#include "listaDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
{
  Aluno *aluno;
  struct celula *proxima;
  struct celula *anterior;
} Celula;

struct listadpl
{

  Celula *inicio;
  Celula *fim;
};

ListaDpl *InicializaLista(void)
{
  ListaDpl *lista = (ListaDpl *)malloc(sizeof(ListaDpl));
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}

// insere no inicio
void *InsereLista(ListaDpl *lista, Aluno *aluno)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->aluno = aluno;
  nova->anterior = NULL;
  if (lista->inicio == NULL)
  {
    nova->proxima = NULL;
    lista->inicio = nova;
    lista->fim = nova;
  }
  else
  {
    nova->proxima = lista->inicio;
    lista->inicio->anterior = nova;
    lista->inicio = nova;
  }
}
// private
static Celula *busca(ListaDpl *lista, char *chave)
{
  for (Celula *i = lista->inicio; i != NULL; i = i->proxima)
  {
    if (strcmp(chave, RetornaNome(i->aluno)) == 0)
      return i;
  }
  return NULL;
}

void *RetiraLista(ListaDpl *lista, char *chave)
{
  Celula *p = busca(lista, chave);
  //não encontrou ou lista vazia
  if (p == NULL)
    return NULL;

  if (p == lista->inicio && p == lista->fim)
  {
    lista->inicio = NULL;
    lista->fim = NULL;
  }
  //se  for a primeira celula
  else if (p == lista->inicio)
  {
    p->proxima->anterior = NULL;
    lista->inicio = p->proxima;
  }
  else if (p == lista->fim)
  {
    p->anterior->proxima = NULL;
    lista->fim = p->anterior;
  }
  else
  {
    p->anterior->proxima = p->proxima;
    p->proxima->anterior = p->anterior;
  }

  free(p);
}

void ImprimeLista(ListaDpl *lista)
{

  for (Celula *p = lista->inicio; p != NULL; p = p->proxima)
  {
    ImprimeAluno(p->aluno);
  }
}

void DestroiLista(ListaDpl *lista)
{
  Celula *p = lista->inicio;
  Celula *t;

  while (p != NULL)
  {
    t = p->proxima;
    // DestroiAluno(p->aluno);
    free(p);
    p = t;
  }
  free(lista);
}
