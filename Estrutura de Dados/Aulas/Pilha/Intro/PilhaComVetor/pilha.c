/* 
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#define TAM 10

struct pilha
{
  // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
  int topo; //vai começar com 0 (na minha implementação)
  Aluno *alunos[TAM];
};

//inicializa a estrutura da pilha
Pilha *InicializaPilha(void)
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = 0;
  return pilha;
}

void Push(Pilha *pilha, Aluno *aluno)
{
  if (!pilha || pilha->topo >= TAM || !aluno)
  {
    printf("Pilha cheia ou Aluno invalido!!\n");
    return;
  }

  pilha->alunos[pilha->topo] = aluno;
  pilha->topo++;
}

Aluno *Pop(Pilha *pilha)
{
  if (!pilha || pilha->topo == 0)
  {
    printf("Pilha vazia!\n");
    return NULL; //retorna deve ser conhecido do cliente, para fazer os tratamentos
  }
  Aluno *aluno = pilha->alunos[pilha->topo - 1];
  pilha->topo--;
  return aluno;

  // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
}

void ImprimePilha(Pilha *pilha)
{
  if (!pilha)
    return;

  for (int i = (pilha->topo - 1); i >= 0; i--)
    ImprimeAluno(pilha->alunos[i]);
}

void DestroiPilha(Pilha *pilha)
{
  if (!pilha)
    return;

  free(pilha);
}
