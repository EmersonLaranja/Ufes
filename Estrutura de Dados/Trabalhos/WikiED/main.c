#include "listaContribuicoes.h"
#include "listaEditores.h"
#include "listaLinks.h"
#include "listaPaginas.h"
#define CAMINHO_ARQUIVO_LOG "log.txt"
#define TAM_COMANDO 50
#define TAM_ARGUMENTO 20

void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo);
void RETIRAPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);
void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor);
void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void INSERECONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void IMPRIMEPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);
void IMPRIMEWIKED(ListaPaginas *listaPaginas, FILE *arquivoLog);
void CAMINHO(FILE *arquivoLog);
void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores);

int main(int argc, char *argv[])
{
  char comando[TAM_COMANDO], argumento1[TAM_ARGUMENTO], argumento2[TAM_ARGUMENTO], argumento3[TAM_ARGUMENTO];

  FILE *arquivo = fopen(argv[1], "r");                //abrindo arquivo no modo de leitura
  FILE *arquivoLog = fopen(CAMINHO_ARQUIVO_LOG, "w"); //abrindo arquivo no modo de escrita
  if (arquivo == NULL)                                //algum problema no arquivo
  {
    printf("Problema na leitura do arquivo");
    fclose(arquivo);
    fclose(arquivoLog);
    return 0;
  }

  ListaPaginas *listaPaginas = InicializaListaPaginas();
  ListaEditores *listaEditores = InicializaListaEditores();

  while (fscanf(arquivo, "%s", comando) != EOF) // enquanto nao eh o fina do arquivo
  {
    if (strcmp(comando, "INSEREPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      INSEREPAGINA(listaPaginas, argumento1, argumento2);
      continue;
    }

    if (strcmp(comando, "RETIRAPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      RETIRAPAGINA(listaPaginas, argumento1, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSEREEDITOR") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      INSEREEDITOR(listaEditores, argumento1);

      continue;
    }

    if (strcmp(comando, "INSERECONTRIBUICAO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      INSERECONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);

      continue;
    }

    if (strcmp(comando, "RETIRACONTRIBUICAO") == 0)
    {

      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      RETIRACONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSERELINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      INSERELINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "RETIRALINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      RETIRALINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "CAMINHO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      CAMINHO(arquivoLog);
      continue;
    }

    if (strcmp(comando, "IMPRIMEPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      IMPRIMEPAGINA(listaPaginas, argumento1, arquivoLog);
      continue;
    }

    if (strcmp(comando, "IMPRIMEWIKED") == 0)
    {
      // fprintf(arquivoLog, "IMPRIMEWIKED\n");
      IMPRIMEWIKED(listaPaginas, arquivoLog);
      continue;
    }

    if (strcmp(comando, "FIM") == 0)
    {
      FIM(listaPaginas, listaEditores);
      break;
    }
    else
    {
      fprintf(arquivoLog, "Comando <%s> disponivel apenas na versao premium\n", comando);
      fscanf(arquivo, "%[^\n]\n", comando);
    }
  }
  fclose(arquivo);
  fclose(arquivoLog);
  return 0;
}

//lista ja inicializada na main
void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo)
{
  Pagina *pagina = InicializaPagina(nomePagina, nomeArquivo);
  InserePaginaListaPaginas(listaPaginas, pagina);
}

void RETIRAPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog)
{
  Pagina *paginaAuxiliar = RetornaPaginaListaPaginas(listaPaginas, nomePagina);
  if (paginaAuxiliar == NULL)
  {
    fprintf(arquivoLog, "nao existe a pagina %s\n", nomePagina);
    return;
  }
  RetiraCelulaPaginaListaPaginas(listaPaginas, nomePagina); //*! Lembre-se que aqui nao apaga as contribuicoes
  RetiraLinksListaPaginas(listaPaginas, nomePagina);
  DestroiPagina(paginaAuxiliar);
}

void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor)
{
  if (VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    return;
  }
  Editor *editor = InicializaEditor(nomeEditor);
  InsereEditorListaEditores(listaEditores, editor);
}

void INSERECONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog)
{
  Contribuicao *contribuicao = InicializaContribuicao(nomeArquivoContribuicao);

  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePagina))
  {
    fprintf(arquivoLog, "Pagina %s nao existe ou lista nao inicializada.ERROR\n", nomePagina);
    DestroiContribuicao(contribuicao);
    return;
  };
  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaPaginas(listaPaginas, nomePagina);

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "Editor(a) %s nao existe ou lista nao inicializada.ERROR\n", nomeEditor);
    DestroiContribuicao(contribuicao);
    return;
  }
  Editor *editorAuxiliar = RetornaEditorListaEditores(listaEditores, nomeEditor);

  // DestroiContribuicao(contribuicao);
  InsereContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, contribuicao, editorAuxiliar);
  InsereContribuicaoListaEditores(listaEditores, contribuicao, nomeEditor);
};

void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog)
{

  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePagina))
  {
    fprintf(arquivoLog, "Pagina %s nao existe ou lista nao inicializada.ERROR\n", nomePagina);
    return;
  };

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "Editor %s nao existe ou lista nao inicializada.ERROR\n", nomeEditor);
    return;
  }

  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaEditores(listaEditores, nomeEditor);

  Editor *editorDaListaContribuicoes = RetornaEditorListaContribuicoes(listaContribuicoesAuxiliar, nomeEditor);
  Editor *editorAuxiliar = RetornaEditorListaEditores(listaEditores, nomeEditor);

  if (strcmp(RetornaNomeEditor(editorDaListaContribuicoes), RetornaNomeEditor(editorAuxiliar)) != 0)
  {
    fprintf(arquivoLog, "ERROR: editor nao tem direito de excluir esta contribuicao\n");
    return;
  }
  else if (strcmp(RetornaNomeEditor(editorDaListaContribuicoes), RetornaNomeEditor(editorAuxiliar)) == 0)
  {
    RetiraCelulaContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, nomeArquivoContribuicao);
  }
};

void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog)
{
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaOrigem))
  {
    fprintf(arquivoLog, "A pagina %s nao existe\n", nomePaginaOrigem);
    return;
  }
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaDestino))
  {
    fprintf(arquivoLog, "A pagina %s nao existe\n", nomePaginaDestino);
    return;
  }
  ListaLinks *listaLinkAuxiliar = RetornaListaLinksListaPaginas(listaPaginas, nomePaginaOrigem);
  InserePaginaListaLinks(listaLinkAuxiliar, RetornaPaginaListaPaginas(listaPaginas, nomePaginaDestino));
};

void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog)
{
  ListaLinks *listaLinkAuxiliar = RetornaListaLinksListaPaginas(listaPaginas, nomePaginaOrigem);
  RetiraPaginaListaLinks(listaLinkAuxiliar, nomePaginaDestino);
};

void CAMINHO(FILE *arquivoLog)
{
  fprintf(arquivoLog, "Essa funcao esta disponivel apenas na versao premium\n");
};

void IMPRIMEPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog)
{
  ImprimePaginaListaPaginas(listaPaginas, nomePagina, arquivoLog);
};

void IMPRIMEWIKED(ListaPaginas *listaPaginas, FILE *arquivoLog)
{
  ImprimeListaPaginas(listaPaginas, arquivoLog);
};

void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores)
{
  DestroiListaPaginas(listaPaginas);
  DestroiListaEditores(listaEditores);
};