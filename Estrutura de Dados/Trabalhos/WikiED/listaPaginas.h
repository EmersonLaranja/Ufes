/*
  listaPaginas.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef LISTAPAGINAS_H
#define LISTAPAGINAS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pagina.h"
#include "listaLinks.h"
#include "listaContribuicoes.h"

/* Define o tipo ListaPaginas (tipo opaco)*/
typedef struct listaPaginas ListaPaginas;

/* Define o tipo CelulaPagina (tipo opaco)*/
typedef struct celulaPagina CelulaPagina;

/*----------------------------------------------------------------------
 * Inicializa a lista de paginas
 * inputs: -
 * output: lista de paginas inicializada
 * pre-condicao: -
 * pos-condicao: sentinela da lista de paginas existe e os campos primeira e ultima apontam para NULL  */
ListaPaginas *InicializaListaPaginas(void);

/*----------------------------------------------------------------------
* Insere uma pagina na ultima posição da lista de paginas
* inputs: a lista de paginas e a pagina a ser inserida na lista  
* output: nenhum
* pre-condicao:  lista de paginas, pagina
* pos-condicao: lista contém a pagina inserida na ultima posição
*/
void InserePaginaListaPaginas(ListaPaginas *listaPaginas, Pagina *pagina);

/*----------------------------------------------------------------------
 * Verifica se uma pagina existe
 * inputs: a lista de paginas e o nome de um pagina
 * output: 1 - caso o pagina exista; 0 - caso o pagina nao exista
 * pre-condicao: a lista de paginas deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da lista de paginas */
int VerificaPaginaExisteListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
 * Retorna a celula de pagina de uma lista de paginas (procurando celula pelo nome do pagina)
 * inputs: a lista de paginas e o nome de um pagina 
 * output: a celula de pagina
 * pre-condicao: lista de paginas deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da pagina   */
CelulaPagina *RetornaCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
 * Retorna um pagina de uma lista de paginas (procurando um pagina pelo nome de um pagina)
 * inputs: a lista de paginas e o nome do pagina 
 * output: o pagina
 * pre-condicao: lista de paginas deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da pagina */
Pagina *RetornaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
 * Retorna uma lista de contribuicoes de uma lista de paginas (procurando uma lista de contribuicoes pelo nome de uma pagina)
 * inputs: a lista de paginas e o nome da pagina da lista de contribuicoes 
 * output: a lista de contribuicoes da pagina passada
 * pre-condicao: lista de paginas deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da lista de contribuicoes */
ListaContribuicoes *RetornaListaContribuicoesListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
 * Retorna uma lista de links de uma lista de paginas (procurando uma lista de links pelo nome de uma pagina)
 * inputs: a lista de paginas e o nome da pagina da lista de links 
 * output: a lista de links da pagina passada
 * pre-condicao: lista de paginas deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da lista de links */
ListaLinks *RetornaListaLinksListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
* Retira uma pagina de uma lista de paginas (procurando uma pagina pelo nome da pagina)
* inputs: a lista de paginas e o nome da pagina
* output: a pagina retirada da lista de paginas ou NULL, se não se encontrar na lista de paginas
* pre-condicao: lista não é nula
* pos-condicao: lista não contém a pagina com nome do arquivo de pagina
*/
void RetiraCelulaPaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
* Retira uma lista de links de uma lista de paginas (procurando uma pagina pelo nome da pagina)
* inputs: a lista de paginas e o nome da pagina
* output: a lista de links retirada da lista de paginas ou NULL, se não se encontrar na lista de paginas
* pre-condicao: as listas não são nulas
* pos-condicao: lista de e paginas não contém a lista de links com nome da pagina
*/
void RetiraLinksListaPaginas(ListaPaginas *listaPaginas, char *nomePagina);

/*----------------------------------------------------------------------
* Imprime uma pagina (procurando pagina por seu nome)
* inputs: a lista de paginas, nome de uma pagina e ponteiro do arquivo de log
* output: gera um arquivo para a pagina a ser impressa e a imprime
* pre-condicao: lista de paginas  não é nula o ponteiro do arquivo deve estar valido!
* pos-condicao: dados da lista de paginas impressos 
*/
void ImprimePaginaListaPaginas(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);

/*----------------------------------------------------------------------
* Imprime uma lista de paginas
* inputs: a lista de paginas e ponteiro do arquivo de log
* output: pagina impressa no arquivo de saida
* pre-condicao: lista de paginas  não é nula o ponteiro do arquivo deve estar valido!
* pos-condicao: dados da lista de paginas impressos 
*/
void ImprimeListaPaginas(ListaPaginas *listaPaginas, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Destroi a lista de paginas
 * inputs: a lista de paginas
 * output: -
 * pre-condicao: lista de paginas deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado, libera os paginas*/
void DestroiListaPaginas(ListaPaginas *listaPaginas);

#endif /* LISTADEPAGINAS_H */
