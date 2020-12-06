#include "abb.h"

struct arv
{
  Aluno *info;
  Arv *esq;
  Arv *dir;
};

Arv *abb_cria(void)
{
  return NULL;
}

void *abb_imprime(Arv *a)
{
  printf("<");
  if (a != NULL)
  {
    abb_imprime(a->esq);
    ImprimeAluno(a->info);
    abb_imprime(a->dir);
  }
  printf(">");
}

Arv *abb_busca(Arv *a, int chave)
{
  if (a = NULL)
    return NULL;

  else if (RetornaMatricula(a->info) > chave)
    return abb_busca(a->esq, chave);

  else if (RetornaMatricula(a->info) < chave)
    return abb_busca(a->dir, chave);

  else
    return a;
}

Arv *abb_insere(Arv *a, Aluno *aluno)
{

  if (a == NULL)
  {
    a = (Arv *)malloc(sizeof(Arv));
    a->info = aluno;
    a->esq = a->dir = NULL;
  }

  //procura onde inserir
  else if (RetornaMatricula(aluno) < RetornaMatricula(a->info))
    a->esq = abb_insere(a->esq, aluno);

  // else if (RetornaMatricula(aluno) > RetornaMatricula(a->info)) //acho que eh assim
  else
    a->dir = abb_insere(a->dir, aluno);

  return a;
}

Arv *abb_retira(Arv *a, int v)
{

  if (a == NULL)
    return NULL;

  else if (RetornaMatricula(a->info) > v)
    a->esq = abb_retira(a->esq, v);

  else if (RetornaMatricula(a->info) < v)
    a->dir = abb_retira(a->dir, v);

  //achamos
  else
  {
    //caso no folha
    if (a->esq == NULL && a->dir == NULL)
    {
      free(a);
      a = NULL;
    }

    //caso 1 filho a direita
    else if (a->esq == NULL)
    {
      Arv *t = a;
      a = a->dir;
      free(t);
    }
    //caso 1 filho a esquerda
    else if (a->dir == NULL)
    {
      Arv *t = a;
      a = a->esq;
      free(t);
    }
    //caso 2 filhos
    else
    {
      //buscando o antecessor do nó
      Arv *f = a->esq;
      while (f->dir != NULL)
        f = f->dir;
      //troca de info
      Aluno *t = a->info;
      a->info = f->info;
      f->info = t;
      //recursao para o nó em alguma das situações anteriores
      a->esq = abb_retira(a->esq, v);
    }
  }
  return a;
}

Arv *abb_libera(Arv *a)
{
  if (a != NULL)
  {
    abb_libera(a->esq);
    abb_libera(a->dir);
    free(a); //liberando a raiz
  }

  return NULL;
}