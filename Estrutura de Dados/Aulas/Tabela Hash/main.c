#include "hash.h"
#include <ctype.h>

#define NPAL 64
#define NTAB 127

int LePalavra(FILE *fp, char *s)
{
  int i = 0;
  int c;

  while ((c = fgetc(fp) != EOF))
  {
    if (isalpha(c))
      break;
  }
  if (c == EOF)
    return 0;

  s[i++] = c;
  while ((i < NPAL - 1) && (c = fgetc(fp)) != EOF && isalpha(c))
  {
    s[i++] = c;
  }
  return i;
}

int main(int argc, char *argv[])
{
  FILE *fp;
  Hash *tab;
  char s[NPAL];

  if (argc != 2)
  {
    printf("Arquivo nao encontrado!\n");
    return 0;
  }

  fp = fopen(argv[1], "rt");

  if (fp == NULL)
  {
    printf("Erro na abertura do arquivo!\n");
    return 0;
  }

  tab = InicializaHash(NTAB);

  while (LePalavra(fp, s))
  {
    Palavra *p = Acessa(tab, s);
    AtualizaOcorrencias(p);
  }
  ImprimeHash(tab);

  LiberaHash(tab);
  return 0;
}