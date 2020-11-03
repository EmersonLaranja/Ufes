#ifndef LISTADELINKS_H
#define LISTADELINKS_H
#include "pagina.h"

typedef struct listaDeLinks ListaDeLinks;
typedef struct celulaDeLink CelulaDeLink;

ListaDeLinks *InicializaListaDeLinks(void);
void InserePaginaNaListaDeLinks(ListaDeLinks *lista, Pagina *pagina);
void RemoveLinkDaListaDeLinks(ListaDeLinks *lista, char *chave);
void RemoveListaDeLinks(ListaDeLinks *lista);
// void ImprimeListaDeLinks(ListaDeLinks *lista);

#endif /* LISTADELINKS_H */
