//
//  produto.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

#ifndef produto_h
#define produto_h

/* Define o tipo TProduto (tipo opaco)
   Estrutura interna deste tipo eh definida na implementacao do TAD.
*/
typedef struct produto TProduto;

/*----------------------------------------------------------------------
 * Inicializa o produto
 * inputs: nome do produto e o numero de calorias
 * output: Produto inicializado
 * pre-condicao: nome devidamente alocado e numero de calorias valido
 * pos-condicao: Produto inicializado  */
TProduto *InicProd(char *nome, int calorias);

/*----------------------------------------------------------------------
 * Insere um ingrediente ao produto e incrementa o número de calorias do produto
 * inputs: o produto, a string que define o ingrediente
 * output: nada
 * pre-condicao: produto deve ser previamente inicializado e as strings devem ser validas
 * pos-condicao: Produto contem o ingrediente passado e o numero de calorias calculado */
void InsereIngrediente(TProduto *prod, char *ingrediente);

/*----------------------------------------------------------------------
 * Imprime o Produto, seu numero de calorias e todos os seus ingredientes
 * inputs: o produto e o ponteiro para o arquivo
 * output: nada
 * pre-condicao: produto deve ser previamente inicializado e o ponteiro do arquivo deve estar valido!
 * pos-condicao: funcao nao altera os dados do produto */
void ImprimeIngredientes(TProduto *prod);

/*----------------------------------------------------------------------
 * Destroi o produto e seus ingredientes (liberando a memoria)
 * inputs: o produto
 * output: NULL
 * pre-condicao: produto deve ser previamente inicializado
 * pos-condicao: todo o espaco de memoria deve ser liberado */
TProduto *DestroiProd(TProduto *prod);

/*----------------------------------------------------------------------
 * Verifica se o produto possui o ingrediente indicado
 * inputs: o produto e a string que define o ingrediente
 * output: 0 (nao achou) e 1 (achou o ingrediente)
 * pre-condicao: produto deve ser previamente inicializado
 * pos-condicao: todo o espaco de memoria deve ser liberado */
int VerificaIngrediente(TProduto *prod, char *ingrediente);

/*----------------------------------------------------------------------
 * Retorna o numero de calorias de um produto
 * inputs: o produto
 * output: calorias do produto
 * pre-condicao: produto deve ser previamente inicializado
 * pos-condicao: funcao nao altera os dados produto */
int Calorias(TProduto *prod);

/*----------------------------------------------------------------------
 * Retorna o nome do Produto
 * inputs: o produto
 * output: nome do produto
 * pre-condicao: produto deve ser previamente inicializado
 * pos-condicao: funcao nao altera os dados produto */
char *RetornaNome(TProduto *prod);

#endif /* produto_h */
