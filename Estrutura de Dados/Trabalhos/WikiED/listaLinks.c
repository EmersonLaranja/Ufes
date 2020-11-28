#include "listaLinks.h"
struct celulaLink
{
  Pagina *pagina;
  CelulaLink *proxima;
};

struct listaLinks
{
  CelulaLink *primeira;
  CelulaLink *ultima;
};

ListaLinks *InicializaListaLinks(void)
{
  ListaLinks *lista = (ListaLinks *)malloc(sizeof(ListaLinks));
  lista->primeira = NULL;
  lista->ultima = NULL;
  return lista;
};

void InserePaginaListaLinks(ListaLinks *listaLinks, Pagina *pagina)
{
  CelulaLink *nova = (CelulaLink *)malloc(sizeof(CelulaLink));
  nova->pagina = pagina;

  if (listaLinks->primeira == NULL) //verificando se a lista eh vazia
  {
    listaLinks->primeira = nova;
    listaLinks->ultima = nova;
  }
  listaLinks->ultima->proxima = nova;
  listaLinks->ultima = nova;
  nova->proxima = NULL;
};

Pagina *RetornaPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina)
{
  for (CelulaLink *auxiliar = listaLinks->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), nomePagina) == 0)
    {
      return auxiliar->pagina;
    }
  }
  return NULL;
};

CelulaLink *RetornaCelulaLinkListaLinks(ListaLinks *listaLinks, char *nomePagina)
{
  for (CelulaLink *auxiliar = listaLinks->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), nomePagina) == 0)
    {
      return auxiliar;
    }
  }
  return NULL;
};

void ImprimeListaLinks(ListaLinks *listaLinks, FILE *arquivo)
{
  fprintf(arquivo, "\n--> Links\n");

  for (CelulaLink *auxiliar = listaLinks->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    fprintf(arquivo, "%s %s\n", RetornaNomePagina(auxiliar->pagina), RetornaNomeArquivoPagina(auxiliar->pagina));
  }
};

void RetiraPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina)
{
  CelulaLink *auxiliar = listaLinks->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomePagina(auxiliar->pagina), (nomePagina)) != 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }

  if (auxiliar == NULL)
  {
    return;
  }

  if (auxiliar == listaLinks->primeira && auxiliar == listaLinks->ultima)
  {
    listaLinks->primeira = listaLinks->ultima = NULL;
  }
  else if (auxiliar == listaLinks->primeira)
  {
    listaLinks->primeira = auxiliar->proxima;
  }
  else if (auxiliar == listaLinks->ultima)
  {
    listaLinks->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
  }
  free(auxiliar);
};

void DestroiListaLinks(ListaLinks *listaLinks)
{
  CelulaLink *t;
  CelulaLink *p = listaLinks->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (p)
    {
      free(p);
    }
    p = t;
  }
  free(listaLinks);
};

void VisitaPaginas(ListaPaginas *listaPaginas, Pagina *paginaPartida, Pagina *paginaDestino, ListaLinks *listaLinksPaginasVisitadas)
{
  //insiro a pagina de onde eu partir
  InserePaginaListaLinks(listaLinksPaginasVisitadas, paginaPartida);

  //retornando a lista de links da pagina que quero percorrer
  ListaLinks *listaLinkPaginaPartida = RetornaListaLinksListaPaginas(listaPaginas, RetornaNomePagina(paginaPartida));

  //busca caminho dentro de cada celula da lista de link passada
  for (CelulaLink *auxiliar = listaLinkPaginaPartida->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    char *nomePaginaAuxiliar = RetornaNomePagina(auxiliar->pagina);

    //se nao encontrei na a pagina lista das paginas que visitei
    if (RetornaCelulaLinkListaLinks(listaLinksPaginasVisitadas, nomePaginaAuxiliar) == NULL)
    {
      //faco a visita para verificar se existe caminho na pagina em questao
      VisitaPaginas(listaPaginas, auxiliar->pagina, paginaDestino, listaLinksPaginasVisitadas);
    }
  }
}