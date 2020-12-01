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
    // DestroiAluno(a->al);
    free(a);
  }

  return NULL;
};

int arv_vazia(Arv *a)
{
  return a == NULL ? 1 : 0;
};

int arv_pertence(Arv *a, char *chave)
{
  if (arv_vazia(a))
  {
    return 0;
  }
  else
  {
    return strcmp(RetornaNome(a->al), chave) == 0 ||
           arv_pertence(a->esq, chave) ||
           arv_pertence(a->dir, chave);
  }
};

void *arv_imprime(Arv *a)
{
  printf("<");
  if (!arv_vazia(a))
  {
    ImprimeNomeAluno(a->al);
    // ImprimeAluno(a->al);
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

  if (((!arv_vazia(a->esq)) && (strcmp(RetornaNome(a->esq->al), RetornaNome(al))) == 0) ||
      ((!arv_vazia(a->dir)) && (strcmp(RetornaNome(a->dir->al), RetornaNome(al))) == 0))
    return a;

  Arv *aux = arv_pai(a->esq, al);

  if (aux == NULL)
    aux = arv_pai(a->dir, al);

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

  if (strcmp(RetornaNome(a->al), RetornaNome(al)) == 0)
    return (1 + ocorrencias(a->esq, al) + ocorrencias(a->dir, al));

  return (ocorrencias(a->esq, al) + ocorrencias(a->dir, al));
};

Aluno *RetornaAlunoArvore(Arv *a)
{
  if (!arv_vazia(a))
    return a->al;
  return 0;
};