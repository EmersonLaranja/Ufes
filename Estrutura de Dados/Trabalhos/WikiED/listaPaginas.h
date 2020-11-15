#ifndef LISTAPAGINAS_H
#define LISTAPAGINAS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pagina.h"
#include "listaLinks.h"
#include "listaContribuicoes.h"

typedef struct listaPaginas ListaPaginas;
typedef struct celulaPagina CelulaPagina;

ListaPaginas *InicializaListaPaginas(void);
void InserePaginaListaPaginas(ListaPaginas *listaPaginas, Pagina *pagina);
int VerificaPaginaExisteListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
CelulaPagina *RetornaCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
Pagina *RetornaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
ListaContribuicoes *RetornaListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
ListaLinks *RetornaListaLinksListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
void RetiraCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
// void RetiraPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
// void RetiraListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
void RetiraLinksListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
void ImprimePaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);
void ImprimeListaPaginas(ListaPaginas *listaPaginas);
void DestroiListaPaginas(ListaPaginas *listaPaginas);
#endif /* LISTADEPAGINAS_H */
