
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
  for (CelulaContribuicao *nova = listaContribuicoes->primeira; nova != NULL; nova = nova->proxima)
  {
    printf("%s %s\n\n", nova->editor, RetornaNomeArquivo(nova->contribuicao)); //! soh pra eu ver, apagar dps
    fprintf(arquivo, "%s %s\n\n", nova->editor, RetornaNomeArquivo(nova->contribuicao));
  }
};

Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave){};
// //
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contrib){};

void RetiraListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave){};

void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes){};
