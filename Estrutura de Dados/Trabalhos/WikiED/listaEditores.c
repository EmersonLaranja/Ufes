
#include "listaEditores.h"

struct celulaEditor
{
  Editor *editor;
  ListaContribuicoes *ListaContribuicoes;
  CelulaEditor *proxima;
};

struct listaEditores
{
  CelulaEditor *primeira;
  CelulaEditor *ultima;
};

ListaEditores *InicializaListaEditores(void)
{
  ListaEditores *lista = (ListaEditores *)malloc(sizeof(ListaEditores));
  lista->primeira = NULL;
  lista->ultima = NULL;
}

void InsereListaEditores(ListaEditores *lista, Editor *editor, ListaContribuicoes *ListaContribuicoes)
{
  CelulaEditor *nova = (CelulaEditor *)malloc(sizeof(CelulaEditor));
  nova->editor = editor;
  nova->ListaContribuicoes = ListaContribuicoes; //TODO: onde vou inicializar essa lista?

  if (lista->primeira == NULL)
  {
    lista->primeira = nova;
    lista->ultima = nova;
  }
  lista->ultima->proxima = nova;
  lista->ultima = nova;
  nova->proxima = NULL;
}
