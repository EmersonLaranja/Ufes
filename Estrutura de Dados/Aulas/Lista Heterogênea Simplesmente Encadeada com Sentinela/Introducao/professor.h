
/* 
 * File:   listaHet.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#ifndef PROFESSOR_H
#define PROFESSOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include "aluno.h"

  typedef struct professor Professor;
  Professor *InicializaProfessor(int siape, char *nome, float salario);
  void ImprimeProfessor(Professor *prof);
  int RetornaSiape(Professor *professor);
  char *RetornaNomeProfessor(Professor *professor);
  float RetornaSalario(Professor *professor);
  void DestroiProfessor(Professor *professor);

#ifdef __cplusplus
}
#endif

#endif /* PROFESSOR_H */
