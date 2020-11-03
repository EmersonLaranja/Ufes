#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ListaDeContribuicoes.h"

struct celulaDeContribuicao
{
  Contribuicao *contribuicao;
  CelulaDeContribuicao *proxima;
};

struct listaDeContribuicoes
{
  CelulaDeContribuicao *primeira;
  CelulaDeContribuicao *ultima;
};

ListaDeContribuicoes *InicializaListaDeContribuicoes(void)
{
  ListaDeContribuicoes *lista = (ListaDeContribuicoes *)malloc(sizeof(ListaDeContribuicoes));
  lista->primeira = NULL;
  lista->ultima = NULL;
  return lista;
}
void InsereContribuicaoNaListaDeContribuicoes(ListaDeContribuicoes *lista, Contribuicao *contribuicao)
{
  CelulaDeContribuicao *nova = (CelulaDeContribuicao *)malloc(sizeof(CelulaDeContribuicao));
  nova->contribuicao = contribuicao;

  if (lista->primeira == NULL)
  {
    lista->primeira = nova;
    lista->ultima = nova;
  }
  lista->ultima->proxima = nova;
  lista->ultima = nova;
  nova->proxima = NULL;
}
void RemoveContribuicaoDaListaDeContribuicoes(ListaDeContribuicoes *lista, char *chave)
{
  CelulaDeContribuicao *auxiliar = lista->primeira, *anterior = NULL;

  while (auxiliar != NULL && strcmp(RetornaNomePagina(auxiliar->contribuicao), (chave)) != 0)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proxima;
  }

  if (auxiliar == NULL)
  {
    return;
  }

  if (auxiliar == lista->primeira && auxiliar == lista->ultima)
  {
    lista->primeira = lista->ultima = NULL;
  }
  else if (auxiliar == lista->primeira)
  {
    lista->primeira = auxiliar->proxima;
  }
  else if (auxiliar == lista->ultima)
  {
    lista->ultima = anterior;
    anterior->proxima = NULL;
  }
  else
  {
    anterior->proxima = auxiliar->proxima;
  }
  free(auxiliar);
}
void RemoveListaDeContribuicoes(ListaDeContribuicoes *lista)
{
  CelulaDeContribuicao *t;
  CelulaDeContribuicao *p = lista->primeira;
  while (p != NULL)
  {
    t = p->proxima;
    if (t)
    {
      free(p);
    }
    p = t;
  }
  free(lista);
}