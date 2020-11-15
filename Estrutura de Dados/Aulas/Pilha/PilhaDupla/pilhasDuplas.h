#ifndef _PILHASDUPLAS_H
#define _PILHASDUPLAS_H

typedef struct pilhaDupla PilhaDupla;

PilhaDupla *InicializaPilha(void);

void ImprimePilha(PilhaDupla *pilha);

void PushPrimeiraPilha(PilhaDupla *pilha, int numero);

void PushSegundaPilha(PilhaDupla *pilha, int numero);

int PopPrimeiraPilha(PilhaDupla *pilha);

int PopSegundaPilha(PilhaDupla *pilha);

void DestroiPilhas(PilhaDupla *pilha);

#endif //_PILHASDUPLAS_H
