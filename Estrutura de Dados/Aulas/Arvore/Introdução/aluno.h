/* 
 * File:   aluno.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ALUNO_H
#define ALUNO_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct aluno Aluno;

  Aluno *InicializaAluno(int matricula, char *nome, float cr);

  void ImprimeAluno(Aluno *aluno);

  int RetornaMatricula(Aluno *aluno);

  char *RetornaNome(Aluno *aluno);

  float RetornaCR(Aluno *aluno);

  void DestroiAluno(Aluno *aluno);
  void ImprimeNomeAluno(Aluno *aluno);
#ifdef __cplusplus
}
#endif

#endif /* ALUNO_H */
