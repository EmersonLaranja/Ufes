
#include "listaEditores.h"

struct celulaEditor
{
  Editor *editor;
  ListaContribuicoes *listaContribuicoes;
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
};

void InsereEditorListaEditores(ListaEditores *listaEditores, Editor *editor)
{
  CelulaEditor *nova = (CelulaEditor *)malloc(sizeof(CelulaEditor));
  nova->editor = editor;
  nova->listaContribuicoes = InicializaListaContribuicoes();

  if (listaEditores->primeira == NULL)
  {
    listaEditores->primeira = nova;
    listaEditores->ultima = nova;
  }
  listaEditores->ultima->proxima = nova;
  listaEditores->ultima = nova;
  nova->proxima = NULL;
};

void InsereContribuicaoListaEditores(ListaEditores *listaEditores, Contribuicao *contribuicao, char *chave)
{
  CelulaEditor *auxiliar = RetornaCelulaEditorListaEditores(listaEditores, chave);
  if (auxiliar == NULL)
  {
    // printf("Editor nao exite!\n");
    return;
  }
  InsereContribuicaoListaContribuicoes(auxiliar->listaContribuicoes, contribuicao, auxiliar->editor);
};

CelulaEditor *RetornaCelulaEditorListaEditores(ListaEditores *listaEditores, char *chave)
{
  for (CelulaEditor *auxiliar = listaEditores->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeEditor(auxiliar->editor), chave) == 0)
    {
      return auxiliar;
    }
  }
  return NULL;
};

Editor *RetornaEditorListaEditores(ListaEditores *listaEditores, char *chave)
{
  for (CelulaEditor *auxiliar = listaEditores->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeEditor(auxiliar->editor), chave) == 0)
    {
      return auxiliar->editor;
    }
  }
  return NULL;
};

ListaContribuicoes *RetornaListaContribuicoesListaEditores(ListaEditores *listaEditores, char *chave)
{
  CelulaEditor *auxiliar = RetornaCelulaEditorListaEditores(listaEditores, chave);
  return auxiliar->listaContribuicoes;
};

int VerificaEditorExisteListaEditores(ListaEditores *listaEditores, char *nomeEditor)
{
  CelulaEditor *auxiliar = listaEditores->primeira;

  while (auxiliar != NULL)
  {
    if (strcmp(RetornaNomeEditor(auxiliar->editor), nomeEditor) == 0)
    {
      return 1; //nome do editor existe
    }
    auxiliar = auxiliar->proxima;
  }
  return 0; //nao existe editor com esse nome
};

void ImprimeListaEditores(ListaEditores *listaEditores, FILE *arq)
{
  for (CelulaEditor *auxiliar = listaEditores->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    ImprimeEditor(auxiliar->editor);
    ImprimeListaContribuicoes(auxiliar->listaContribuicoes, arq);
  }
};

void DestroiListaEditores(ListaEditores *listaEditores)
{
  CelulaEditor *t;
  CelulaEditor *p = listaEditores->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (p)
    {

      if (p->listaContribuicoes)
        DestroiNosListaContribuicoes(p->listaContribuicoes);
      if (p->editor)
        DestroiEditor(p->editor);
      free(p);
    }
    p = t;
  }
  free(listaEditores);
};