/* 
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#ifndef PILHA_H
#define PILHA_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct pilha Pilha;

  //inicializa a estrutura da pilha
  Pilha *InicializaPilha(void);

  //inclui no topo
  void Push(Pilha *pilha, Aluno *aluno);
  //retira do topo
  Aluno *Pop(Pilha *pilha);

  void ImprimePilha(Pilha *pilha);

  void DestroiPilha(Pilha *pilha);

#ifdef __cplusplus
}
#endif

#endif /* PILHA_H */
