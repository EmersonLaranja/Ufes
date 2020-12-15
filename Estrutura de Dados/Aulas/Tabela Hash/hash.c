#include "hash.h"

struct hash
{
  Palavra **vetor;
  int tamanho;
};

Hash *InicializaHash(int tamanho)
{
  Hash *h = (Hash *)malloc(sizeof(Hash));

  h->tamanho = tamanho;
  h->vetor = (Palavra **)malloc(sizeof(Palavra *));

  for (int i = 0; i < tamanho; i++)
  {
    h->vetor[i] = NULL;
  }
  return h;
};

static int FazHash(char *s, int tamanho)
{
  int total = 0, i;

  for (i = 0; s[i] != '\0'; i++)
  {
    total += s[i];
  }
  return total % tamanho;
}

Palavra *Acessa(Hash *hash, char *string)
{
  int indice = FazHash(string, hash->tamanho);
  Palavra *palavra = BuscaPalavra(hash->vetor[indice], string);

  if (palavra)
    return palavra;

  palavra = InicializaPalavra(string);

  hash->vetor[indice] = InserePalavraLista(hash->vetor[indice], palavra);

  return palavra;
};

int contaPalavras(Hash *hash)
{
  int soma = 0;

  for (int i = 0; i < hash->tamanho; i++)
  {
    soma += ContaPalavrasLista(hash->vetor[i]);
  }

  return soma;
};

void ImprimeHash(Hash *hash)
{
  for (int i = 0; i < hash->tamanho; i++)
  {
    printf("\nPosicao vet[%d]: \n", i);
    ImprimeLista(hash->vetor[i]);
  }
};

void LiberaHash(Hash *hash)
{

  for (int i = 0; i < hash->tamanho; i++)
    LiberaListaPalavras(hash->vetor[i]);
  free(hash->vetor);
  free(hash);
};
