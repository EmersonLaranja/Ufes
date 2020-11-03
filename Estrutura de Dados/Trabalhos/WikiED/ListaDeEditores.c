#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ListaDeEditores.h"

struct celulaDeEditor
{
  Editor *editor;
  ListaDeContribuicoes *listaDeContribuicoes;
  CelulaDeEditor *proxima;
};

struct listaDeEditores
{
  CelulaDeEditor *primeira;
  CelulaDeEditor *ultima;
};
