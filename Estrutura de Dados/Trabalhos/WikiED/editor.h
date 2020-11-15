/*
  editor.h
  Trabalho de ED1 - WikED!
  Created by Emerson Laranja dos Santos on 11/15/2020.
*/

#ifndef EDITOR_H
#define EDITOR_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Define o tipo Editor (tipo opaco)*/
typedef struct editor Editor;

/*----------------------------------------------------------------------
 * Inicializa a editor
 * inputs: nome do editor
 * output: editor inicializado
 * pre-condicao: -
 * pos-condicao: editor inicializado  */
Editor *InicializaEditor(char *nome);

/*----------------------------------------------------------------------
 * Retorna o nome do editor
 * inputs: o editor
 * output: o nome do editor
 * pre-condicao: editor deve ser previamente inicializado
 * pos-condicao: funcao nao altera o estado da editor   */
char *RetornaNomeEditor(Editor *editor);

/*----------------------------------------------------------------------
 * Destroi o editor
 * inputs: o editor
 * output: -
 * pre-condicao: editor deve ser previamente inicializado
 * pos-condicao: todo o espaco de memoria deve ser liberado */
void DestroiEditor(Editor *editor);

#endif /* EDITOR_H */