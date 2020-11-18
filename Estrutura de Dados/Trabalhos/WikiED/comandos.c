//lista ja inicializada na main
#include "comandos.h"
void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo, FILE *arquivoLog)
{
  if (VerificaPaginaExisteListaPaginas(listaPaginas, nomePagina))
  {
    fprintf(arquivoLog, "ERROR:Pagina %s ja existe\n", nomePagina);
    return;
  }
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

void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor, FILE *arquivoLog)
{
  if (VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "ERROR:Editor %s ja existe\n", nomeEditor);
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
