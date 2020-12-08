/* 
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

//inicializa a estrutura da pilha
Pilha *InicializaPilha(void);

//inclui no topo
void Push(Pilha *pilha, Arv *arv);
//retira do topo
Arv *Pop(Pilha *pilha);

void ImprimePilha(Pilha *pilha);

void DestroiPilha(Pilha *pilha);

#endif /* PILHA_H */
