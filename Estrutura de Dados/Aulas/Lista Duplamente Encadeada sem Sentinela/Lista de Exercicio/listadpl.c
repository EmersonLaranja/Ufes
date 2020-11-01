#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
struct tipoitem
{
  char *nome;
  int matricula;
  char *endereco;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista duplamente encadeada sem Sentinela
  */
struct tipolistadpl
{
  TipoItem *item;
  TipoListaDpl *anterior;
  TipoListaDpl *proxima;
};

TipoListaDpl *Insere(TipoItem *aluno, TipoListaDpl *lista)
{
  TipoListaDpl *nova = (TipoListaDpl *)malloc(sizeof(TipoListaDpl));
  nova->item = aluno;
  nova->anterior = NULL;
  nova->proxima = lista;
  if (lista != NULL)
    lista->anterior = nova;
  return nova;
}

static TipoListaDpl *Busca(TipoListaDpl *lista, char *nome)
{
  for (TipoListaDpl *i = lista; i != NULL; i = i->proxima)
  {
    if (strcmp(i->item->nome, nome) == 0)
    {
      return i; //encontrado
    }
  }
  return NULL; //não encontrado
}

TipoListaDpl *Retira(TipoListaDpl *lista, char *nome)
{
  TipoListaDpl *res = Busca(lista, nome);
  if (res == NULL)
    return lista;

  if (res->anterior != NULL)
  {
    res->anterior->proxima = res->proxima;
  }
  else
  {
    lista = res->proxima;
  }

  if (res->proxima != NULL)
  {
    res->proxima->anterior = res->anterior;
  }
  else
  {
  }

  free(res->item->nome);
  free(res->item->endereco);
  free(res->item);
  free(res);
  return lista;
}

void Imprime(TipoListaDpl *lista)
{
  for (TipoListaDpl *i = lista; i != NULL; i = i->proxima)
  {
    printf("NOME: %s, MATRICULA %d, ENDERECO:%s\n", i->item->nome, i->item->matricula, i->item->endereco);
  }
}

TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco)
{
  TipoItem *nova = (TipoItem *)malloc(sizeof(TipoItem));
  nova->nome = strdup(nome);
  nova->matricula = matricula;
  nova->endereco = strdup(endereco);
  return nova;
}

TipoListaDpl *libera(TipoListaDpl *lista)
{
  TipoListaDpl *p = lista, *t;

  while (p != NULL)
  {
    t = p->proxima;
    free(p->item->nome);
    free(p->item->endereco);
    free(p->item);
    free(p);
    p = t;
  }
  return NULL;
}
