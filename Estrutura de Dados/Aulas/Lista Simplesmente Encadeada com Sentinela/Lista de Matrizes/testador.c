#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 4
#define NCOLUNAS 3

int main()
{
  int i, j;
  Matriz *mat1, *mat2, *mat3, *transp1, *transp2, *transp3;

  //chamando a funcao do TAD Matriz que inicializa a matriz
  mat1 = InicializaMatriz(NLINHAS, NCOLUNAS);
  mat2 = InicializaMatriz(NLINHAS, NCOLUNAS);
  mat3 = InicializaMatriz(NLINHAS, NCOLUNAS);

  //preenchendo as matrizes
  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat1, i, j, 2 * (i + j));

  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat2, i, j, i + j);

  for (i = 0; i < NLINHAS; i++)
    for (j = 0; j < NCOLUNAS; j++)
      ModificaElemento(mat3, i, j, 5 * (i + j));

  Lista *lista1, *lista2;
  lista1 = IniciaLista();

  InsereLista(lista1, mat1);
  InsereLista(lista1, mat2);
  InsereLista(lista1, mat3);

  transp1 = Transposta(mat1);
  transp2 = Transposta(mat2);
  transp3 = Transposta(mat3);

  lista2 = IniciaLista();
  InsereLista(lista2, (transp1));
  InsereLista(lista2, (transp2));
  InsereLista(lista2, (transp3));

  printf("Lista 1:\n");
  ImprimeLista(lista1);
  printf("Lista 2:\n");
  ImprimeLista(lista2);

  printf("\nRetirando algumas matrizes...\n");
  RetiraLista(lista1, 0);  //retirando a primeira matriz
  RetiraLista(lista1, 1);  //retirando a ultima matriz, visto que sobraram 2 matrizes
  RetiraLista(lista2, 1);  //retirando a matriz do meio
  RetiraLista(lista2, 10); //testando retirar de uma posição além da lista

  printf("Lista 1:\n");
  ImprimeLista(lista1);
  printf("Lista 2:\n");
  ImprimeLista(lista2);

  InsereLista(lista1, mat1);
  InsereLista(lista2, transp3);

  DestroiLista(lista1);
  DestroiLista(lista2);

  DestroiMatriz(mat1);
  DestroiMatriz(mat2);
  DestroiMatriz(mat3);
  DestroiMatriz(transp1);
  DestroiMatriz(transp2);
  DestroiMatriz(transp3);

  return 0;
}