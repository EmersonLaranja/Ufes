#include "listaDeAlunos.h"

struct cr
{
  int n;    //quantidade de alunos
  float cr; //cr acumulado
};

static int ComparaMatriculas(void *aluno, void *mat)
{
  Aluno *a = (Aluno *)aluno;
  int *imat = (int *)mat;

  if (RetornaMatricula(a) == *imat)
  {
    return 0;
  }

  return 1;
}

static int Imprime(void *aluno, void *dado)
{
  ImprimeAluno(aluno);
  return 1;
}

static int acumula(void *aluno, void *dado)
{
  struct cr *acumulado = (struct cr *)dado;
  acumulado->cr += RetornaCR(aluno);
  acumulado->n++;
  return 1;
}

ListaGenerica *RetiraAluno(ListaGenerica *lista, int matricula)
{
  return RetiraLista(lista, ComparaMatriculas, &matricula);
}

int PertenceAluno(ListaGenerica *lista, int matricula)
{
  return PercorreLista(lista, ComparaMatriculas, &matricula);
}

void ImprimeListaAlunos(ListaGenerica *lista)
{
  PercorreLista(lista, Imprime, NULL);
}

float CalculaMediaTurma(ListaGenerica *lista)
{
  struct cr *acumulado = (struct cr *)malloc(sizeof(struct cr));
  acumulado->cr = 0.0;
  acumulado->n = 0;

  PercorreLista(lista, acumula, acumulado);

  float media = acumulado->cr / acumulado->n;

  free(acumulado);
  return media;
}
