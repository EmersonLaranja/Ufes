#include "crivo_de_eratostenes.h"

int main(int argc, char const *argv[])
{
  int n = 10000;
  char *lista = cria_lista(n);

  for (int i = 2; i < n; i++)
  {
    if (*(lista + i) == EH_INDEFINIDO)
    {
      *(lista + i) = EH_PRIMO;
      marca_multiplos(lista, i, n);
    }
  }

  // imprime_primos(lista, n);
  destroi_lista(lista);

  return 0;
}
