#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

struct matriz
{
  int **inicio;
  int numlinhas;
  int numcolunas;
};

typedef struct matriz Matriz;

Matriz *InicializaMatriz(int nlinhas, int ncolunas)
{

  Matriz *m = (Matriz *)malloc(sizeof(Matriz));
  m->numcolunas = ncolunas;
  m->numlinhas = nlinhas;
  m->inicio = (int **)malloc(sizeof(int *) * m->numlinhas);
  for (int i = 0; i < m->numlinhas; i++)
  {
    m->inicio[i] = (int *)malloc(sizeof(int) * m->numcolunas);
  }
  return m;
}

void ModificaElemento(Matriz *mat, int linha, int coluna, int elem)
{

  if (linha < mat->numlinhas && coluna < mat->numcolunas)
  {
    mat->inicio[linha][coluna] = elem;
  }
}

int RecuperaElemento(Matriz *mat, int linha, int coluna)
{
  if (linha < mat->numlinhas && coluna < mat->numcolunas)
  {
    return mat->inicio[linha][coluna];
  }
}

int RecuperaNColunas(Matriz *mat)
{
  return mat->numcolunas;
}

int RecuperaNLinhas(Matriz *mat)
{
  return mat->numlinhas;
}

Matriz *Transposta(Matriz *mat)
{
  Matriz *t = InicializaMatriz(RecuperaNColunas(mat), RecuperaNLinhas(mat));
  for (int i = 0; i < t->numlinhas; i++)
  {
    for (int j = 0; j < t->numcolunas; j++)
    {
      ModificaElemento(t, i, j, RecuperaElemento(mat, j, i));
    }
  }
  return t;
}

Matriz *Multiplicacao(Matriz *mat1, Matriz *mat2)
{
  Matriz *mult = InicializaMatriz(RecuperaNLinhas(mat1), RecuperaNColunas(mat2));
  int t;
  for (int i = 0; i < mult->numlinhas; i++)
  {
    for (int j = 0; j < mult->numcolunas; j++)
    {
      t = 0;
      for (int k = 0; k < RecuperaNColunas(mat1); k++)
      {
        t += mat1->inicio[i][k] * mat2->inicio[k][j];
      }

      mult->inicio[i][j] = t;
    }
  }
  return mult;
}

void ImprimeMatriz(Matriz *mat)
{
  int k;
  for (int i = 0; i < mat->numlinhas; i++)
  {
    printf("|");
    for (int j = 0; j < mat->numcolunas; j++)
    {
      if (j == mat->numcolunas - 1)
      {
        printf("%.2d", mat->inicio[i][j]);
        continue;
      }
      printf("%.2d\t", mat->inicio[i][j]);
    }
    printf("|\n");
  }
}

void DestroiMatriz(Matriz *mat)
{
  for (int i = 0; i < mat->numlinhas; i++)
  {
    if (mat->inicio[i])
      free(mat->inicio[i]);
  }
  if (mat->inicio)
    free(mat->inicio);

  free(mat);
}
