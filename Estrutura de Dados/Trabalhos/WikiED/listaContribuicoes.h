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
void InsereContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao, Editor *editor);
void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arq);
CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao);
Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave);
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave);
void AlteraEstadoContribuicoesListaContribuicoes(ListaContribuicoes *listaContribuicoes);
void RetiraCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *chave);
void DestroiNosListaContribuicoes(ListaContribuicoes *listaContribuicoes);
void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes);

#endif /* LISTACONTRIBUICOES_H */
