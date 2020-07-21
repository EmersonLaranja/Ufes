#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaHet.h"

//🟧
struct retangulo
{
  float b;
  float h;
};

// 🔺
struct triangulo
{
  float b;
  float h;
};

// 🟠
struct circulo
{
  float r;
};

struct celula_str
{
  int tipo;
  void *Item;
  struct celula_str *Prox;
};

TipoListaHet *cria_ret(float b, float h)

{
  Retangulo *ret = (Retangulo *)malloc(sizeof(Retangulo));

  ret->b = b;
  ret->h = h;

  TipoListaHet *l = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  l->tipo = RET;
  l->Item = ret;
  l->Prox = NULL;
  return l;
}
TipoListaHet *cria_tri(float b, float h)
{
  Triangulo *tri = (Triangulo *)malloc(sizeof(Triangulo));

  tri->b = b;
  tri->h = h;

  TipoListaHet *l = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  l->tipo = TRI;
  l->Item = tri;
  l->Prox = NULL;
  return l;
}
TipoListaHet *cria_cir(float r)
{
  Circulo *cir = (Circulo *)malloc(sizeof(Circulo));

  cir->r = r;

  TipoListaHet *l = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  l->tipo = CIR;
  l->Item = cir;
  l->Prox = NULL;
  return l;
}