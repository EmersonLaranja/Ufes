#ifndef arv_h
#define ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arv Arv;

Arv *arv_criavazia(void);

Arv *arv_cria(Aluno *al, Arv *sae, Arv *sad);

Arv *arv_libera(Arv *a);

int arv_vazia(Arv *a);

int arv_pertence(Arv *a, char *chave);

void *arv_imprime(Arv *a);

int arv_altura(Arv *a);

Arv *arv_pai(Arv *a, Aluno *al);

int folhas(Arv *a);

int ocorrencias(Arv *a, Aluno *al);

Aluno *RetornaAlunoArvore(Arv *a);

#endif /*ARV_H*/