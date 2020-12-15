#include "listaGenerica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct listagenerica
{
  void *item;
  ListaGenerica *prox;
};

ListaGenerica *CriaLista()
{
  return NULL;
}

ListaGenerica *InsereLista(ListaGenerica *lista, void *item)
{
  ListaGenerica *nova = (ListaGenerica *)malloc(sizeof(ListaGenerica));
  nova->item = item;
  nova->prox = lista;

  return nova;
}
ListaGenerica *RetiraLista(ListaGenerica *lista, int (*cb)(void *, void *), void *chave)
{
  ListaGenerica *p = lista;
  ListaGenerica *ant = NULL;

  while (p != NULL && cb(p->item, chave))
  {
    ant = p;
    p = p->prox;
  }

  //Vazia
  if (p == NULL)
  {
    return lista;
  }

  //Primeira
  if (ant == NULL)
  {
    lista = lista->prox;
  }
  else
  {
    ant->prox = p->prox;
  }

  free(p);
  return lista;
}

int PercorreLista(ListaGenerica *lista, int (*cb)(void *, void *), void *dado)
{
  ListaGenerica *p;

  for (p = lista; p != NULL; p = p->prox)
  {
    int r = cb(p->item, dado);
    if (r == 0)
    {
      return r;
    }
  }
  return 1;
}
void LiberaLista(ListaGenerica *lista)
{
  ListaGenerica *p = lista;
  ListaGenerica *t;

  while (p != NULL)
  {
    t = p->prox;
    free(p);
    p = t;
  }
}