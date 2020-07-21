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
  TipoListaHet *nova = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  nova->Item = ret;
  nova->Prox = NULL;
  nova->tipo = RET;
  return nova;
}
TipoListaHet *cria_tri(float b, float h)
{
  Triangulo *tri = (Triangulo *)malloc(sizeof(Triangulo));
  tri->b = b;
  tri->h = h;
  TipoListaHet *nova = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  nova->Item = tri;
  nova->Prox = NULL;
  nova->tipo = TRI;
  return nova;
}
TipoListaHet *cria_cir(float r)
{
  Circulo *cir = (Circulo *)malloc(sizeof(Circulo));

  cir->r = r;
  TipoListaHet *nova = (TipoListaHet *)malloc(sizeof(TipoListaHet));
  nova->Item = cir;
  nova->Prox = NULL;
  nova->tipo = CIR;
  return nova;
}

static float ret_area(Retangulo *r)
{
  return r->b * r->h;
}

static float tri_area(Triangulo *t)
{
  return (t->b * t->h) / 2;
}

static float cir_area(Circulo *c)
{
  return c->r * c->r;
}

static float area(TipoListaHet *p)
{
  float a;
  switch (p->tipo)
  {
  case RET:
    a = ret_area(p->Item);
    break;
  case TRI:
    a = tri_area(p->Item);
    break;
  case CIR:
    a = cir_area(p->Item);
    break;
  }
  return a;
}

float max_area(TipoListaHet *l)
{
  float amax = 0.0;
  TipoListaHet *p;
  for (p = l; p != NULL; p = p->Prox)
  {
    float a = area(p);
    if (a > amax)
      amax = a;
  }
  return amax;
}