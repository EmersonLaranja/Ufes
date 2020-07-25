
/* 
 * File:   fila.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define TAM 10

struct fila
{
  int inicio;
  int n; //tamanho da fila
  Aluno *alunos[TAM];
};

Fila *InicializaFila(void)
{
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->inicio = 0; //poderia ser qualquer indice valido (é uma fila circular)
  fila->n = 0;
  return fila;
}

//insere no final
void InsereFila(Fila *fila, Aluno *aluno)
{
  //testa se fila eh cheia
  if (!fila || fila->n >= TAM)
  {
    printf("\n Pilha invalida ou cheia\n");
    return;
  }
  //acha o final da fila circular!
  int posicaoFinal = (fila->n + fila->inicio) % TAM;

  //inserindo no final
  fila->alunos[posicaoFinal] = aluno;
  //incrementando o numero de alunos
  fila->n++;
}

//retira do começo
Aluno *RetiraFila(Fila *fila)
{
  if (!fila || fila->n == 0)
  {
    printf("\n Pilha invalida ou vazia\n");
    return NULL;
  }
  Aluno *aluno = fila->alunos[fila->inicio];

  //faz incremento circular do indice do inicio
  fila->inicio = (fila->inicio + 1) % TAM;
  fila->n--;
  return aluno;
}

//do inicio ao fim
void ImprimeFila(Fila *fila)
{
  int pos = 0;

  if (!fila)
    return;

  for (int i = 0; i < fila->n; i++)
  {
    pos = (fila->inicio + i) % TAM;
    ImprimeAluno(fila->alunos[pos]);
  }
}

void DestroiFila(Fila *fila)
{
  if (!fila)
  {
    return;
  }
  free(fila);
}
