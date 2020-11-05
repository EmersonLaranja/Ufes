#include "contribuicao.h"
#define SIM 1
#define NAO 0
struct contribuicao
{
  char *nomeDoArquivo; //nome do arquivo de contribuição: tipo c8.txt
  char *texto;
  int foiRetirada;
};

Contribuicao *InicializaContribuicao(char *texto, char *nomeDoArquivo)
{
  Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
  contribuicao->texto = strdup(texto);
  contribuicao->nomeDoArquivo = strdup(nomeDoArquivo);
  contribuicao->foiRetirada = NAO; //inicialmente, a contribuicao mesmo vazia eh considerada como nao retirada
  return contribuicao;
};

void ImprimeContribuicao(Contribuicao *contribuicao, FILE *arquivo)
{
  if (contribuicao && contribuicao->foiRetirada == NAO)
  {                                      //se tem a contribuicao e ela nao fora retirada
    printf("%s\n", contribuicao->texto); //! Soh pra eu visualizar, remover depois
    fprintf(arquivo, "%s\n", contribuicao->texto);
  }
};

char *RetornaTextoContribuicao(Contribuicao *contribuicao)
{
  return contribuicao->texto;
};

char *RetornaFlagContribuicao(Contribuicao *contribuicao)
{
  return contribuicao->foiRetirada;
};

char *RetornaNomeDoArquivoContribuicao(Contribuicao *contribuicao)
{
  return contribuicao->nomeDoArquivo;
};

void AlteraEstadoContribuicao(Contribuicao *contribuicao)
{
  if (contribuicao->foiRetirada == SIM)
  {
    contribuicao->foiRetirada = NAO;
  }
  else if (contribuicao->foiRetirada == NAO)
  {
    contribuicao->foiRetirada = SIM;
  }
};

int ContribuicaoFoiRetirada(Contribuicao *contribuicao)
{
  if (contribuicao->foiRetirada == SIM)
  {
    return 1;
  }

  return 0;
}

void DestroiContribuicao(Contribuicao *contribuicao)
{
  if (contribuicao)
  {
    free(contribuicao->texto);
    free(contribuicao->nomeDoArquivo);
    free(contribuicao);
  }
};
