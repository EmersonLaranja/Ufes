
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

  if (listaLinks->primeira == NULL)
  {
    listaLinks->primeira = nova;
    listaLinks->ultima = nova;
  }
  listaLinks->ultima->proxima = nova;
  listaLinks->ultima = nova;
  nova->proxima = NULL;
};

//TODO: fazer RetornaPaginaListaLinks
Pagina *RetornaPaginaListaLinks(ListaLinks *listaLinks, char *chave)
{
  for (CelulaLink *nova = listaLinks->primeira; nova != NULL; nova = nova->proxima)
  {
    if (strcmp(RetornaNomePagina(nova->pagina), chave) == 0)
    {
      return nova->pagina;
    }
    return NULL;
  }
};

void ImprimeListaLinks(ListaLinks *listaLinks, FILE *arquivo)
{
  for (CelulaLink *nova = listaLinks->primeira; nova != NULL; nova = nova->proxima)
  {
    printf("%s %s\n\n", RetornaNomePagina(nova->pagina), RetornaNomeArquivo(nova->pagina)); //! soh pra eu ver, apagar dps
    fprintf(arquivo, "%s %s\n\n", RetornaNomePagina(nova->pagina), RetornaNomeArquivo(nova->pagina));
  }
};

void RetiraLinkListaLinks(ListaLinks *listaLinks, char *chave)
{
  CelulaLink *auxiliar = listaLinks->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomePagina(auxiliar->pagina), (chave)) != 0)
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
