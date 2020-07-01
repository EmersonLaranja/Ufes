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
  Celula *anterior;
  Celula *atual = lista->inicio;
  TipoItem *alunoAuxiliar;

  while (atual != NULL && (mat != atual->aluno->matricula))
  {
    anterior = atual;
    atual = atual->proxima;
  }

  //não encontrou ou a lista é vazia
  if (atual == NULL)
  {
    return NULL;
  }

  alunoAuxiliar = atual->aluno;

  //lista unica
  if (lista->inicio == atual && lista->fim == atual)
  {
    free(lista->inicio);
    lista->inicio = NULL;
    lista->fim = NULL;
  }
  //elemento no inicio (primeira posição)
  else if (lista->inicio == atual)
  {
    free(lista->inicio);
    lista->inicio = atual->proxima;
  }

  //elemento no fim (ultima posição)
  else if (lista->fim == atual)
  {
    free(lista->fim);
    lista->fim = anterior;
    anterior->proxima = NULL;
  }

  else
  { //no meio da lista (a,b)
    anterior->proxima = atual->proxima;
    free(atual);
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