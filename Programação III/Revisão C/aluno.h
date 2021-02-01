#ifndef ALUNO_H
#define ALUNO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct aluno Aluno;

Aluno *InicializaAluno(char *nome, float nota);
char *RetornaNome(Aluno *aluno);
float RetornaNota(Aluno *aluno);
void LiberaAluno(Aluno *aluno);

#endif /*ALUNO_H*/