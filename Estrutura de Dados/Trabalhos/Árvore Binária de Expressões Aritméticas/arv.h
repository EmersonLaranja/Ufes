/*
  arvore.h
  Trabalho de ED1 - Árvore Binária de Expressões Aritméticas
  Created by Emerson Laranja dos Santos on 12/07/2020.
*/

#ifndef ARVORE_H
#define ARVORE_H
#define OPERANDO 1
#define OPERADOR 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;
#include "pilha.h"

Arvore *ArvoreCriaVazia(void);

Arvore *ArvoreCria(int operando, char operador, Arvore *sae, Arvore *sad);
Arvore *ArvoreLibera(Arvore *arvore);

int ArvoreVazia(Arvore *arvore);

Arvore *MontaArvore(Arvore *arvore, char *expressao, Pilha *caminhos, int posicao);

float CalculaArvore(Arvore *arvore);

#endif /* ARVORE_H */