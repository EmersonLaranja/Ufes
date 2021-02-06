#include "aluno.h"

struct aluno
{
  char *nome;
  int nota;
};

Aluno *InicializaAluno(char *nome, int nota)
{
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  aluno->nome = strdup(nome);
  aluno->nota = nota;

  return aluno;
}

char *RetornaNome(Aluno *aluno)
{
  if (aluno)
    return aluno->nome;
}
int RetornaNota(Aluno *aluno)
{
  if (aluno)
    return aluno->nota;
}

void ImprimeAluno(Aluno *aluno)
{
  if (aluno)
    printf("Nome:%s, nota:%d\n", aluno->nome, aluno->nota);
}

void LiberaAluno(Aluno *aluno)
{
  if (aluno)
  {
    free(aluno->nome);
    free(aluno);
  }
}

static int ComparaNomes(const void *x, const void *y)
{
  Aluno *a = *((Aluno **)x), *b = *((Aluno **)y);
  return strcmp(RetornaNome(a), RetornaNome(b));
}

void OrdenaNomeAlunos(Aluno **vetor, int tamanho)
{
  qsort(vetor, tamanho, sizeof(Aluno *), ComparaNomes);
}