
// #include "Fila.h"

// typedef struct celula Celula;

// struct celula
// {
//   int *elemento;
//   Celula *proxima;
// };

// struct filaComLista
// {
//   Celula *inicio;
//   Celula *fim;
// };

// Fila *InicializaFila()
// {
//   Fila *fila = (Fila *)malloc(sizeof(Fila));

//   fila->inicio = NULL;
//   fila->fim = NULL;

//   return fila;
// }

// void InsereFila(Fila *fila, int *numero)
// {
//   if (!fila)
//   {
//     printf("Fila nao existe!\n");
//     return;
//   }

//   Celula *nova = (Celula *)malloc(sizeof(Celula));

//   nova->elemento = numero;
//   nova->proxima = NULL;

//   if (!fila->fim)
//     fila->inicio = nova;
//   else
//     fila->fim->proxima = nova;

//   fila->fim = nova;
// }

// void RetiraFila(Fila *fila)
// {
//   if (!fila)
//   {
//     printf("Fila não existe!\n");
//     return;
//   }

//   if (!fila->inicio)
//   {
//     printf("Fila vazia!\n");
//     return;
//   }

//   Celula *auxiliar = fila->inicio;

//   if (fila->inicio == fila->fim)
//   {
//     fila->inicio = NULL;
//     fila->fim = NULL;
//   }
//   else
//     fila->inicio = auxiliar->proxima;

//   free(auxiliar);
// }

// void ImprimeFila(Fila *fila)
// {
//   if (!fila)
//   {
//     printf("Fila não existe!\n");
//     return;
//   }

//   if (!fila->inicio)
//   {
//     printf("Fila vazia!\n");
//     return;
//   }

//   Celula *auxiliar;
//   printf("| ");
//   for (auxiliar = fila->inicio; auxiliar; auxiliar = auxiliar->proxima)
//   {
//     printf("%d ", *auxiliar->elemento);
//   }
//   printf("|\n\n");
// }

// void DestroiFila(Fila *fila)
// {
//   if (fila)
//   {
//     Celula *auxiliar = fila->inicio;
//     Celula *proxima;

//     while (auxiliar)
//     {
//       proxima = auxiliar->proxima;
//       free(auxiliar);
//       auxiliar = proxima;
//     }

//     free(fila);
//   }
//   else
//     printf("Fila não existe!\n");
// }