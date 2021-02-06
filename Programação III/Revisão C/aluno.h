#ifndef ALUNO_H
#define ALUNO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct aluno Aluno; //that could be in the aluno.c (Only testing)

Aluno *InicializaAluno(char *nome, int nota);
char *RetornaNome(Aluno *aluno);
int RetornaNota(Aluno *aluno);
void ImprimeAluno(Aluno *aluno);
void LiberaAluno(Aluno *aluno);
void OrdenaNomeAlunos(Aluno **vetor, int tamanho);

#endif /*ALUNO_H*/