#ifndef ARV_H_
#define ARV_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;

/*-------------------------------------------------------------------------
Cria uma arvore vazia;
 *inputs:-;
 *outputs: arvore vazia;
 *pré-condição: - ;
 *pós-condição: arvore vazia foi retornada (valor NULL);
*/
Arvore *CriaArvoreVazia(void);

/*-------------------------------------------------------------------------
Inicializa uma arvore;
 *inputs:-
 *outputs: endereço do tipo Arvore*;
 *pré-condição: - ;
 *pós-condição: arvore foi alocada e inicializada;
*/
Arvore *CriaArvore(void);

/*-------------------------------------------------------------------------
Insere um operando em uma arvore;
 *inputs: uma arvore (tipo Arvore*) e um numero operando (tipo inteiro);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, numero como inteiro;
 *pós-condição: (Arvore*) mddificada, numero inserido;
*/
Arvore *InsereOperandoArvore(Arvore *arvore, int operando);

/*-------------------------------------------------------------------------
Insere determinado operador em uma determinada arvore;
 *inputs: (Arvore*), (char operador);
 *outputs: (Arvore*);
 *pré-condição: (Arvore*) existente, operador como char;
 *pós-condição: (Arvore*) mddificada, operador inserido;
*/
Arvore *InsereOperadorArvore(Arvore *arvore, char operador);

/*-------------------------------------------------------------------------
Retorna o status da árvore, se está vazia ou não;
 *inputs: (Arvore*);
 *outputs: (int);
 *pré-condição: (Arvore*) existente;
 *pós-condição: int alocado;
*/
int ArvoreEhVazia(Arvore *arvore);

/*-------------------------------------------------------------------------
Retorna valor do operador da arvore;
 *inputs: uma arvore (tipo Arvore*);
 *outputs: operador (tipo char);
 *pré-condição: uma arvore (tipo Arvore*) inicializada;
 *pós-condição: - ;
*/
char RetornaOperador(Arvore *arvore);

/*-------------------------------------------------------------------------
Retorna valor do operando da arvore;
 *inputs: uma arvore (tipo Arvore*);
 *outputs: operando (tipo int);
 *pré-condição: uma arvore (tipo Arvore*) inicializada;
 *pós-condição: - ;
*/
int RetornaOperando(Arvore *arvore);

/*-------------------------------------------------------------------------
Monta a arvore a partir da equação dada;
 *inputs: uma arvore (tipo Arvore*),string (char *expressão),inteiro da posicao na expressao (int *posição);
 *outputs: uma arvore (tipo Arvore*);
 *pré-condição: uma arvore (tipo Arvore*) existente, expressão existente, posição existente;
 *pós-condição: (Arvore*) modificada;
*/
Arvore *MontaArvore(Arvore *arvore, char *expressao, int *posicao);

/*-------------------------------------------------------------------------
Retorna valor calculado da expressao de uma arvore;
 *inputs: uma arvore (tipo Arvore*);
 *outputs: resultado (tipo float);
 *pré-condição: uma arvore (tipo Arvore*) inicializada;
 *pós-condição: float existente;
*/
float CalculaEquacao(Arvore *arvore);

/*-------------------------------------------------------------------------
Libera o espaço de memória ocupado pela árvore;
 *inputs: uma arvore (tipo Arvore*);
 *outputs: - ;
 *pré-condição:-;
 *pós-condição:endereço de memoria liberado;
*/
Arvore *LiberaArvore(Arvore *arvore);

/*-------------------------------------------------------------------------
 Preenche uma arvore com a expressao passada;
 *inputs: uma arvore (tipo Arvore*) ,e uma string com a expressao (char *expressao);
 *outputs: arvore (tipo Arvore*) preenchida;
 *pré-condição: arvore (tipo Arvore*) inicializada;
 *pós-condição: arvore (tipo Arvore*) existente;
*/
Arvore *PreencheArvore(Arvore *arvore, char *expressao);

/*-------------------------------------------------------------------------
 Retorna valor da expressao da arvore;
 *inputs: Arvore (tipo Arvore*);
 *outputs: float ;
 *pré-condição: Arvore (tipo Arvore*) inicializada;
 *pós-condição: - ;
*/
float ResultadoExpressao(Arvore *arvore);

/*-------------------------------------------------------------------------
 Imprime resultado;
 *inputs: arquivo de saida, resultado (tipo float);
 *outputs: - ;
 *pré-condição: ponteiro para arquivo valido;
 *pós-condição: resultado não modificado;
*/
void ImprimeResultado(FILE *arquivoSaida, float resultado);

#endif /*ARV_H_*/
