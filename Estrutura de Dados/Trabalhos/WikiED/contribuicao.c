#include "contribuicao.h"
#define SIM 1
#define NAO 0
struct contribuicao
{
  char *nomeArquivo; //nome do arquivo de contribuicao: tipo c8.txt
  int foiRetirada;   //flag para controlar se uma contribuicao foi retirada
};

Contribuicao *InicializaContribuicao(char *nomeArquivo)
{
  Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
  contribuicao->nomeArquivo = strdup(nomeArquivo); //alocando e enderecando o argumento recebido
  contribuicao->foiRetirada = NAO;                 //inicialmente, a contribuicao mesmo vazia eh considerada como nao retirada
  return contribuicao;
};

int RetornaFlagContribuicao(Contribuicao *contribuicao)
{
  return contribuicao->foiRetirada;
};

char *RetornaNomeArquivoContribuicao(Contribuicao *contribuicao)
{
  if (contribuicao == NULL)
  {
    return NULL;
  }
  return contribuicao->nomeArquivo;
};

void AlteraEstadoContribuicao(Contribuicao *contribuicao)
{
  contribuicao->foiRetirada = SIM; //o estado eh alterado ao retirar uma contribuicao
};

void DestroiContribuicao(Contribuicao *contribuicao)
{
  if (contribuicao)
  {
    free(contribuicao->nomeArquivo);
    free(contribuicao);
  }
};
