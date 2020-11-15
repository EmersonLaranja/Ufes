/*
  listaContribuicoes.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef LISTACONTRIBUICOES_H
#define LISTACONTRIBUICOES_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "contribuicao.h"
#include "editor.h"

/* Define o tipo ListaContribuicoes (tipo opaco)*/
typedef struct listaContribuicoes ListaContribuicoes;

/* Define o tipo celulaContribuicao (tipo opaco)*/
typedef struct celulaContribuicao CelulaContribuicao;

/*----------------------------------------------------------------------
 * Inicializa a lista de contribuicoes
 * inputs: -
 * output: lista de contribuicoes inicializada
 * pre-condicao: -
 * pos-condicao: sentinela da lista de contribuicoes existe e os campos primeira e ultima apontam para NULL  */
ListaContribuicoes *InicializaListaContribuicoes(void);

/*----------------------------------------------------------------------
*Insere uma contribuicao na ultima posição da lista de contribuicoes
* inputs: a lista de contribuicoes, a contribuicao a ser inserida na lista  e o editor da contribuicao (do tipo Editor)  
* output: nenhum
* pre-condicao:  lista de contribuicoes, contribuicao e editor não são nulos
* pos-condicao: lista contém a contribuicao inserida na ultima posição
*/
void InsereContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao, Editor *editor);
/*----------------------------------------------------------------------
*Imprime uma lista de contribuicoes
* inputs: a lista de contribuicoes e ponteiro do arquivo de saída
* output: arquivo de saida com contribuicoes da lista de contribuicoes
* pre-condicao: lista de contribuicoes  não é nula o ponteiro do arquivo deve estar valido!
* pos-condicao: dados da lista de contribuicoes impressos na saida padrao no arquivo de saida que foi gerado
*/
void ImprimeListaContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo);

/*----------------------------------------------------------------------
* Imprime o estado das contribuicoes de uma lista de contribuicoes
* inputs: a lista de contribuicoes e ponteiro do arquivo de saída
* output: arquivo de saida com contribuicoes da lista de contribuicoes
* pre-condicao: lista de contribuicoes  não é nula o ponteiro do arquivo deve estar valido!
* pos-condicao: dados relativo ao estado das contribuicoes da lista de contribuicoes impressos na saida padrao no arquivo de saida que foi gerado
*/
void ImprimeHistoricoContribuicoes(ListaContribuicoes *listaContribuicoes, FILE *arquivo);

/*----------------------------------------------------------------------
 * Retorna a celula de contribuicao de uma lista de contribuicoes
 * inputs: a lista de contribuicoes e uma contribuicao 
 * output: a celula de contribuicao
 * pre-condicao: lista de contribuicoes e contribuicao devem ser previamente inicializadas
 * pos-condicao: funcao nao altera o estado da contribuicao   */
CelulaContribuicao *RetornaCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, Contribuicao *contribuicao);

/*----------------------------------------------------------------------
 * Retorna uma contribuicao de uma lista de contribuicoes (procurando uma contribuicao pelo nome de seu arquivo)
 * inputs: a lista de contribuicoes e o nome do arquivo da contribuicao 
 * output: a contribuicao
 * pre-condicao: lista de contribuicoes deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da contribuicao */
Contribuicao *RetornaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo);

/*----------------------------------------------------------------------
 * Retorna um editor de uma lista de contribuicoes (procurando um editor pelo nome do editor)
 * inputs: a lista de contribuicoes e o nome do editor
 * output: o editor
 * pre-condicao: lista de contribuicoes deve ser previamente inicializada
 * pos-condicao: funcao nao altera o estado da contribuicao */
Editor *RetornaEditorListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeEditor);

/*----------------------------------------------------------------------
 * Altera o estado da flag de uma lista de contribuicoes (indicando se ela foi retirada ou não)
 * inputs: a lista de contribuicoes
 * output: -
 * pre-condicao: a lista de contribuicoes deve ser previamente inicializada
 * pos-condicao: estado das contribuicoes da lista alterado  */
void AlteraEstadoContribuicoesListaContribuicoes(ListaContribuicoes *listaContribuicoes);

/*----------------------------------------------------------------------
* Retira uma contribuicao de uma lista de contribuicoes (procurando um editor pelo nome do arquivo de contribuicao)
* inputs: a lista de contribuicoes e o nome do arquivo de contribuicao
* output: a contribuicao retirada da lista de contribuicoes ou NULL, se não se encontrar na lista de contribuicoes
* pre-condicao: lista não é nula
* pos-condicao: lista não contém a contribuicao com nome do arquivo de contribuicao
*/
void RetiraCelulaContribuicaoListaContribuicoes(ListaContribuicoes *listaContribuicoes, char *nomeArquivo);

/*----------------------------------------------------------------------
 * Destroi os nos da lista de contribuicoes
 * inputs: os nos da lista de contribuicoes
 * output: -
 * pre-condicao: lista de contribuicoes deve ser previamente inicializada
 * pos-condicao: espaco de memoria das celulas liberados, nao libera as contribuicoes */
void DestroiNosListaContribuicoes(ListaContribuicoes *listaContribuicoes);

/*----------------------------------------------------------------------
 * Destroi a lista de contribuicoes
 * inputs: a lista de contribuicoes
 * output: -
 * pre-condicao: lista de contribuicoes deve ser previamente inicializada
 * pos-condicao: todo o espaco de memoria deve ser liberado, libera as contribuicoes*/
void DestroiListaContribuicoes(ListaContribuicoes *listaContribuicoes);

#endif /* LISTACONTRIBUICOES_H */