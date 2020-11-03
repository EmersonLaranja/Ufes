#ifndef PAGINA_H
#define PAGINA_H

typedef struct pagina Pagina;

Pagina *InicializaPagina(char *nome);

void ImprimePagina(Pagina *pagina);

char *RetornaNomePagina(Pagina *pagina);

void DestroiPagina(Pagina *pagina);

#endif /* PAGINA_H */