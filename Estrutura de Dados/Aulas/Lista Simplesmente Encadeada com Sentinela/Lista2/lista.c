#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
struct tipoitem
{
  char *endereco;
  char *nome;
  int matricula;
};
/*
Tipo que define os elementos de uma lista
*/
struct celula
{
  TipoItem *aluno;
  Celula *proxima;
};
/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista COM Sentinela
  */
struct tipolista
{
  Celula *inicio;
  Celula *fim;
};

TipoLista *InicializaLista()
{
  TipoLista *lista = (TipoLista *)malloc(sizeof(TipoLista));
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}

void Insere(TipoItem *aluno, TipoLista *lista)
{
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->aluno = aluno;
  nova->proxima = lista->inicio;
  lista->inicio = nova;

  if (lista->fim == NULL)
    lista->fim = nova;
}

TipoItem *Retira(TipoLista *lista, int mat)
{
  Celula *anterior = NULL, *i = lista->inicio, *j = i;
  TipoItem *alunoAuxiliar = NULL;
  for (i; i != NULL; i = i->proxima)
  {
    anterior = NULL;
    for (j = i; j != NULL;)
    {
      if (j->aluno->matricula == mat)
      {
        alunoAuxiliar = j->aluno;

        if (j == NULL)
        {
          return NULL;
        }
        if (lista->inicio == j && lista->fim == j)
        {
          lista->inicio = lista->fim = NULL;
          DeletaTipoItem(j->aluno);
          free(j);
          return alunoAuxiliar;
        }
        else if (lista->inicio == j)
        {
          i = lista->inicio = j->proxima;
          DeletaTipoItem(j->aluno);
          free(j);
          j = NULL;
        }
        else if (lista->fim == j)
        {
          lista->fim = anterior;
          anterior->proxima = NULL;
          DeletaTipoItem(j->aluno);
          free(j);
          j = NULL;
        }
        else
        {
          anterior->proxima = j->proxima;
          DeletaTipoItem(j->aluno);
          free(j);
          j = anterior->proxima;
        }
      }
      else
      {
        anterior = j;
        j = j->proxima;
      }
    }
  }
  return alunoAuxiliar;
};

void Imprime(TipoLista *lista)
{
  for (Celula *i = lista->inicio; i != NULL; i = i->proxima)
  {
    printf("NOME: %s\nMATRICULA: %d\nENDERECO: %s\n\n", i->aluno->nome, i->aluno->matricula, i->aluno->endereco);
  }
};

TipoLista *Libera(TipoLista *lista)
{
  Celula *celulaAtual = lista->inicio;
  Celula *celulaSucessora = NULL;
  while (celulaAtual != NULL)
  {
    celulaSucessora = celulaAtual->proxima;
    free(celulaAtual->aluno->nome);
    free(celulaAtual->aluno->endereco);
    free(celulaAtual->aluno);
    free(celulaAtual);
    celulaAtual = celulaSucessora;
  }
  free(lista);
  lista = NULL;
  return lista;
}

TipoItem *InicializaTipoItem(char *nome, int matricula, char *endereco)
{
  TipoItem *aluno = (TipoItem *)malloc(sizeof(TipoItem));
  aluno->nome = strdup(nome);
  aluno->matricula = matricula;
  aluno->endereco = strdup(endereco);
  return aluno;
}

void *DeletaTipoItem(TipoItem *item)
{
  free(item->endereco);
  free(item->nome);
  free(item);
}