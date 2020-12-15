#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *InicializaAluno(int matricula, char *nome, float cr);

void ImprimeAluno(Aluno *aluno);

int RetornaMatricula(Aluno *aluno);

float RetornaCR(Aluno *aluno);

char *RetornaNome(Aluno *aluno);

void DestroiAluno(Aluno *aluno);

#endif /* ALUNO_H */