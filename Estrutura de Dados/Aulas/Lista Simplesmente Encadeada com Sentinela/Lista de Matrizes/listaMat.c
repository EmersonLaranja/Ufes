/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula
{
  Matriz *matriz;
  Celula *proxima;
};

struct lista
{
  Celula *primeira;
  Celula *ultima;
};

Lista *IniciaLista(void)
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->primeira = NULL;
  lista->ultima = NULL;

  return lista;
}

void ImprimeLista(Lista *lista)
{
  Celula *auxiliar;
  if (!lista)
  {
    printf("Lista vazia");
    exit(1);
  }
  for (auxiliar = lista->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    ImprimeMatriz(auxiliar->matriz);
    printf("\n");
  }
}

//inserindo elementos no inicio
void InsereLista(Lista *lista, Matriz *matriz)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->matriz = matriz;
  nova->proxima = lista->primeira;
  lista->primeira = nova;

  if (lista->ultima == NULL)
    lista->ultima = nova;
}

Matriz *RetiraLista(Lista *lista, int posicao)
{
  Celula *celulaAuxiliar = lista->primeira;
  Matriz *matrizAuxiliar;
  Celula *anterior = NULL;

  //faz a busca
  int i = 0;
  while (celulaAuxiliar != NULL && i != posicao)
  {
    anterior = celulaAuxiliar;
    celulaAuxiliar = celulaAuxiliar->proxima;
    i++;
  }

  //lista vazia ou não encontrou o matriz
  if (celulaAuxiliar == NULL)
    return NULL;

  //atribui o matriz de retorno
  matrizAuxiliar = celulaAuxiliar->matriz;

  //se for uma unica celula
  if (lista->primeira == celulaAuxiliar && lista->ultima == celulaAuxiliar)
  { //lista vazia
    lista->primeira =
        lista->ultima =
            NULL;
  }
  else if (lista->primeira == celulaAuxiliar)
  {
    lista->primeira = celulaAuxiliar->proxima; //se for o primeiro
  }
  else if (lista->ultima == celulaAuxiliar)
  { //se for o ultimo
    lista->ultima = anterior;
    lista->ultima->proxima = NULL; //poderia ser anterior->proxima=NULL
  }

  else
  { //caso comum, retirar elementos que não são os extremos
    anterior->proxima = celulaAuxiliar->proxima;
  }

  free(celulaAuxiliar);

  return matrizAuxiliar;
}

void DestroiLista(Lista *lista)
{
  Celula *p = lista->primeira;
  Celula *t = NULL;

  while (p != NULL)
  {
    t = p->proxima;
    DestroiMatriz(p->matriz);
    free(p);
    p = t;
  }
  //liberando a sentinela
  free(lista);
}