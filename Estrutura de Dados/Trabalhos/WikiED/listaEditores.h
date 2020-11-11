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
void InsereEditorListaEditores(ListaEditores *listaEditores, Editor *editor);
void InsereContribuicaoListaEditores(ListaEditores *listaEditores, Contribuicao *contribuicao, char *chave);
CelulaEditor *RetornaCelulaEditorListaEditores(ListaEditores *listaEditores, char *chave);
Editor *RetornaEditorListaEditores(ListaEditores *listaEditores, char *chave);
ListaContribuicoes *RetornaListaContribuicoesListaEditores(ListaEditores *listaEditores, char *chave);
int VerificaNomeEditorExisteListaEditores(ListaEditores *listaEditores, char *nomeEditor);
void ImprimeListaEditores(ListaEditores *listaEditores, FILE *arq);
void DestroiListaEditores(ListaEditores *listaEditores);
#endif /* LISTAEDITORES_H */
