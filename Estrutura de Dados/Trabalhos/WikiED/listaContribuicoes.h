#ifndef LISTACONTRIBUICOES_H
#define LISTACONTRIBUICOES_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "contribuicao.h"
#include "editor.h"

typedef struct listaContribuicoes ListaContribuicoes;
typedef struct celulaContribuicao CelulaContribuicao;

ListaContribuicoes *InicializaListaContribuicoes(void);

void InsereListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao, Editor *editor);

void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arq);

Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave);
// //
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contrib);

void RetiraContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave);

void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes);

#endif /* LISTACONTRIBUICOES_H */
