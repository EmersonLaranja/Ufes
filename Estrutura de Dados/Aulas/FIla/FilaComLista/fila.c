
/* 
 * File:   fila.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaComSentinela.h"
#include "fila.h"

#define TAM 10

struct fila
{
  Lista *lista;
};

Fila *InicializaFila(void)
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->lista = IniciaLista();
  return fila;
}

//insere no final
void InsereFila(Fila *fila, Aluno *aluno)
{
  InsereListaFim(fila->lista, aluno);
}

//retira do começo
Aluno *RetiraFila(Fila *fila)
{
  return RetiraPosicao(fila->lista, 0);
}

//do inicio ao fim
void ImprimeFila(Fila *fila)
{
  ImprimeLista(fila->lista);
}

void DestroiFila(Fila *fila)
{
  DestroiLista(fila->lista);
  free(fila);
}
