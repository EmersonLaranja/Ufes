#include "listaDuplamenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listadpl
{
  Aluno *aluno;
  ListaDpl *proxima;
  ListaDpl *anterior;
};

ListaDpl *InicializaLista(void)
{
  return NULL;
}

// insere no inicio
ListaDpl *InsereLista(ListaDpl *lista, Aluno *aluno)
{
  ListaDpl *nova = (ListaDpl *)malloc(sizeof(ListaDpl));
  nova->aluno = aluno;
  nova->anterior = NULL;
  nova->proxima = lista;
  if (lista != NULL)
    lista->anterior = nova;
  return nova;
}
//private
static ListaDpl *busca(ListaDpl *lista, char *chave)
{
  for (ListaDpl *i = lista; i != NULL; i = i->proxima)
  {
    if (strcmp(chave, RetornaNome(i->aluno)) == 0)
      return i;
  }
  return NULL;
}

ListaDpl *RetiraLista(ListaDpl *lista, char *chave)
{
  ListaDpl *p = busca(lista, chave);
  //não encontrou ou lista vazia
  if (p == NULL)
    return lista;

  //se não for a primeira celula
  if (p->anterior != NULL)
    p->anterior->proxima = p->proxima;
  else
  {
    lista = p->proxima;
    //creio ser o mesmo que lista=lista->proxima
    lista->anterior = NULL;
  }

  //se não for a última celula
  if (p->proxima != NULL)
    p->proxima->anterior = p->anterior;
  else
  {
    p->anterior->proxima = NULL;
  }

  free(p);
  return lista;
}

void ImprimeLista(ListaDpl *lista)
{
  ListaDpl *p;

  for (p = lista; p != NULL; p = p->proxima)
  {
    ImprimeAluno(p->aluno);
  }
}

void DestroiLista(ListaDpl *lista)
{
  ListaDpl *p = lista;
  ListaDpl *t;

  while (p != NULL)
  {
    t = p->proxima;
    // DestroiAluno(p->aluno);
    free(p);
    p = t;
  }
}
