/*
  contribuicao.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Define o tipo Contribuicao (tipo opaco)*/
typedef struct contribuicao Contribuicao;

/*----------------------------------------------------------------------
 * Inicializa a contribuicao
 * inputs: nome do arquivo de contribuicao
 * output: contribuicao inicializada
 * pre-condicao: -
 * pos-condicao: contribuicao inicializada  */
Contribuicao *InicializaContribuicao(char *nomeArquivo);

/*----------------------------------------------------------------------
 * Retorna a flag que indica se uma contribuicao foi retirada ou não
 * inputs: a contribuicao
 * output: o valor da flag
 * pre-condicao: contribuicao deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da contribuicao  */
int RetornaFlagContribuicao(Contribuicao *contribuicao);

/*----------------------------------------------------------------------
 * Retorna o nome do arquivo de contribuicao
 * inputs: a contribuicao
 * output: o nome do arquivo de contribuicao
 * pre-condicao: contribuicao deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da contribuicao   */
char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao);

/*----------------------------------------------------------------------
 * Altera o estado da flag de contribuicao de uma contribuicao (indicando se ela foi retirada ou não)
 * inputs: a contribuicao
 * output: -
 * pre-condicao: contribuicao deve ser previamente inicializada
 * pos-condicao: estado da contribuicao alterado  */
void AlteraEstadoContribuicao(Contribuicao *contribuicao);

/*----------------------------------------------------------------------
 * Destroi a contribuicao
 * inputs: a contribuicao
 * output: -
 * pre-condicao: contribuicao deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado */
void DestroiContribuicao(Contribuicao *contribuicao);

#endif /* CONTRIBUICAO_H */