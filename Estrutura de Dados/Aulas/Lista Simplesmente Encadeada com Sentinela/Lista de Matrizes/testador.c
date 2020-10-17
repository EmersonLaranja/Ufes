#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 3

int main()
{
  int i, j;
  Matriz *mat1, *mat2, *mat3;
  //chamando a funcao do TAD Matriz que inicializa a matriz
  mat1 = InicializaMatriz(NLINHAS, NCOLUNAS);
  mat2 = InicializaMatriz(NLINHAS, NCOLUNAS);
  mat3 = InicializaMatriz(NLINHAS, NCOLUNAS);

  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat1, i, j, i + j);

  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat2, i, j, i + j);

  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat3, i, j, i + j);

  Lista *lista1, *lista2;
  lista1 = IniciaLista();

  InsereLista(lista1, mat1);
  InsereLista(lista1, mat2);
  InsereLista(lista1, mat3);

  lista2 = IniciaLista();
  InsereLista(lista2, Transposta(mat1));
  InsereLista(lista2, Transposta(mat2));
  InsereLista(lista2, Transposta(mat3));

  ImprimeLista(lista1);
  printf("\n");
  ImprimeLista(lista2);

  // int i, j;
  // for (i = 0; i < NLINHAS; i++)
  //   for (j = 0; j < NCOLUNAS; j++)
  //     ModificaElemento(mat, i, j, i + j);
  // ImprimeMatriz(mat);

  // Matriz *trp = Transposta(mat);
  // printf("A matriz transposta eh: \n");
  // ImprimeMatriz(trp);

  // Matriz *mlt = Multiplicacao(mat, trp);
  // printf("A matriz multiplicacao eh: \n");
  // ImprimeMatriz(mlt);

  // DestroiMatriz(mat);
  // DestroiMatriz(trp);
  // DestroiMatriz(mlt);

  return 0;
}