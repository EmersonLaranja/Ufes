#include "aluno.h"

struct aluno
{
  float cr;
  int matricula;
  char *nome;
};

Aluno *InicializaAluno(int matricula, char *nome, float cr)
{
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  aluno->cr = cr;
  aluno->matricula = matricula;
  aluno->nome = strdup(nome);
  return aluno;
}

void ImprimeAluno(Aluno *aluno)
{
  printf(" Matricula: %d, Nome: %s, CR: %.2f\n", aluno->matricula, aluno->nome, aluno->cr);
}

int RetornaMatricula(Aluno *aluno)
{
  return aluno->matricula;
}

char *RetornaNome(Aluno *aluno)
{
  return aluno->nome;
}

float RetornaCR(Aluno *aluno)
{
  return aluno->cr;
}

void DestroiAluno(Aluno *aluno)
{
  if (aluno)
  {
    free(aluno->nome);
    free(aluno);
  }
}
