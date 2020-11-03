#ifndef LISTADECONTRIBUICOES_H
#define LISTADECONTRIBUICOES_H
#include "contribuicao.h"

typedef struct listaDeContribuicoes ListaDeContribuicoes;
typedef struct celulaDeContribuicao CelulaDeContribuicao;

ListaDeContribuicoes *InicializaListaDeContribuicoes(void);
void InsereContribuicaoNaListaDeContribuicoes(ListaDeContribuicoes *lista, Contribuicao *contribuicao);
void RemoveContribuicaoDaListaDeContribuicoes(ListaDeContribuicoes *lista, char *chave);
void RemoveListaDeContribuicoes(ListaDeContribuicoes *lista);

#endif /* LISTADECONTRIBUICOES_H */
