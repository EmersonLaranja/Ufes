
#include "listaContribuicoes.h"

struct celulaContribuicao
{
  Editor *editor;
  Contribuicao *contribuicao;
  CelulaContribuicao *proxima;
};

struct listaContribuicoes
{
  CelulaContribuicao *primeira;
  CelulaContribuicao *ultima;
};

ListaContribuicoes *InicializaListaContribuicoes(void)
{
  ListaContribuicoes *listaContribuicoes = (ListaContribuicoes *)malloc(sizeof(ListaContribuicoes));
  listaContribuicoes->primeira = NULL;
  listaContribuicoes->ultima = NULL;
  return listaContribuicoes;
};

void InsereListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao, Editor *editor)
{
  CelulaContribuicao *nova = (CelulaContribuicao *)malloc(sizeof(CelulaContribuicao));
  nova->contribuicao = contribuicao;
  nova->editor = editor;

  if (listaContribuicoes->primeira == NULL)
  {
    listaContribuicoes->primeira = nova;
    listaContribuicoes->ultima = nova;
  }
  listaContribuicoes->ultima->proxima = nova;
  listaContribuicoes->ultima = nova;
  nova->proxima = NULL;
};

void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    printf("%s %s\n\n", RetornaNomeEditor(auxiliar->editor), RetornaNomeArquivo(auxiliar->contribuicao)); //! soh pra eu ver, apagar dps
    fprintf(arquivo, "%s %s\n\n", RetornaNomeEditor(auxiliar->editor), RetornaNomeArquivo(auxiliar->contribuicao));
  }
};

Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaTextoContribuicao(auxiliar->contribuicao), chave) == 0)
    {
      return auxiliar->contribuicao;
    }
  }
  return NULL;
};
// //
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (auxiliar->contribuicao == contribuicao)
    {
      return auxiliar->editor;
    }
  }
  return NULL;
};

void RetiraContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave)
{
  CelulaContribuicao *auxiliar = listaContribuicoes->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaTextoContribuicao(auxiliar->contribuicao), chave) == 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }

  if (auxiliar == NULL)
  {
    return;
  }

  if (auxiliar == listaContribuicoes->primeira && auxiliar == listaContribuicoes->ultima)
  {
    listaContribuicoes->primeira = listaContribuicoes->ultima = NULL;
  }
  else if (auxiliar == listaContribuicoes->primeira)
  {
    listaContribuicoes->primeira = auxiliar->proxima;
  }
  else if (auxiliar == listaContribuicoes->ultima)
  {
    listaContribuicoes->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
  }
  free(auxiliar);
};

void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes)
{
  CelulaContribuicao *t;
  CelulaContribuicao *p = listaContribuicoes->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (p)
    {
      free(p);
    }
    p = t;
  }
  free(listaContribuicoes);
};
