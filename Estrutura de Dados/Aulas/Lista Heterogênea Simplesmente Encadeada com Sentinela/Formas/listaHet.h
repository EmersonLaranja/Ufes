
#ifndef LISTAHET_H
#define LISTAHET_H

/* Definição dos tipos de objetos */
#define RET 0
#define TRI 1
#define CIR 2

typedef struct retangulo Retangulo;
typedef struct triangulo Triangulo;
typedef struct circulo Circulo;
typedef struct celula_str TipoListaHet;

TipoListaHet *cria_ret(float b, float h);
TipoListaHet *cria_tri(float b, float h);
TipoListaHet *cria_cir(float r);

#endif