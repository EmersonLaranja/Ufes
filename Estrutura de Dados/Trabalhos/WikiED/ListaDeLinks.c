#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ListaDeLinks.h"

struct celulaDeLink
{
  Pagina *pagina;
  CelulaDeLink *proxima;
};

struct listaDeLinks
{
  CelulaDeLink *primeira;
  CelulaDeLink *ultima;
};

ListaDeLinks *InicializaListaDeLinks(void)
{
  ListaDeLinks *lista = (ListaDeLinks *)malloc(sizeof(ListaDeLinks));
  lista->primeira = NULL;
  lista->ultima = NULL;
  return lista;
};

void InserePaginaNaListaDeLinks(ListaDeLinks *lista, Pagina *pagina)
{
  CelulaDeLink *nova = (CelulaDeLink *)malloc(sizeof(CelulaDeLink));
  nova->pagina = pagina;

  if (lista->primeira == NULL)
  {
    lista->primeira = nova;
    lista->ultima = nova;
  }
  lista->ultima->proxima = nova;
  lista->ultima = nova;
  nova->proxima = NULL;
};

void RemoveLinkDaListaDeLinks(ListaDeLinks *lista, char *chave)
{
  CelulaDeLink *auxiliar = lista->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomePagina(auxiliar->pagina), (chave)) != 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }

  if (auxiliar == NULL)
  {
    return;
  }

  if (auxiliar == lista->primeira && auxiliar == lista->ultima)
  {
    lista->primeira = lista->ultima = NULL;
  }
  else if (auxiliar == lista->primeira)
  {
    lista->primeira = auxiliar->proxima;
  }
  else if (auxiliar == lista->ultima)
  {
    lista->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
  }
  free(auxiliar);
};
void RemoveListaDeLinks(ListaDeLinks *lista)
{
  CelulaDeLink *t;
  CelulaDeLink *p = lista->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (t)
    {
      free(p);
    }
    p = t;
  }
  free(lista);
};
