/* 
 * File:   listaMat.h
 * Author: Emerson Laranja
 *
 * Created on 17 de Outubro de 2020, 14:30
 */

#ifndef LISTAMAT_H
#define LISTAMAT_H

#include "matriz.h"

typedef struct lista Lista;

//TODO: Fazer as definições de cada função
Lista *IniciaLista();

void InsereLista(Lista *lista, Matriz *matriz);
void ImprimeLista(Lista *lista);
Matriz *RetiraLista(Lista *lista, int posicao);
void DestroiLista(Lista *lista);

#endif /* LISTACMAT_H */
