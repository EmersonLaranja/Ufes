/*
  listaLinks.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef LISTALINKS_H
#define LISTALINKS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "pagina.h"

/* Define o tipo ListaLinks (tipo opaco)*/
typedef struct listaLinks ListaLinks;

/* Define o tipo CelulaLink (tipo opaco)*/
typedef struct celulaLink CelulaLink;
#include "listaPaginas.h"
/*----------------------------------------------------------------------
 * Inicializa a lista de links
 * inputs: -
 * output: lista de links inicializada
 * pre-condicao: -
 * pos-condicao: sentinela da lista de links existe e os campos primeira e ultima apontam para NULL  */
ListaLinks *InicializaListaLinks(void);

/*----------------------------------------------------------------------
* Insere um link na ultima posição da lista de links
* inputs: a lista de links,o link (uma pagina) a ser inserido na lista
* output: nenhum
* pre-condicao:  lista de links e link (uma pagina) não são nulos
* pos-condicao: lista contém o link inserido na ultima posição
*/
void InserePaginaListaLinks(ListaLinks *listaLinks, Pagina *pagina);
/*----------------------------------------------------------------------
 * Retorna um link de uma lista de links (procurando um link pelo nome de seu link)
 * inputs: a lista de links e o nome do link 
 * output: o link
 * pre-condicao: lista de links deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado do link */
Pagina *RetornaPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina);

/*----------------------------------------------------------------------
 * Retorna uma celula de link de uma lista de links (procurando um link pelo nome de seu link)
 * inputs: a lista de links e o nome do link 
 * output: a celula de link
 * pre-condicao: lista de links deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado do link */
CelulaLink *RetornaCelulaLinkListaLinks(ListaLinks *listaLinks, char *nomePagina);

/*----------------------------------------------------------------------
*Imprime uma lista de links
* inputs: a lista de links e ponteiro do arquivo de saída
* output: arquivo de saida com links da lista de links
* pre-condicao: lista de links  não é nula o ponteiro do arquivo deve estar valido!
* pos-condicao: dados da lista de links impressos na saida padrao no arquivo de saida que foi gerado
*/
void ImprimeListaLinks(ListaLinks *listaLinks, FILE *arquivo);

/*----------------------------------------------------------------------
* Retira um link de uma lista de links (procurando um link pelo nome de seu link)
* inputs: a lista de links e o nome do arquivo de link
* output: o link retirado da lista de links ou NULL, se não se encontrar na lista de links
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o link com nome do link passado
*/
void RetiraPaginaListaLinks(ListaLinks *listaLinks, char *nomePagina);

/*----------------------------------------------------------------------
 * Destroi a lista de links
 * inputs: a lista de links
 * output: -
 * pre-condicao: lista de links deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado, libera os links*/
void DestroiListaLinks(ListaLinks *lista);

//todo
void VisitaPaginas(ListaPaginas *listaPaginas, Pagina *paginaPartida, Pagina *paginaDestino, ListaLinks *listaLinksPaginasVisitadas);
#endif /* LISTALINKS_H */
