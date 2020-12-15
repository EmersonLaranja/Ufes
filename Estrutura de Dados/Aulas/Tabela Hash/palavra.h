#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PALAVRA_H_
#define PALAVRA_H_

typedef struct palavra Palavra;

Palavra *InicializaPalavra(char *string);

char *RetornaString(Palavra *palavra);

void AtualizaOcorrencias(Palavra *palavra);

int RetornaOcorrencias(Palavra *palavra);

Palavra *BuscaPalavra(Palavra *palavra, char *string);

Palavra *InserePalavraLista(Palavra *lista, Palavra *palavra);

int ContaPalavrasLista(Palavra *palavra);

void ImprimeLista(Palavra *palavra);

void LiberaListaPalavras(Palavra *palavra);
#endif /*PALAVRA_H_*/