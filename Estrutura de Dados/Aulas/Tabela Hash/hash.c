#define _GNU_SOURCE

#include "palavra.h"
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash
{
  Palavra **vetor;
  int tamanho;
};

static int hash(char *s, int tamanho)
{
  int total = 0;

  for (int i = 0; s[i] != '\0'; i++)
  {
    total += s[i];
  }

  return (total % tamanho);
}

Hash *InicializaHash(int tamanho)
{

  Hash *h = (Hash *)malloc(sizeof(Hash));
  h->tamanho = tamanho;
  h->vetor = (Palavra **)malloc(tamanho * sizeof(Palavra *));

  for (int i = 0; i < tamanho; i++)
  {
    h->vetor[i] = NULL;
  }

  return h;
}

Palavra *Acessa(Hash *h, char *string)
{
  Palavra *p;

  int indice = hash(string, h->tamanho);
  p = BuscaPalavra(h->vetor[indice], string);

  if (p)
  {
    return p;
  }

  p = InicializaPalavra(string);
  h->vetor[indice] = InserePalavraLista(h->vetor[indice], p);

  return p;
}

void ImprimeHash(Hash *h)
{

  for (int i = 0; i < h->tamanho; i++)
  {
    printf("\nPosição vetor[%d]: \n ", i);
    ImprimeLista(h->vetor[i]);
  }
}

void LiberaHash(Hash *h)
{

  for (int i = 0; i < h->tamanho; i++)
  {
    LiberaListaPalavras(h->vetor[i]);
  }
  free(h->vetor);
  free(h);
}