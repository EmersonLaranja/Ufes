#ifndef LISTADEALUNOS_H_
#define LISTADEALUNOS_H_

#include "listaGenerica.h"
#include "aluno.h"

float CalculaMediaTurma(ListaGenerica *lista);

int PertenceAluno(ListaGenerica *lista, int matricula);

void ImprimeListaAlunos(ListaGenerica *lista);

ListaGenerica *RetiraAluno(ListaGenerica *lista, int matricula);

#endif /* LISTADEALUNOS_H_ */