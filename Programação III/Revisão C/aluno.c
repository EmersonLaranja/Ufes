#include "aluno.h"

struct aluno
{
  char *nome;
  float nota;
};

Aluno *InicializaAluno(char *nome, float nota)
{
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  aluno->nome = strdup(nome);
  aluno->nota = nota;

  return aluno;
}

char *RetornaNome(Aluno *aluno)
{
  return aluno->nome;
}
float RetornaNota(Aluno *aluno)
{
  return aluno->nota;
}

void LiberaAluno(Aluno *aluno)
{
  if (aluno)
  {
    free(aluno->nome);
    free(aluno);
  }
}