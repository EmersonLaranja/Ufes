/* 
 * File:   listaMat.h
 * Author: Emerson Laranja
 *
 * Created on 17 de Outubro de 2020, 14:30
 */

#ifndef LISTAMAT_H
#define LISTAMAT_H

#include "matriz.h"

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  */
typedef struct lista Lista;

/*Inicializa o sentinela de uma lista
* inputs: nenhum
* output: Sentinela inicializado
* pre-condicao: nenhuma
* pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL
*/
Lista *IniciaLista();

/*Insere uma matriz na primeira posição da lista de matrizes
* inputs: matriz a ser inserido na lista (do tipo TipoItem) e a lista
* output: nenhum
* pre-condicao: matriz e lista não são nulos
* pos-condicao: lista contém o matriz inserido na primeira posição
*/
void InsereLista(Lista *lista, Matriz *matriz);

/*Imprime os dados de todos as matrizes da lista
* inputs: a lista de matrizes
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados das matrizes impressos na saida padrao
*/
void ImprimeLista(Lista *lista);

/*Retira uma matriz de matrícula mat da lista de matrizes
* inputs: a lista e a posicao da matriz a ser retirada da lista
* output: a matriz retirada da lista ou NULL, se o matriz não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o matriz de matrícula mat
*/
Matriz *RetiraLista(Lista *lista, int posicao);

/*Libera toda a memória alocada para a lista 
* inputs: a lista encadeada de matrizes
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada (memoria da matrizes não deve ser liberada aqui)
*/
void DestroiLista(Lista *lista);

#endif /* LISTAMAT_H */
