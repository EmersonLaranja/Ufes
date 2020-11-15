/*
  pagina.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef PAGINA_H
#define PAGINA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Define o tipo Contribuicao (tipo opaco)*/
typedef struct pagina Pagina;

/*----------------------------------------------------------------------
 * Inicializa a pagina
 * inputs: nome da pagina e do arquivo de pagina
 * output: pagina inicializada
 * pre-condicao: -
 * pos-condicao: pagina inicializada  */
Pagina *InicializaPagina(char *nomeDaPagina, char *nomeArquivo);

/*----------------------------------------------------------------------
 * Imprime a pagina (nome da pagina)
 * inputs: o pagina e o ponteiro para o arquivo
 * output: -
 * pre-condicao: pagina deve ser previamente inicializado e o ponteiro do arquivo deve estar valido!
 * pos-condicao: funcao nao altera os dados do pagina */
void ImprimePagina(Pagina *pagina, FILE *arquivo);

/*----------------------------------------------------------------------
 * Retorna o nome da pagina
 * inputs: a pagina
 * output: o nome da pagina
 * pre-condicao: pagina deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da pagina   */
char *RetornaNomePagina(Pagina *pagina);

/*----------------------------------------------------------------------
 * Retorna o nome do arquivo da pagina
 * inputs: o nome do arquivo da pagina
 * output: o nome do arquivo da pagina
 * pre-condicao: pagina deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado do arquivo  da pagina  */
char *RetornaNomeArquivoPagina(Pagina *pagina);

/*----------------------------------------------------------------------
 * Destroi a pagina
 * inputs: a pagina
 * output: -
 * pre-condicao: pagina deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado */
void DestroiPagina(Pagina *pagina);

#endif /* PAGINA_H */