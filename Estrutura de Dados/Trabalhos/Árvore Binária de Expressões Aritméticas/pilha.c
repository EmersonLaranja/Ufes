/*
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#define TAM 50

struct pilha
{
  // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
  int topo; //vai começar com 0 (na minha implementação)
  Arvore *arvore[TAM];
};

//inicializa a estrutura da pilha
Pilha *InicializaPilha(void)
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = 0;
  return pilha;
}

void Push(Pilha *pilha, Arvore *arvore)
{
  if (!pilha || pilha->topo >= TAM || !arvore)
  {
    printf("Pilha cheia ou Arvore invalido!!\n");
    return;
  }

  pilha->arvore[pilha->topo] = arvore;
  pilha->topo++;
}

Arvore *Pop(Pilha *pilha)
{
  if (!pilha || pilha->topo == 0)
  {
    printf("Pilha vazia!\n");
    return NULL; //retorna deve ser conhecido do cliente, para fazer os tratamentos
  }
  Arvore *arvore = pilha->arvore[pilha->topo - 1];
  pilha->topo--;
  return arvore;

  // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
}

void DestroiPilha(Pilha *pilha)
{
  if (!pilha)
    return;

  free(pilha);
}

int RetornaValorTopo(Pilha *pilha)
{
  return pilha->topo;
}