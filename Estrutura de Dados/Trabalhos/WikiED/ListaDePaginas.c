#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ListaDePaginas.h"

struct celulaDePagina
{
  Pagina *pagina;
  ListaDeLinks *listaDeLinks;
  ListaDeContribuicoes *listaDeContribuicoes;
  CelulaDePagina *proxima;
};

struct listaDePaginas
{
  CelulaDePagina *primeira;
  CelulaDePagina *ultima;
};
