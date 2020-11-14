
#include "listaPaginas.h"
#define TAM 50
#define OUTPUT "outputs/"
struct celulaPagina
{
  Pagina *pagina;
  ListaLinks *listaLinks;
  ListaContribuicoes *listaContribuicoes;
  CelulaPagina *proxima;
};

struct listaPaginas
{
  CelulaPagina *primeira;
  CelulaPagina *ultima;
};

ListaPaginas *InicializaListaPaginas(void)
{
  ListaPaginas *listaPaginas = (ListaPaginas *)malloc(sizeof(ListaPaginas));
  listaPaginas->primeira = NULL;
  listaPaginas->ultima = NULL;
  return listaPaginas;
};

int VerificaPaginaExisteListaPaginas(ListaPaginas *listaPaginas, char *nomePagina)
{
  CelulaPagina *auxiliar = listaPaginas->primeira;

  while (auxiliar != NULL)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), nomePagina) == 0)
    {
      return 1; //nome do pagina existe
    }
    auxiliar = auxiliar->proxima;
  }
  return 0; //nao existe pagina com esse nome
};

void InserePaginaListaPaginas(ListaPaginas *listaPaginas, Pagina *pagina)
{
  CelulaPagina *nova = (CelulaPagina *)malloc(sizeof(CelulaPagina));
  nova->pagina = pagina;
  nova->listaContribuicoes = InicializaListaContribuicoes();
  nova->listaLinks = InicializaListaLinks();

  if (listaPaginas->primeira == NULL)
  {
    listaPaginas->primeira = nova;
    listaPaginas->ultima = nova;
  }
  listaPaginas->ultima->proxima = nova;
  listaPaginas->ultima = nova;
  nova->proxima = NULL;
};

void ImprimeListaPaginas(ListaPaginas *listaPaginas)
{
  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (auxiliar->pagina != NULL)
    {
      ImprimePaginaListaPaginas(listaPaginas, RetornaNomePagina(auxiliar->pagina));
    }
  }
};

void ImprimePaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina)
{
  Pagina *paginaAuxiliar = RetornaPaginaListaPaginas(listaPaginas, nomePagina);
  ListaContribuicoes *listaContribuicoesAuxiliar = RetornaListaContribuicoesListaPaginas(listaPaginas, nomePagina);
  ListaLinks *listaLinksAuxiliar = RetornaListaLinksListaPaginas(listaPaginas, nomePagina);

  if (paginaAuxiliar == NULL)
  {
    printf("Nao foi possivel imprimir a pagina\n");
    // fprintf(arquivoLog,"Nao foi possivel imprimir a pagina\n");
    return;
  }

  char nomeArquivoSaida[TAM] = OUTPUT;
  strcat(nomeArquivoSaida, RetornaNomeArquivoPagina(paginaAuxiliar));

  FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

  ImprimePagina(paginaAuxiliar, arquivoSaida);
  ImprimeHistoricoContribuicoes(listaContribuicoesAuxiliar, arquivoSaida);
  ImprimeListaLinks(listaLinksAuxiliar, arquivoSaida);
  ImprimeListaContribuicoes(listaContribuicoesAuxiliar, arquivoSaida);

  fclose(arquivoSaida);
};

CelulaPagina *RetornaCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina)
{
  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), nomePagina) == 0)
    {
      return auxiliar;
    }
  }
  return NULL;
};

Pagina *RetornaPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave)
{
  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), chave) == 0)
    {
      return auxiliar->pagina;
    }
  }
  return NULL;
};

ListaContribuicoes *RetornaListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *chave)
{
  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), chave) == 0)
    {
      return auxiliar->listaContribuicoes;
    }
  }
  return NULL;
};

ListaLinks *RetornaListaLinksListaPaginas(ListaPaginas *listaPaginas, char *chave)
{
  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    if (strcmp(RetornaNomePagina(auxiliar->pagina), chave) == 0)
    {
      return auxiliar->listaLinks;
    }
  }
  return NULL;
};

void RetiraCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave)
{
  CelulaPagina *auxiliar = listaPaginas->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomePagina(auxiliar->pagina), chave) != 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }

  if (auxiliar == NULL)
  {
    return;
  }

  if (auxiliar == listaPaginas->primeira && auxiliar == listaPaginas->ultima)
  {
    listaPaginas->primeira = listaPaginas->ultima = NULL;
  }
  else if (auxiliar == listaPaginas->primeira)
  {
    listaPaginas->primeira = auxiliar->proxima;
  }
  else if (auxiliar == listaPaginas->ultima)
  {
    listaPaginas->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
  }
  DestroiListaLinks(auxiliar->listaLinks); //destruindo as celulas
  AlteraEstadoContribuicoesListaContribuicoes(auxiliar->listaContribuicoes);
  DestroiListaContribuicoes(auxiliar->listaContribuicoes);
  free(auxiliar);
}

// void RetiraPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave){};

// void RetiraListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *chave){};

void RetiraLinksListaPaginas(ListaPaginas *listaPaginas, char *chave)
{

  for (CelulaPagina *auxiliar = listaPaginas->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    RetiraPaginaListaLinks(auxiliar->listaLinks, chave);
  }
};

void DestroiListaPaginas(ListaPaginas *listaPaginas)
{
  CelulaPagina *t;
  CelulaPagina *p = listaPaginas->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (p)
    {
      if (p->listaContribuicoes)
      {
        DestroiListaContribuicoes(p->listaContribuicoes);
      }
      if (p->listaLinks)
      {
        DestroiListaLinks(p->listaLinks);
      }
      if (p->pagina)
      {
        DestroiPagina(p->pagina);
      }
      free(p);
    }
    p = t;
  }
  free(listaPaginas);
};
