#include "contribuicao.h"
#define SIM 1
#define NAO 0
struct contribuicao
{
  char *nomeArquivo; //nome do arquivo de contribuição: tipo c8.txt
  // char *texto;
  int foiRetirada;
};

Contribuicao *InicializaContribuicao(char *nomeArquivo)
{
  Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
  // contribuicao->texto = strdup(texto);
  contribuicao->nomeArquivo = strdup(nomeArquivo);
  contribuicao->foiRetirada = NAO; //inicialmente, a contribuicao mesmo vazia eh considerada como nao retirada
  return contribuicao;
};

void ImprimeContribuicao(Contribuicao *contribuicao, char *nomeArquivo)
{
  //TODO Abrir o arquivo e imprimir com o nome dentro da contribuição
  if (contribuicao == NULL)
  {
    printf("Contribuicao invalida\n");
    return;
  }
  if (contribuicao->foiRetirada == NAO)
  {
    char c;

    FILE *arquivoOrigem = fopen(RetornaNomeArquivoContribuicao(contribuicao), "r");

    FILE *arquivoCopia = fopen(nomeArquivo, "w");

    if (arquivoOrigem == NULL)

    {

      printf("Problema na leitura do arquivo\n");

      return;
    }

    while (1)

    {

      c = fgetc(arquivoOrigem);

      if (c == EOF)

      {

        break;
      }

      fprintf(arquivoCopia, "%c", c);
    };

    fclose(arquivoOrigem);

    fclose(arquivoCopia);
  }
};

// char *RetornaTextoContribuicao(Contribuicao *contribuicao)
// {
//   if (contribuicao == NULL)
//   {
//     return NULL;
//   }
//   return contribuicao->texto;
// };

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
  contribuicao->foiRetirada = SIM;
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
    free(contribuicao->nomeArquivo);
    free(contribuicao);
  }
};
