
#include "pagina.h"

struct pagina
{
  char *nomePagina;
  char *nomeArquivo;
};

Pagina *InicializaPagina(char *nomePagina, char *nomeArquivo)
{
  Pagina *pagina = (Pagina *)malloc(sizeof(Pagina));
  pagina->nomePagina = strdup(nomePagina);
  pagina->nomeArquivo = strdup(nomeArquivo);
  return pagina;
}

void ImprimePagina(Pagina *pagina, FILE *arquivo)
{
  if (pagina)
  {
    printf("%s\n\n", pagina->nomePagina); //! Soh pra eu visualizar, Retirar depois
    fprintf(arquivo, "%s\n\n", pagina->nomePagina);
  }
}

char *RetornaNomePagina(Pagina *pagina)
{
  return pagina->nomePagina;
}

char *RetornaNomeArquivoPagina(Pagina *pagina)
{
  return pagina->nomeArquivo;
}

void DestroiPagina(Pagina *pagina)
{
  if (pagina)
  {
    free(pagina->nomePagina);
    free(pagina->nomeArquivo);
    free(pagina);
  }
}
