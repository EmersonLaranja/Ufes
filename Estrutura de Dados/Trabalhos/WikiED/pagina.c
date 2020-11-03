#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pagina.h"

struct pagina
{
  char *nome
};

Pagina *InicializaPagina(char *nome)
{
  Pagina *pagina = (Pagina *)malloc(sizeof(Pagina));
  pagina->nome = strdup(nome);
  return pagina;
};

void ImprimePagina(Pagina *pagina)
{
  if (pagina)
    printf("%s\n", pagina->nome);
};

char *RetornaNomePagina(Pagina *pagina)
{
  return pagina->nome;
};

void DestroiPagina(Pagina *pagina)
{
  if (pagina)
    free(pagina->nome);
  free(pagina);
};
