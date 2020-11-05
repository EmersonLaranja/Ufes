#ifndef PAGINA_H
#define PAGINA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct pagina Pagina;

Pagina *InicializaPagina(char *nomeDaPagina, char *nomeDoArquivo);

void ImprimePagina(Pagina *pagina, FILE *arquivo);

char *RetornaNomePagina(Pagina *pagina);

char *RetornaNomeArquivo(Pagina *pagina);

void DestroiPagina(Pagina *pagina);

#endif /* PAGINA_H */