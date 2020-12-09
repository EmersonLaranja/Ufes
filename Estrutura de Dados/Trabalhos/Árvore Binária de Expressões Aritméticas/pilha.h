/* 
 * File:   Pilha.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;
#include "arv.h"

//inicializa a estrutura da pilha
Pilha *InicializaPilha(void);

//inclui no topo
void Push(Pilha *pilha, Arvore *arvore);
//retira do topo
Arvore *Pop(Pilha *pilha);

int RetornaValorTopo(Pilha *pilha);

void DestroiPilha(Pilha *pilha);

#endif /* PILHA_H */
