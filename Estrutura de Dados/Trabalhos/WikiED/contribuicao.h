#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H
#include "editor.h"

typedef struct contribuicao Contribuicao;

Contribuicao *InicializaContribuicao(Editor *editor, char *texto);

// void ImprimeContribuicao(Contribuicao *contribuicao);

Editor *RetornaEditorContribuicao(Contribuicao *contribuicao);

int ContribuicaoFoiRetirada(Contribuicao *contribuicao);

// void DestroiContribuicao(Contribuicao *contribuicao);

#endif /* CONTRIBUICAO_H */