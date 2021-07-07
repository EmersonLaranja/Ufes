#include "josefo.h"

struct celula
{
  int num;
  Celula *prox;
};

struct listaCircular
{ //sentinela
  Celula *prim;
  Celula *ult;
};

ListaCircular *CriaLista(void)
{
  ListaCircular *lista = (ListaCircular *)malloc(sizeof(ListaCircular));

  lista->prim = NULL;

  return lista;
}

void InsereElementosFinalLista(ListaCircular *lista, int qntElementos)
{
  Celula *nova;
  for (int i = 0; i < qntElementos; i++)
  {
    nova = malloc(sizeof(Celula));
    nova->num = (i + 1);

    if (lista->prim == NULL)
    {
      lista->prim = nova;
      lista->ult = nova;
    }
    lista->ult->prox = nova;
    lista->ult = nova;

    nova->prox = NULL;
  }

  lista->ult->prox = lista->prim;
}

ListaCircular *RemoveElementoLista(int elemento)
{
}