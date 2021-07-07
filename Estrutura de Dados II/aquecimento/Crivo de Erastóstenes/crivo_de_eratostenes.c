#include "crivo_de_eratostenes.h"

char *cria_lista(int tam)
{
  return calloc(tam, sizeof(char));
}

void marca_multiplos(char *lista, int param, int fim)
{
  //começa do primeiro multiplo, já que o param eh um primo
  for (int i = (param + param); i < fim; i += param)
  {
    *(lista + i) = NAO_EH_PRIMO;
  }
}

void imprime_primos(char *lista, int fim)
{
  for (int i = 0; i < fim; i++)
  {
    if (*(lista + i) == EH_PRIMO)
    {
      printf("%d\n", i);
    }
  }
}

void destroi_lista(char *lista)
{
  free(lista);
}