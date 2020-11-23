/*
  comandos.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/18/2020.
*/

#ifndef COMANDOS_H
#define COMANDOS_H
#include "listaPaginas.h"
#include "listaEditores.h"

void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo, FILE *arquivoLog);
void RETIRAPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);
void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor, FILE *arquivoLog);
void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void INSERECONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);
void IMPRIMEPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);
void IMPRIMEWIKED(ListaPaginas *listaPaginas, FILE *arquivoLog);
void CAMINHO(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);
void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores);

#endif /*COMANDOS_H*/