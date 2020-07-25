/* 
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "listaComSentinela.h"
#define TAM 10

struct pilha
{
  Lista *lista;
};

//inicializa a estrutura da pilha
Pilha *InicializaPilha(void)
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->lista = IniciaLista();
  return pilha;
}

void Push(Pilha *pilha, Aluno *aluno)
{
  InsereLista(pilha->lista, aluno);
}

Aluno *Pop(Pilha *pilha)
{
  return (RetiraPosicao(pilha->lista, 0));
}

void ImprimePilha(Pilha *pilha)
{
  ImprimeLista(pilha->lista);
}

void DestroiPilha(Pilha *pilha)
{
  if (pilha)
  {

    DestroiLista(pilha->lista);
  }
  free(pilha)
}
