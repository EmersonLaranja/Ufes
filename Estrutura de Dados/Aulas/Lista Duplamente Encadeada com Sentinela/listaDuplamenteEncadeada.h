#ifndef ListaDpl_h
#define ListaDpl_h

#include <stdio.h>
#include "aluno.h"

typedef struct listadpl ListaDpl;

ListaDpl *InicializaLista(void);
void *InsereLista(ListaDpl *lista, Aluno *aluno);
void *RetiraLista(ListaDpl *lista, char *chave);
void ImprimeLista(ListaDpl *lista);
void DestroiLista(ListaDpl *lista);

#endif /*ListaDpl_h*/