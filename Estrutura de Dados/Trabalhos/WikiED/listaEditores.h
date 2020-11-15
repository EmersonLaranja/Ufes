/*
  listaEditores.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef LISTAEDITORES_H
#define LISTAEDITORES_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "editor.h"
#include "listaContribuicoes.h"
/* Define o tipo ListaEditores (tipo opaco)*/
typedef struct listaEditores ListaEditores;

/* Define o tipo CelulaEditor (tipo opaco)*/
typedef struct celulaEditor CelulaEditor;

/*----------------------------------------------------------------------
 * Inicializa a lista de editores
 * inputs: -
 * output: lista de editores inicializada
 * pre-condicao: -
 * pos-condicao: sentinela da lista de editores existe e os campos primeira e ultima apontam para NULL  */
ListaEditores *InicializaListaEditores(void);

/*----------------------------------------------------------------------
*Insere um editor na ultima posição da lista de editores
* inputs: a lista de editores e o editor a ser inserido na lista 
* output: nenhum
* pre-condicao:  lista de editores e editor não são nulos
* pos-condicao: lista contém o editor inserida na ultima posição
*/
void InsereEditorListaEditores(ListaEditores *listaEditores, Editor *editor);

/*----------------------------------------------------------------------
*Insere uma contribuicao na ultima posição da lista de contribuicoes de um dado editor
* inputs: a lista de editores, a contribuicao a ser inserida na lista  e o nome do editor da contribuicao   
* output: nenhum
* pre-condicao:  lista de editores e contribuicao  não são nulos
* pos-condicao: lista contém a contribuicao inserida na ultima posição a lista de contribuicoes de um dado editor
*/
void InsereContribuicaoListaEditores(ListaEditores *listaEditores, Contribuicao *contribuicao, char *nomeEditor);

/*----------------------------------------------------------------------
 * Retorna a celula de editor de uma lista de editores (procurando celula pelo nome do editor)
 * inputs: a lista de editores e o nome de um editor 
 * output: a celula de editor
 * pre-condicao: lista de editores deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da editor   */
CelulaEditor *RetornaCelulaEditorListaEditores(ListaEditores *listaEditores, char *nomeEditor);

/*----------------------------------------------------------------------
 * Retorna um editor de uma lista de editores (procurando um editor pelo nome de um editor)
 * inputs: a lista de editores e o nome do editor 
 * output: o editor
 * pre-condicao: lista de editores deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da editor */
Editor *RetornaEditorListaEditores(ListaEditores *listaEditores, char *nomeEditor);

/*----------------------------------------------------------------------
 * Retorna uma lista de contribuicoes de uma lista de editores (procurando uma lista de contribuicoes pelo nome de um editor)
 * inputs: a lista de editores e o nome do editor da lista de contribuicoes 
 * output: a lista de contribuicoes do editor passado
 * pre-condicao: lista de editores deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da lista de contribuicoes */
ListaContribuicoes *RetornaListaContribuicoesListaEditores(ListaEditores *listaEditores, char *nomeEditor);

/*----------------------------------------------------------------------
 * Verifica se um editor existe
 * inputs: a lista de editores e o nome de um editor
 * output: 1 - caso o editor exista; 0 - caso o editor nao exista
 * pre-condicao: a lista de editores deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da lista de editores */
int VerificaEditorExisteListaEditores(ListaEditores *listaEditores, char *nomeEditor);

/*----------------------------------------------------------------------
 * Destroi a lista de editores
 * inputs: a lista de editores
 * output: -
 * pre-condicao: lista de editores deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado, libera os editores*/
void DestroiListaEditores(ListaEditores *listaEditores);

#endif /* LISTAEDITORES_H */
