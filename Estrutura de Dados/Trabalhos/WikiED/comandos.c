#include "listaLinks.h"
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
    fprintf(arquivoLog, "ERROR: Nao existe a pagina %s\n", nomePagina);
    return;
  }
  RetiraCelulaPaginaListaPaginas(listaPaginas, nomePagina); //*! aqui nao apaga as contribuicoes
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
    fprintf(arquivoLog, "ERROR: Pagina %s nao existe ou lista nao inicializada.\n", nomePagina);
    DestroiContribuicao(contribuicao);
    return;
  };
  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaPaginas(listaPaginas, nomePagina);

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "ERROR: Editor(a) %s nao existe ou lista nao inicializada.\n", nomeEditor);
    DestroiContribuicao(contribuicao);
    return;
  }

  //Verificar se ja existe esta contribuicao nesta lista
  if (RetornaContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, nomeArquivoContribuicao) != NULL)
  {
    fprintf(arquivoLog, "ERROR: Contribuicao %s ja existe na lista de contribuicao pedida.\n", nomeArquivoContribuicao);
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
    fprintf(arquivoLog, "ERROR: Pagina %s nao existe na lista solicitada.\n", nomePagina);
    return;
  };

  if (!VerificaEditorExisteListaEditores(listaEditores, nomeEditor))
  {
    fprintf(arquivoLog, "ERROR: Editor %s nao existe na lista solicitada.\n", nomeEditor);
    return;
  }

  //lista de contribuicoes do editor passado
  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaEditores(listaEditores, nomeEditor);

  //verificando se existe a contribuicao passada na lista desse(a) editor(a). Se nao existe, nao é dela/dele
  if (RetornaContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, nomeArquivoContribuicao) == NULL)
  {
    fprintf(arquivoLog, "ERROR: editor nao tem direito de excluir a contribuicao %s ou contribuicao nao existe\n", nomeArquivoContribuicao);
    return;
  }

  Editor *editorDaListaContribuicoes = RetornaEditorListaContribuicoes(listaContribuicoesAuxiliar, nomeEditor);
  Editor *editorAuxiliar = RetornaEditorListaEditores(listaEditores, nomeEditor);

  //verifica se o editor da lista eh o editor passado. Se for, permite a retirada da celula de contribuicao da lista
  if (strcmp(RetornaNomeEditor(editorDaListaContribuicoes), RetornaNomeEditor(editorAuxiliar)) == 0)
  {
    RetiraCelulaContribuicaoListaContribuicoes(listaContribuicoesAuxiliar, nomeArquivoContribuicao);
  }
};

void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog)
{
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaOrigem))
  {
    fprintf(arquivoLog, "A pagina de origem %s nao existe\n", nomePaginaOrigem);
    return;
  }
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaDestino))
  {
    fprintf(arquivoLog, "A pagina de destino %s nao existe\n", nomePaginaDestino);
    return;
  }
  ListaLinks *listaLinkAuxiliar = RetornaListaLinksListaPaginas(listaPaginas, nomePaginaOrigem);

  //verificando se o link a ser inserido na lista de links ja existe
  if (RetornaPaginaListaLinks(listaLinkAuxiliar, nomePaginaDestino) != NULL)
  {
    fprintf(arquivoLog, "O link %s ja existe na lista de links da pagina %s\n", nomePaginaDestino, nomePaginaOrigem);
    return;
  }

  InserePaginaListaLinks(listaLinkAuxiliar, RetornaPaginaListaPaginas(listaPaginas, nomePaginaDestino));
};

void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog)
{
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaOrigem))
  {
    fprintf(arquivoLog, "A pagina de origem %s nao existe\n", nomePaginaOrigem);
    return;
  }
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaDestino))
  {
    fprintf(arquivoLog, "A pagina de destino %s nao existe\n", nomePaginaDestino);
    return;
  }

  ListaLinks *listaLinkAuxiliar = RetornaListaLinksListaPaginas(listaPaginas, nomePaginaOrigem);

  if (RetornaPaginaListaLinks(listaLinkAuxiliar, nomePaginaDestino) == NULL)
  {
    fprintf(arquivoLog, "O link %s nao esta na lista de links da pagina %s\n", nomePaginaDestino, nomePaginaOrigem);
  }
  RetiraPaginaListaLinks(listaLinkAuxiliar, nomePaginaDestino);
};

void CAMINHO(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog)
{
  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaOrigem))
  {
    fprintf(arquivoLog, "A pagina de origem %s nao existe\n", nomePaginaOrigem);
    return;
  }

  if (!VerificaPaginaExisteListaPaginas(listaPaginas, nomePaginaDestino))
  {
    fprintf(arquivoLog, "A pagina de destino %s nao existe\n", nomePaginaDestino);
    return;
  }

  Pagina *paginaOrigemAuxiliar = RetornaPaginaListaPaginas(listaPaginas, nomePaginaOrigem);
  Pagina *paginaDestinoAuxiliar = RetornaPaginaListaPaginas(listaPaginas, nomePaginaDestino);
  ListaLinks *paginasVisitadas = InicializaListaLinks(); //lista que armazena paginas que ja percorri

  VisitaPaginas(listaPaginas, paginaOrigemAuxiliar, paginaDestinoAuxiliar, paginasVisitadas); //percorre possiveis links, armazenando as paginas visitadas

  // Se ao percorrer os possiveis links eu nao passei na pagina de destino, significa que nao achei link para pagina de destino
  if (RetornaPaginaListaLinks(paginasVisitadas, RetornaNomePagina(paginaDestinoAuxiliar)) == NULL)
  {
    fprintf(arquivoLog, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", nomePaginaOrigem, nomePaginaDestino);
  }
  else
  {
    fprintf(arquivoLog, "HA CAMINHO DA PAGINA %s PARA %s\n", nomePaginaOrigem, nomePaginaDestino);
  }

  DestroiListaLinks(paginasVisitadas);
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
