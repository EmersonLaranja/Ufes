#include "listaContribuicoes.h"
#include "listaEditores.h"
#include "listaLinks.h"
#include "listaPaginas.h"

void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo);
void RETIRAPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);
void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor);
void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void INSERECONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores);

int main(int argc, char *argv[])
{
  ListaPaginas *listaPaginas = InicializaListaPaginas();
  ListaEditores *listaEditores = InicializaListaEditores();

  char comando[50], argumento1[20], argumento2[20], argumento3[20];

  FILE *arquivo = fopen(argv[1], "r");
  FILE *arquivoLog = fopen("outputs/log.txt", "w");
  if (arquivo == NULL)
  {
    printf("Problema na leitura do arquivo, tente novamente\n");
    return 0;
  }
  while (fscanf(arquivo, "%s", comando) != EOF)
  // while (!feof(arquivo))
  {
    // fscanf(arquivo, "%[^\n]\n", comando);
    // fscanf(arquivo, "%s", comando);
    // fscanf(arquivo, "%*c\n");
    // fprintf(arquivoLog, "%s\n", comando);
    // printf("%s\n", comando);
    if (strcmp(comando, "INSEREPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      // fprintf(arquivoLog, "%s %s %s\n", comando, argumento1, argumento2);
      printf("%s %s %s\n", comando, argumento1, argumento2);
      INSEREPAGINA(listaPaginas, argumento1, argumento2);
      continue;
    }

    if (strcmp(comando, "RETIRAPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      // fprintf(arquivoLog, "%s %s\n", comando, argumento1);
      printf("%s %s\n", comando, argumento1);
      RETIRAPAGINA(listaPaginas, argumento1, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSEREEDITOR") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      // fprintf(arquivoLog, "%s %s\n", comando, argumento1);
      printf("%s %s\n", comando, argumento1);
      INSEREEDITOR(listaEditores, argumento1);

      continue;
    }

    if (strcmp(comando, "INSERECONTRIBUICAO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      // fprintf(arquivoLog, "%s %s %s %s\n", comando, argumento1, argumento2, argumento3);
      printf("%s %s %s %s\n", comando, argumento1, argumento2, argumento3);
      INSERECONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);

      continue;
    }

    if (strcmp(comando, "RETIRACONTRIBUICAO") == 0)
    {

      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      // fprintf(arquivoLog, "%s %s %s %s\n", comando, argumento1, argumento2, argumento3);
      printf("%s %s %s %s\n", comando, argumento1, argumento2, argumento3);
      RETIRACONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSERELINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      // fprintf(arquivoLog, "%s %s %s\n", comando, argumento1, argumento2);
      printf("%s %s %s\n", comando, argumento1, argumento2);
      INSERELINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "RETIRALINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      // fprintf(arquivoLog, "%s %s %s\n", comando, argumento1, argumento2);
      printf("%s %s %s\n", comando, argumento1, argumento2);
      RETIRALINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "CAMINHO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      // fprintf(arquivoLog, "%s %s %s\n", comando, argumento1, argumento2);
      printf("%s %s %s\n", comando, argumento1, argumento2);
      continue;
    }

    if (strcmp(comando, "IMPRIMEPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      // fprintf(arquivoLog, "%s %s\n", comando, argumento1);
      printf("%s %s\n", comando, argumento1);
      continue;
    }

    if (strcmp(comando, "IMPRIMEWIKED") == 0)
    {
      fprintf(arquivoLog, "%s %s %s\n", comando, argumento1, argumento2);
      // printf("%s %s %s\n", comando, argumento1, argumento2);
      printf("IMPRIMEWIKED\n");
      // fprintf(arquivoLog, "IMPRIMEWIKED\n");
      continue;
    }

    if (strcmp(comando, "FIM") == 0)
    {
      printf("FIM");
      // fprintf(arquivoLog, "FIM");
      FIM(listaPaginas, listaEditores);
      break;
    }
    else
    {
      fscanf(arquivo, "%[^\n]\n", comando);
      printf("Nao disponivel nesta versao\n");
      fprintf(arquivoLog, "Nao disponivel nesta versao\n");
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
    printf("nao existe a pagina %s\n", nomePagina);
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
    printf("Ja exite um editor com o nome %s\n", nomeEditor);
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
    fprintf(arquivoLog, "Pagina nao existe ou lista nao inicializada.ERROR\n");
    printf("Pagina nao existe ou lista nao inicializada.ERROR\n");
    DestroiContribuicao(contribuicao);
    return;
  };
  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaPaginas(listaPaginas, nomePagina);

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "Editor nao existe ou lista nao inicializada.ERROR\n");
    printf("Editor nao existe ou lista nao inicializada.ERROR\n");
    DestroiContribuicao(contribuicao);
    return;
  }
  Editor *editorAuxiliar = RetornaEditorListaEditores(listaEditores, nomeEditor);

  InsereContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, contribuicao, editorAuxiliar);
  InsereContribuicaoListaEditores(listaEditores, contribuicao, nomeEditor);
};

void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog)
{

  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePagina))
  {
    fprintf(arquivoLog, "Pagina nao existe ou lista nao inicializada.ERROR\n");
    printf("Pagina nao existe ou lista nao inicializada.ERROR\n");
    return;
  };

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "Editor nao existe ou lista nao inicializada.ERROR\n");
    printf("Editor nao existe ou lista nao inicializada.ERROR\n");
    return;
  }

  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaEditores(listaEditores, nomeEditor);

  Editor *editorDaListaContribuicoes = RetornaEditorListaContribuicoes(listaContribuicoesAuxiliar, nomeEditor);
  Editor *editorAuxiliar = RetornaEditorListaEditores(listaEditores, nomeEditor);

  if (strcmp(RetornaNomeEditor(editorDaListaContribuicoes), RetornaNomeEditor(editorAuxiliar)) != 0)
  {
    fprintf(arquivoLog, "ERROR: editor não tem direito de excluir esta contribuição\n");
    printf("ERROR: editor não tem direito de excluir esta contribuição\n");
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
    printf("A pagina %s nao existe\n", nomePaginaOrigem);
    return;
  }
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaDestino))
  {
    fprintf(arquivoLog, "A pagina %s nao existe\n", nomePaginaDestino);
    printf("A pagina %s nao existe\n", nomePaginaDestino);
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

void CAMINHO()
{
  printf("Essa funcao esta disponivel apenas na versao premium\n");
};
void IMPRIMEPAGINA();
void IMPRIMEWIKED();

void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores)
{
  DestroiListaPaginas(listaPaginas);
  DestroiListaEditores(listaEditores);
};