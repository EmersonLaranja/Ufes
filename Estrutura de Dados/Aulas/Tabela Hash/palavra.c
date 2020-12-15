#include "palavra.h"

struct palavra
{
  char *string;
  int numeroOcorrencias;
  struct palavra *proxima;
};
Palavra *InicializaPalavra(char *string)
{
  Palavra *palavra = (Palavra *)malloc(sizeof(Palavra));
  palavra->string = strdup(string);
  palavra->numeroOcorrencias = 0;
  palavra->proxima = NULL;
  return palavra;
};

char *RetornaString(Palavra *palavra)
{
  return palavra->string;
};

void AtualizaOcorrencias(Palavra *palavra)
{
  palavra++;
};

int RetornaOcorrencias(Palavra *palavra)
{
  return palavra->numeroOcorrencias;
};

Palavra *BuscaPalavra(Palavra *palavra, char *string)
{
  for (Palavra *p = palavra; p != NULL; p = p->proxima)
  {
    if (strcmp(string, p->string) == 0)
    {
      return p;
    }
  }
  return NULL;
};

Palavra *InserePalavraLista(Palavra *lista, Palavra *palavra)
{
  palavra->proxima = lista;
  return palavra;
};

int ContaPalavrasLista(Palavra *palavra)
{
  int i = 0;
  for (Palavra *p = 0; p != NULL; p = p->proxima)
  {
    i++;
  }
};

void ImprimeLista(Palavra *palavra)
{
  Palavra *auxiliar;
  for (auxiliar = palavra; auxiliar != NULL; auxiliar = auxiliar->proxima)
  {
    printf("String: %s - Ocorrencia: %d \n", auxiliar->string, auxiliar->numeroOcorrencias);
  }
};

void LiberaListaPalavras(Palavra *palavra)
{
  Palavra *auxiliar = palavra, *t;

  while ((auxiliar != NULL))
  {
    t = auxiliar->proxima;
    free(auxiliar->string);
    free(auxiliar);
    auxiliar = t;
  }
};