#include <stdio.h>

#include "Fila.h"

int main()
{
  Fila *fila = InicializaFila();
  int numero[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

  InsereFila(fila, &numero[0]);
  InsereFila(fila, &numero[1]);
  InsereFila(fila, &numero[2]);
  InsereFila(fila, &numero[3]);
  InsereFila(fila, &numero[4]);
  InsereFila(fila, &numero[6]);
  InsereFila(fila, &numero[7]);
  InsereFila(fila, &numero[8]);
  InsereFila(fila, &numero[9]);

  printf("Fila:\n");
  ImprimeFila(fila);

  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila);

  printf("Imprimindo Fila:\n");
  ImprimeFila(fila);

  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila);
  RetiraFila(fila); //acusa fila vazia
  InsereFila(fila, &numero[0]);
  InsereFila(fila, &numero[1]);

  printf("Imprimindo Fila:\n");
  ImprimeFila(fila);

  DestroiFila(fila);
  return 0;
}