#ifndef abb_h
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arv Arv;

Arv *abb_cria(void);

void *abb_imprime(Arv *a);

//retorna o ponteiro para o nó ou NULL
Arv *abb_busca(Arv *a, int chave);

Arv *abb_insere(Arv *a, Aluno *aluno);

Arv *abb_retira(Arv *a, int v);

Arv *abb_libera(Arv *a);

#endif /*ABB_H*/