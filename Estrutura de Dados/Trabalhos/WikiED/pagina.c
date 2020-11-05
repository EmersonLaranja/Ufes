
#include "pagina.h"

struct pagina
{
  char *nomeDaPagina;
  char *nomeDoArquivo;
};

Pagina *InicializaPagina(char *nomeDaPagina, char *nomeDoArquivo)
{
  Pagina *pagina = (Pagina *)malloc(sizeof(Pagina));
  pagina->nomeDaPagina = strdup(nomeDaPagina);
  pagina->nomeDoArquivo = strdup(nomeDoArquivo);
  return pagina;
}

void ImprimePagina(Pagina *pagina, FILE *arquivo)
{
  if (pagina)
  {
    printf("%s\n\n", pagina->nomeDaPagina); //! Soh pra eu visualizar, Retirar depois
    fprintf(arquivo, "%s\n\n", pagina->nomeDoArquivo);
  }
}

char *RetornaNomePagina(Pagina *pagina)
{
  return pagina->nomeDaPagina;
}

char *RetornaNomeArquivo(Pagina *pagina)
{
  return pagina->nomeDoArquivo;
}

void DestroiPagina(Pagina *pagina)
{
  if (pagina)
  {
    free(pagina->nomeDaPagina);
    free(pagina->nomeDoArquivo);
    free(pagina);
  }
}
