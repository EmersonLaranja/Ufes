
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILA_H
#define FILA_H

typedef struct filaComVetor Fila;
// typedef struct filaComLista Fila;

Fila *InicializaFila(void);

void InsereFila(Fila *fila, int *numero);

void RetiraFila(Fila *fila);

void ImprimeFila(Fila *fila);

void DestroiFila(Fila *fila);

#endif /* FILA_H */