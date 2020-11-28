/*
  comandos.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/18/2020.
*/

#ifndef COMANDOS_H
#define COMANDOS_H
#include "listaPaginas.h"
#include "listaEditores.h"

/*----------------------------------------------------------------------
 * Cria uma página WikED! com o nome e o arquivo especificados
 * inputs: lista de paginas, nome da pagina, nome do arquivo, arquivo de log
 * output: -
 * pre-condicao: lista de paginas  não é nula o ponteiro do arquivo deve estar valido!
 * pos-condicao: pagina inserida na lista de todas as paginas da WikED!  */
void INSEREPAGINA(ListaPaginas *listaPaginas, char *nomePagina, char *nomeArquivo, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * exclui a página da WikED!, excluindo, portanto, a lista de contribuições e links.
 * inputs: lista de paginas, nome da pagina, arquivo de log
 * output: -
 * pre-condicao: lista de paginas  não é nula o ponteiro do arquivo deve estar valido!
 * pos-condicao: pagina e sua lista de links destruida. NAO destroi as contribuicoes da pagina, apenas as celulas e a lista de contribuicoes  */
void RETIRAPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Insere um editor com o nome especificado
 * inputs: lista de editores, nome do editor, arquivo de log
 * output: -
 * pre-condicao: lista de editores  não é nula o ponteiro do arquivo deve estar valido!
 * pos-condicao: editor inserido na lista de todos os editores da WikED!  */
void INSEREEDITOR(ListaEditores *listaEditores, char *nomeEditor, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Insere  um link (uma pagina) para página destino, na página origem.
 * inputs: lista de paginas, nome da pagina de origem,nome da pagina de destino, arquivo de log
 * output: -
 * pre-condicao: lista de paginas não é nula o ponteiro do arquivo deve estar valido!
 * pos-condicao: link para pagina de destino inserido na lista de links da pagina de origem  */
void INSERELINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Retira  um link (uma pagina) para página destino, na página origem.
 * inputs: lista de paginas, nome da pagina de origem,nome da pagina de destino, arquivo de log
 * output: -
 * pre-condicao: lista de paginas não é nula o ponteiro do arquivo deve estar valido!
 * pos-condicao: link para pagina de destino removida na lista de links da pagina de origem  */
void RETIRALINK(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Insere uma contribuição de um dado editor para uma determinada página.
 * inputs: lista de paginas e de editores, nome da pagina,nome do editor, nome do arquivo de contribuicao, arquivo de log
 * output: -
 * pre-condicao: listas não são nulas, nome do arquivo de contribuicao refere-se a uma contribuicao existente nas entradas e o ponteiro do arquivo deve estar valido!
 * pos-condicao: Contribuicao inserida na pagina passada (caso exista na lista de paginas) e no editor que eh dono da contribuicao (caso exista na lista de editores). */
void INSERECONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Retira uma contribuição de um dado editor para uma determinada página.
 * inputs: lista de paginas e de editores, nome da pagina,nome do editor, nome do arquivo de contribuicao, arquivo de log
 * output: -
 * pre-condicao: listas não são nulas, nome do arquivo de contribuicao refere-se a uma contribuicao existente nas entradas e o ponteiro do arquivo deve estar valido!
 * pos-condicao: Celula da contribuicao removida na pagina passada (caso exista na lista de paginas) e no editor que eh dono da contribuicao (caso exista na lista de editores). */
void RETIRACONTRIBUICAO(ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char *nomeEditor, char *nomeArquivoContribuicao, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Gera o arquivo de saida da pagina passada (caso exista) e a imprime no arquivo gerado.
 * inputs: lista de paginas, nome da pagina, arquivo de log
 * output: -
 * pre-condicao: lista de paginas não eh nula e o ponteiro do arquivo deve estar valido!
 * pos-condicao: Arquivo de saida da pagina gerado e preenchido com a pagina especificada*/
void IMPRIMEPAGINA(ListaPaginas *listaPaginas, char *nomePagina, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Gera os arquivos de saida de todas as paginas da wikED! e as imprime nos seus respectivos arquivos.
 * inputs: lista de paginas, arquivo de log
 * output: -
 * pre-condicao: lista de paginas não eh nula e o ponteiro do arquivo deve estar valido!
 * pos-condicao: Arquivos de saida das paginas gerados e preenchidos com as paginas da lista de paginas*/
void IMPRIMEWIKED(ListaPaginas *listaPaginas, FILE *arquivoLog);

void CAMINHO(ListaPaginas *listaPaginas, char *nomePaginaOrigem, char *nomePaginaDestino, FILE *arquivoLog);

/*----------------------------------------------------------------------
 * Determina o ponto de parada do programa, responsavel por liberar todo espaco de memoria alocado ate o fim.
 * inputs: lista de paginas e lista de editores
 * output: -
 * pre-condicao: lista de paginas e de editores não sao nulas
 * pos-condicao: Espaco de memoria liberado*/
void FIM(ListaPaginas *listaPaginas, ListaEditores *listaEditores);

#endif /*COMANDOS_H*/