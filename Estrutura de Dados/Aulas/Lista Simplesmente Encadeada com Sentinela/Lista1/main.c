/*
Dada uma lista L1 encadeada alocada dinamicamente (i.e., implementada
utilizando ponteiros), escreva funções em C que:

a) verifique se L1 está ordenada ou não (a ordem pode ser crescente ou
decrescente)✅

b) faça uma cópia da lista L1 em uma outra lista L2;✅

c) faça uma cópia da Lista L1 em L2, eliminando elementos repetidos,
considerando L1, L2 ordenadas;✅

d) inverta L1 colocando o resultado em L2;✅

e) intercale L1 com a lista L2, gerando a lista L3. Considere que L1, L2 e L3
são ordenadas.✅

f) gere uma lista L2 onde cada registro contém dois campos de informação:
elem contém um elemento de L1, e count contém quantas vezes este
elemento apareceu em L1.

g) elimine de L1 todas as ocorrências de um elemento dado, L1 ordenada.✅

h) assumindo que os elementos de L1 são inteiros positivos, forneça os
elementos que aparecem o maior e o menor número de vezes (forneça
ambos: os elementos e o número de vezes)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
  Lista *lista1 = InicializaLista();

  InsereInicioLista(lista1, "uva");
  InsereInicioLista(lista1, "manga");
  InsereInicioLista(lista1, "manga");
  InsereInicioLista(lista1, "banana");
  InsereInicioLista(lista1, "morango");
  OrdenaListaCrescente(lista1);
  printf("\n    🎈Lista1\n");
  ImprimeLista(lista1);

  RemoveElementoLista(lista1, "manga");
  printf("\nELEMENTO REMOVIDO\n");

  printf("\n    🎈Lista1\n");
  ImprimeLista(lista1);
}