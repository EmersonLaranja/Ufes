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

TipoListaHet *cria_ret(float b, float h) {}
TipoListaHet *cria_tri(float b, float h) {}
TipoListaHet *cria_cir(float r) {}