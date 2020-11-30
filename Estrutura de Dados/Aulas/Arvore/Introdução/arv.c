#include "arv.h"

struct arv
{
  Aluno *al;
  Arv *esq;
  Arv *dir;
};

Arv *arv_criavazia(void)
{
  return NULL;
};

Arv *arv_cria(Aluno *al, Arv *sae, Arv *sad)
{
  Arv *p = (Arv *)malloc(sizeof(Arv));

  p->al = al;
  p->esq = sae;
  p->dir = sad;

  return p;
};

Arv *arv_libera(Arv *a)
{

  if (!arv_vazia(a))
  {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }

  return NULL;
};

int arv_vazia(Arv *a)
{
  return a == NULL ? 1 : 0;
};

int arv_pertence(Arv *a, Aluno *al)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    return a->info == c ||
           arv_pertence(a->esq, c) ||
           arv_pertence(a->dir, c);
  }
};

void *arv_imprime(Arv *a)
{
  printf("<");
  if (!arv_vazia(a))
  {
    printf("%c", a->info);
    arv_imprime(a->esq);
    arv_imprime(a->dir);
  }
  printf(">");
};

static int max2(int a, int b)
{
  return (a > b) ? a : b;
}

int arv_altura(Arv *a)
{
  if (arv_vazia(a))
    return -1;
  else
    return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
};

Arv *arv_pai(Arv *a, Aluno *al)
{
  if (arv_vazia(a))
    return NULL;

  if (((!arv_vazia(a->esq)) && (a->esq->info == c)) || ((!arv_vazia(a->dir)) && (a->dir->info == c)))
    return a;

  Arv *aux = arv_pai(a->esq, c);

  if (aux = NULL)
    aux = arv_pai(a->dir, c);

  return aux;
};

int folhas(Arv *a)
{
  if (arv_vazia(a->esq) && arv_vazia(a->dir))
    return 1;

  else if (!arv_vazia(a->esq) && arv_vazia(a->dir))
    return folhas(a->esq);

  else if (!arv_vazia(a->dir) && arv_vazia(a->esq))
    return folhas(a->dir);

  return folhas(a->esq) + folhas(a->dir);
};

int ocorrencias(Arv *a, Aluno *al)
{

  if (arv_vazia(a))
    return 0;

  if (a->info == c)
    return (1 + ocorrencias(a->esq, c) + ocorrencias(a->dir, c));

  return (ocorrencias(a->esq, c) + ocorrencias(a->dir, c));
};

int info(Arv *a)
{
  if (!arv_vazia(a))
    return a->info;
  return 0;
};