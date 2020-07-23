/* 
 * File:   fila.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include "aluno.h"

#ifndef FILA_H
#define FILA_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct fila Fila;

  Fila *InicializaFila(void);

  //insere no final
  void InsereFila(Fila *fila, Aluno *aluno);

  //retira do começo
  Aluno *RetiraFila(Fila *fila, Aluno *aluno);

  //do inicio ao fim
  void ImprimeFila(Fila *fila);

  void DestroiFila(Fila *fila);

#ifdef __cplusplus
}
#endif

#endif /* FILA_H */
