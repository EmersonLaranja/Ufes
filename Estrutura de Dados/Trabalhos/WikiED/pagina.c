
#include "pagina.h"

struct pagina
{
  char *nomeDaPagina;
  char *nomeArquivo;
};

Pagina *InicializaPagina(char *nomeDaPagina, char *nomeArquivo)
{
  Pagina *pagina = (Pagina *)malloc(sizeof(Pagina));
  pagina->nomeDaPagina = strdup(nomeDaPagina);
  pagina->nomeArquivo = strdup(nomeArquivo);
  return pagina;
}

void ImprimePagina(Pagina *pagina, FILE *arquivo)
{
  if (pagina)
  {
    printf("%s\n\n", pagina->nomeDaPagina); //! Soh pra eu visualizar, Retirar depois
    fprintf(arquivo, "%s\n\n", pagina->nomeArquivo);
  }
}

char *RetornaNomePagina(Pagina *pagina)
{
  return pagina->nomeDaPagina;
}

char *RetornaNomeArquivoPagina(Pagina *pagina)
{
  return pagina->nomeArquivo;
}

void DestroiPagina(Pagina *pagina)
{
  if (pagina)
  {
    free(pagina->nomeDaPagina);
    free(pagina->nomeArquivo);
    free(pagina);
  }
}
