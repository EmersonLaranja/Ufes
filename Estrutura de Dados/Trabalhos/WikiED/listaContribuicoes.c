
#include "listaContribuicoes.h"
#define TAM 50
#define INPUT "inputs/"
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

void InsereContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao, Editor *editor)
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

static void GravaArquivo(char *nomeArquivoLido, FILE *arquivoGravacao)
{
  char c;

  char caminhoArquivo[TAM] = INPUT;
  strcat(caminhoArquivo, nomeArquivoLido);

  FILE *arquivo = fopen(caminhoArquivo, "r");

  // FILE *arquivo = fopen(nomeArquivoLido, "r");

  if (arquivo == NULL)

  {

    printf("Problemas na leitura do arquivo %s\n", nomeArquivoLido);

    return;
  }

  while (1)

  {

    c = fgetc(arquivo);

    if (c == EOF)

    {

      break;
    }

    fprintf(arquivoGravacao, "%c", c);
  };

  fclose(arquivo);
};

void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo)
{
  fprintf(arquivo, "\n--> Textos");
  printf("\n--> Textos");

  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (RetornaFlagContribuicao(auxiliar->contribuicao))
    {
      continue;
    }
    fprintf(arquivo, "\n\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(auxiliar->contribuicao), RetornaNomeEditor(auxiliar->editor));
    printf("\n\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(auxiliar->contribuicao), RetornaNomeEditor(auxiliar->editor)); //! soh pra eu ver, apagar dps
    char *nomeAuxiliar = RetornaNomeArquivoContribuicao(auxiliar->contribuicao);
    GravaArquivo(nomeAuxiliar, arquivo);
  }
};
void ImprimeHistoricoContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo)
{
  printf("\n-> Historico de contribuicoes\n");
  fprintf(arquivo, "\n-> Historico de contribuicoes\n");
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    fprintf(arquivo, "%s %s", RetornaNomeEditor(auxiliar->editor), RetornaNomeArquivoContribuicao(auxiliar->contribuicao));
    printf("%s %s", RetornaNomeEditor(auxiliar->editor), RetornaNomeArquivoContribuicao(auxiliar->contribuicao));
    if (RetornaFlagContribuicao(auxiliar->contribuicao))
    {
      fprintf(arquivo, " <<retirada>>");
      printf(" <<retirada>>");
    }
    fprintf(arquivo, "\n");
    printf("\n");
  }
};

CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (auxiliar->contribuicao == contribuicao)
    {
      return auxiliar;
    }
  }
  return NULL;
}

Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeArquivoContribuicao(auxiliar->contribuicao), chave) == 0)
    {
      return auxiliar->contribuicao;
    }
  }
  return NULL;
};
// //
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeEditor(auxiliar->editor), chave) == 0)
    {
      return auxiliar->editor;
    }
  }
  return NULL;
};

void RetiraCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave)
{
  CelulaContribuicao *auxiliar = listaContribuicoes->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomeArquivoContribuicao(auxiliar->contribuicao), chave) != 0)
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
  AlteraEstadoContribuicao(auxiliar->contribuicao);
  free(auxiliar);
};
void AlteraEstadoContribuicoesListaContribuicoes(ListaContribuicoes *listaContribuicoes)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    AlteraEstadoContribuicao(auxiliar->contribuicao);
  }
};

void DestroiNosListaContribuicoes(ListaContribuicoes *listaContribuicoes)
{
  CelulaContribuicao *t;
  CelulaContribuicao *p = listaContribuicoes->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (p)
    {
      //! O programa TODO bugando por conta dessa linha
      // AlteraEstadoContribuicao(p->contribuicao);
      free(p);
    }
    p = t;
  }
  free(listaContribuicoes);
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
      if (p->contribuicao)
        DestroiContribuicao(p->contribuicao);
      free(p);
    }
    p = t;
  }
  free(listaContribuicoes);
};
