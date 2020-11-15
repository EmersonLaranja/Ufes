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
void ImprimeHistoricoContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arq);
CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao);
Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo);
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeEditor);
void AlteraEstadoContribuicoesListaContribuicoes(ListaContribuicoes *listaContribuicoes);
void RetiraCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo);
void DestroiNosListaContribuicoes(ListaContribuicoes *listaContribuicoes);
void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes);

#endif /* LISTACONTRIBUICOES_H */