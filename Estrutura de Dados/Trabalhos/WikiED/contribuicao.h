#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct contribuicao Contribuicao;

Contribuicao *InicializaContribuicao(char *texto, char *nomeDoArquivo);

void ImprimeContribuicao(Contribuicao *contribuicao, FILE *arquivo);

char *RetornaTextoContribuicao(Contribuicao *contribuicao);

int RetornaFlagContribuicao(Contribuicao *contribuicao);

char *RetornaNomeDoArquivoContribuicao(Contribuicao *contribuicao);

void AlteraEstadoContribuicao(Contribuicao *contribuicao);

int ContribuicaoFoiRetirada(Contribuicao *contribuicao);

void DestroiContribuicao(Contribuicao *contribuicao);

#endif /* CONTRIBUICAO_H */