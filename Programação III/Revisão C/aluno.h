#ifndef ALUNO_H
#define ALUNO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TAM_NOME 20
typedef struct aluno //that could be in the aluno.c (Only testing)
{
  char nome[TAM_NOME];
  int nota;
} Aluno;

Aluno *InicializaAluno(char *nome, float nota);
char *RetornaNome(Aluno *aluno);
float RetornaNota(Aluno *aluno);
void LiberaAluno(Aluno *aluno);

#endif /*ALUNO_H*/