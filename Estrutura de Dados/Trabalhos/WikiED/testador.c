#include <stdio.h>
#include "listaLinks.h"
int main(int argc, char *argv[])
{
  FILE *arquivo;
  Pagina *paginaFisica = InicializaPagina("Fisica", "fisica.txt");
  Pagina *paginaArtes = InicializaPagina("Artes", "artes.txt");
  ListaLinks *listaLinks = InicializaListaLinks();

  InserePaginaListaLinks(listaLinks, paginaFisica);
  InserePaginaListaLinks(listaLinks, paginaArtes);

  Pagina *auxiliar = RetornaPaginaListaLinks(listaLinks, "Fisica");
  ImprimePagina(auxiliar, arquivo);
  ImprimeListaLinks(listaLinks, arquivo);

  RetiraLinkListaLinks(listaLinks, "Artes");
  ImprimeListaLinks(listaLinks, arquivo);

  DestroiListaLinks(listaLinks);
  DestroiPagina(paginaFisica);
  DestroiPagina(paginaArtes);
  return 0;
}
