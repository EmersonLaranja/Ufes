#ifndef LISTAGENERICA_H_
#define LISTAGENERICA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listagenerica ListaGenerica;

ListaGenerica *CriaLista();

ListaGenerica *InsereLista(ListaGenerica *lista, void *item);

int PercorreLista(ListaGenerica *lista, int (*cb)(void *, void *), void *dado);

ListaGenerica *RetiraLista(ListaGenerica *lista, int (*cb)(void *, void *), void *chave);

void LiberaLista(ListaGenerica *lista);

#endif /* LISTAGENERICA_H_ */