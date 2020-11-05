
#include "listaPaginas.h"

struct celulaPagina
{
  Pagina *pagina;
  ListaLinks *ListaLinks;
  ListaContribuicoes *ListaContribuicoes;
  CelulaPagina *proxima;
};

struct listaPaginas
{
  CelulaPagina *primeira;
  CelulaPagina *ultima;
};
