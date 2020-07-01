#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct celula
{
  char *fruta;
  Celula *proxima;
};

struct lista
{
  Celula *primeira;
  Celula *ultima;
};

Lista *InicializaLista(void)
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->primeira = NULL;
  lista->ultima = NULL;
  return lista;
}

void InsereInicioLista(Lista *lista, char *fruta)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->fruta = strdup(fruta);
  nova->proxima = lista->primeira;
  lista->primeira = nova;

  if (lista->ultima == NULL)
    lista->ultima = nova;
}

void InsereFimLista(Lista *lista, char *fruta)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->fruta = strdup(fruta);
  nova->proxima = NULL;

  if (lista->primeira == NULL)
  {
    lista->primeira = nova;
    lista->ultima = nova;
  }
  lista->ultima->proxima = nova;
  lista->ultima = nova;
}

void ImprimeLista(Lista *lista)
{
  for (Celula *nova = lista->primeira; nova != NULL; nova = nova->proxima)
    printf("|Fruta: %7s|\n", nova->fruta);
}

void OrdenaListaCrescente(Lista *lista)
{
  if (lista->primeira != NULL)
  {

    for (Celula *i = lista->primeira; i->proxima != NULL; i = i->proxima)
    {
      Celula *menor = i;
      for (Celula *j = i->proxima; j != NULL; j = j->proxima)
      {
        if (strcmp(j->fruta, menor->fruta) < 0)
        {
          menor = j;
        }
      }

      char *aux = i->fruta;
      i->fruta = menor->fruta;
      menor->fruta = aux;
    }
  }
}

void OrdenaListaDecrescente(Lista *lista)
{
  if (lista->primeira != NULL)
  {

    for (Celula *i = lista->primeira; i->proxima != NULL; i = i->proxima)
    {
      Celula *menor = i;
      for (Celula *j = i->proxima; j != NULL; j = j->proxima)
      {
        if (strcmp(j->fruta, menor->fruta) > 0)
        {
          menor = j;
        }
      }

      char *aux = i->fruta;
      i->fruta = menor->fruta;
      menor->fruta = aux;
    }
  }
}

void RemoveElementoLista(Lista *lista, char *fruta)
{
  Celula *auxiliar = lista->primeira;
  Celula *anterior = NULL;
  while (auxiliar != NULL && strcmp(fruta, auxiliar->fruta) != 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }
  //lista unica
  if (lista->primeira == auxiliar && lista->ultima == auxiliar)
  {
    // free(lista->primeira);
    lista->primeira = NULL;
    lista->ultima = NULL;
  }
  else if (lista->primeira == auxiliar)
  {
    // free(lista->primeira);
    lista->primeira = auxiliar->proxima;
  }
  else if (lista->ultima == auxiliar)
  {
    // free(lista->ultima);
    lista->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
    // free(auxiliar);
  }

  printf("\nELEMENTO REMOVIDO\n");
}

void RemoveLista(Lista *lista)
{
  for (Celula *i = lista->primeira; i != NULL; i = i->proxima)
  {
    free(i);
  }
  free(lista);
}

int QntCelulasNumaLista(Lista *lista)
{
  int qnt = 0;
  for (Celula *i = lista->primeira; i != NULL; i = i->proxima)
    qnt++;
  return qnt;
}

Lista *CopiaLista(Lista *listaOriginal)
{
  int contador = 0;

  Lista *listaCopia = InicializaLista();
  for (Celula *i = listaOriginal->primeira; i != NULL; i = i->proxima)
  {
    for (Celula *j = i->proxima; j != NULL; j = j->proxima)
    {
      if (strcmp(i->fruta, j->fruta) == 0)
        contador++;
    }
    if (contador == 0)
      InsereFimLista(listaCopia, i->fruta);
    contador = 0;
  }
  return listaCopia;
}

Lista *CopiaInversoLista(Lista *listaOriginal)
{
  int contador = 0;

  Lista *listaCopia = InicializaLista();
  for (Celula *i = listaOriginal->primeira; i != NULL; i = i->proxima)
  {
    for (Celula *j = i->proxima; j != NULL; j = j->proxima)
    {
      if (strcmp(i->fruta, j->fruta) == 0)
        contador++;
    }
    if (contador == 0)
      InsereInicioLista(listaCopia, i->fruta);
    contador = 0;
  }
  return listaCopia;
}

Lista *IntercalaListas(Lista *lista1, Lista *lista2)
{
  Lista *listaIntercalada = InicializaLista();
  Lista *auxiliar = InicializaLista();
  int qntLista1 = QntCelulasNumaLista(lista1);
  int qntLista2 = QntCelulasNumaLista(lista2);
  Celula *i1 = lista1->primeira;
  Celula *i2 = lista2->primeira;

  for (i1, i2; i1 != NULL && i2 != NULL; i1 = i1->proxima, i2 = i2->proxima)
  {

    InsereFimLista(auxiliar, i1->fruta);
    InsereFimLista(auxiliar, i2->fruta);
  }
  listaIntercalada = CopiaLista(auxiliar);
  OrdenaListaCrescente(listaIntercalada);
  RemoveLista(auxiliar);

  return listaIntercalada;
}
