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
Pagina *RetornaPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave);
ListaContribuicoes *RetornaListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *chave);
ListaLinks *RetornaListaLinksListaPaginas(ListaPaginas *listaPaginas, char *chave);
void RetiraCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave);
// void RetiraPaginaListaPaginas(ListaPaginas *listaPaginas, char *chave);
// void RetiraListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *chave);
void RetiraLinksListaPaginas(ListaPaginas *listaPaginas, char *chave);
void ImprimeListaPaginas(ListaPaginas *listaPaginas, FILE *arq);
void DestroiListaPaginas(ListaPaginas *listaPaginas);
#endif /* LISTADEPAGINAS_H */
