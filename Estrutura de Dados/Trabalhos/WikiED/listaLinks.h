#ifndef LISTALINKS_H
#define LISTALINKS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pagina.h"

typedef struct listaLinks ListaLinks;
typedef struct celulaLink CelulaLink;

ListaLinks *InicializaListaLinks(void);
void InserePaginaListaLinks(ListaLinks *listaLinks, Pagina *pagina);
Pagina *RetornaPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina);
void ImprimeListaLinks(ListaLinks *listaLinks, FILE *arquivo);
void RetiraPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina);
void DestroiListaLinks(ListaLinks *lista);

#endif /* LISTALINKS_H */
