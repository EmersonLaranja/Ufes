#include "arv.h"

int main()
{
  Arv *a = arv_cria('a',
                    arv_cria('b',
                             arv_criavazia(),
                             arv_cria('d', arv_criavazia(),
                                      arv_criavazia())),
                    arv_cria('c',
                             arv_cria('e', arv_criavazia(),
                                      arv_criavazia()),
                             arv_cria('f', arv_criavazia(),
                                      arv_criavazia())));

  arv_imprime(a);

  int pertence = arv_pertence(a, 'b');
  printf("Caracter b pertence?: %d\n", pertence);

  pertence = arv_pertence(a, 'z');
  printf("Caracter z pertence?: %d\n", pertence);

  Arv *pai = arv_pai(a, 'c');
  printf("Pai do c no: %c\n", info(pai));

  int f = folhas(a);
  printf("Numero de folhas da arvore: %d\n", f);

  int i = ocorrencias(a, 'f');
  printf("Numero de ocorrencias de f: %d\n", i);

  return 0;
}