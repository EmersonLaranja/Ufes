#ifndef LISTAEDITORES_H
#define LISTAEDITORES_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "editor.h"
#include "listaContribuicoes.h"

typedef struct listaEditores ListaEditores;
typedef struct celulaEditor CelulaEditor;

ListaEditores *InicializaListaEditores(void);
void InsereListaEditores(ListaEditores *lista, Editor *editor, ListaContribuicoes *ListaContribuicoes);

#endif /* LISTAEDITORES_H */
