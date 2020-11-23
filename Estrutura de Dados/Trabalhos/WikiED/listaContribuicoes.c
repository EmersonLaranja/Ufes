
#include "listaContribuicoes.h"
#define TAM 50 //tamanho de um vetor comum
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

  if (listaContribuicoes->primeira == NULL) //verificando se a lista eh vazia
  {
    listaContribuicoes->primeira = nova;
    listaContribuicoes->ultima = nova;
  }
  listaContribuicoes->ultima->proxima = nova;
  listaContribuicoes->ultima = nova;
  nova->proxima = NULL;
};

static void GravaArquivo(char *nomeArquivoLido, FILE *arquivoGravacao) //grava informacoes do arquivo a ser lido no arquivo de gravacao
{
  char c; //char auxiliar

  FILE *arquivo = fopen(nomeArquivoLido, "r"); //abrindo arquivo no modo de leitura

  if (arquivo == NULL) //se nao consegui abrir o arquivo

  {

    printf("Problemas na leitura do arquivo %s\n", nomeArquivoLido);

    return;
  }

  while (1)

  {

    c = fgetc(arquivo); //recebe um char do arquivo

    if (c == EOF) //se chegou no final do arquivo

    {

      break; //encerra condicao
    }

    fprintf(arquivoGravacao, "%c", c); //grava char no arquivo de gravacao
  };

  fclose(arquivo);
};

void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo)
{
  fprintf(arquivo, "\n--> Textos");

  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (RetornaFlagContribuicao(auxiliar->contribuicao)) // se a flag for SIM (se contribuicao foi retirada)
    {
      continue;
    }

    fprintf(arquivo, "\n\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(auxiliar->contribuicao), RetornaNomeEditor(auxiliar->editor));

    char *nomeAuxiliar = RetornaNomeArquivoContribuicao(auxiliar->contribuicao);
    GravaArquivo(nomeAuxiliar, arquivo);
  }
};

void ImprimeHistoricoContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo)
{
  fprintf(arquivo, "\n--> Historico de contribuicoes\n");

  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    fprintf(arquivo, "%s %s", RetornaNomeEditor(auxiliar->editor), RetornaNomeArquivoContribuicao(auxiliar->contribuicao));

    if (RetornaFlagContribuicao(auxiliar->contribuicao)) // se a flag for SIM (se contribuicao foi retirada)
    {
      fprintf(arquivo, " <<retirada>>");
    }

    fprintf(arquivo, "\n");
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

Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeArquivoContribuicao(auxiliar->contribuicao), nomeArquivo) == 0)
    {
      return auxiliar->contribuicao;
    }
  }
  return NULL;
};
// //
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeEditor)
{
  for (CelulaContribuicao *auxiliar = listaContribuicoes->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomeEditor(auxiliar->editor), nomeEditor) == 0)
    {
      return auxiliar->editor;
    }
  }
  return NULL;
};

void RetiraCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo)
{
  CelulaContribuicao *auxiliar = listaContribuicoes->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomeArquivoContribuicao(auxiliar->contribuicao), nomeArquivo) != 0)
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
