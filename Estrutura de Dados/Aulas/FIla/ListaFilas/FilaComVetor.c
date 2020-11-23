#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

#define TAM 10

struct filaComVetor
{
  int *items[TAM];
  int inicio;
  int tamanho;
};

Fila *InicializaFila()
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));

  fila->inicio = 0;
  fila->tamanho = 0;

  return fila;
}

void InsereFila(Fila *fila, int *numero)
{
  if (!fila || fila->tamanho == TAM)
  {
    printf("Fila cheia ou nao existe\n");
    return;
  }

  int posicao = (fila->inicio + fila->tamanho) % TAM;
  fila->items[posicao] = numero;
  fila->tamanho++;
}

void RetiraFila(Fila *fila)
{
  if (!fila || fila->tamanho == 0)
  {
    printf("Fila vazia ou nao existe!\n");
    return;
  }

  int posicao = (fila->inicio + 1) % TAM;
  fila->inicio = posicao;
  fila->tamanho--;
}

void ImprimeFila(Fila *fila)
{
  int i;
  int posicao;

  if (!fila || fila->tamanho == 0)
  {
    printf("Fila vazia ou nao existe!\n");
    return;
  }

  printf("| ");
  for (i = 0; i < fila->tamanho; i++)
  {
    posicao = (fila->inicio + i) % TAM;
    printf("%d ", *fila->items[posicao]);
  }
  printf("|\n\n");
}

void DestroiFila(Fila *fila)
{
  if (fila)
    free(fila);
  else
    printf("Fila não existe!\n");
}