#include "comandos.h"

#define CAMINHO_ARQUIVO_LOG "log.txt"
#define TAM_COMANDO 50
#define TAM_ARGUMENTO 25

int main(int argc, char *argv[])
{
  char consomeLixo = '0', comando[TAM_COMANDO],
       argumento1[TAM_ARGUMENTO],
       argumento2[TAM_ARGUMENTO],
       argumento3[TAM_ARGUMENTO];

  FILE *arquivo = fopen(argv[1], "r"); //abrindo arquivo no modo de leitura
  if (arquivo == NULL)                 //algum problema no arquivo
  {
    printf("Problema na leitura do arquivo");
    return 0;
  }

  FILE *arquivoLog = fopen(CAMINHO_ARQUIVO_LOG, "w"); //abrindo arquivo no modo de escrita

  ListaPaginas *listaPaginas = InicializaListaPaginas();
  ListaEditores *listaEditores = InicializaListaEditores();

  //consumindo todo lixo do inicio do arquivo
  while (!(consomeLixo >= 'a' && consomeLixo <= 'z') && !(consomeLixo >= 'A' && consomeLixo <= 'Z'))
  {
    fscanf(arquivo, "%c", &consomeLixo);
  }

  //concatenando o comando ate formar uma palavra, processo eh feito 1 vez para evitar qualquer lixo no comeco do codigo
  comando[0] = consomeLixo;
  for (int i = 1; consomeLixo != ' '; i++)
  {
    fscanf(arquivo, "%c", &consomeLixo);
    if (consomeLixo != ' ')
    {
      comando[i] = consomeLixo;
    }
    else
    {
      comando[i] = '\0';
    }
  }

  do
  {

    if (strcmp(comando, "INSEREPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      INSEREPAGINA(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "RETIRAPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      RETIRAPAGINA(listaPaginas, argumento1, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSEREEDITOR") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      INSEREEDITOR(listaEditores, argumento1, arquivoLog);

      continue;
    }

    if (strcmp(comando, "INSERECONTRIBUICAO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      INSERECONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);

      continue;
    }

    if (strcmp(comando, "RETIRACONTRIBUICAO") == 0)
    {

      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      fscanf(arquivo, "%s", argumento3);
      RETIRACONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, arquivoLog);
      continue;
    }

    if (strcmp(comando, "INSERELINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      INSERELINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "RETIRALINK") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      RETIRALINK(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "CAMINHO") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      fscanf(arquivo, "%s", argumento2);
      CAMINHO(listaPaginas, argumento1, argumento2, arquivoLog);
      continue;
    }

    if (strcmp(comando, "IMPRIMEPAGINA") == 0)
    {
      fscanf(arquivo, "%s", argumento1);
      IMPRIMEPAGINA(listaPaginas, argumento1, arquivoLog);
      continue;
    }

    if (strcmp(comando, "IMPRIMEWIKED") == 0)
    {
      // fprintf(arquivoLog, "IMPRIMEWIKED\n");
      IMPRIMEWIKED(listaPaginas, arquivoLog);
      continue;
    }

    if (strcmp(comando, "FIM") == 0)
    {
      FIM(listaPaginas, listaEditores);
      break;
    }

    else
    {
      fprintf(arquivoLog, "Comando <%s> disponivel apenas na versao premium\n", comando);
      fscanf(arquivo, "%[^\n]\n", comando);
    }

  } while (fscanf(arquivo, "%s", comando) != EOF); // enquanto nao eh o final do arquivo

  fclose(arquivo);
  fclose(arquivoLog);
  return 0;
}
