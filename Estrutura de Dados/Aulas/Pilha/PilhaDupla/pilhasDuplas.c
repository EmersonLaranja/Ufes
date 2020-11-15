#include <stdio.h>
#include <stdlib.h>
#include "pilhasDuplas.h"
#define MaxTam 1000
typedef int TipoItem;

typedef struct
{
    int topo, base;
} IndicePilha;

struct pilhaDupla
{
    TipoItem item[MaxTam];
    IndicePilha pilha1, pilha2;
};

PilhaDupla *InicializaPilha(void)
{
    PilhaDupla *pilha = (PilhaDupla *)malloc(sizeof(PilhaDupla));

    pilha->pilha1.base = 0;
    pilha->pilha1.topo = -1; //para que de fato tenhamos o ultimo elemento no topo da pilha

    pilha->pilha2.base = MaxTam - 1;
    pilha->pilha2.topo = MaxTam;

    return pilha;
}

void ImprimePilha(PilhaDupla *pilha)
{
    int i;

    if (!pilha)
        return;

    printf("\nPilha 1:\n|");
    for (i = (pilha->pilha1.topo); i >= 0; i--)
    {
        printf("%d ", pilha->item[i]);
    }
    printf("|\n");

    printf("\nPilha 2:\n|");
    for (i = (pilha->pilha2.topo); i <= MaxTam - 1; i++)
    {
        printf("%d ", pilha->item[i]);
    }
    printf("|\n");
}

void PushPrimeiraPilha(PilhaDupla *pilha, int num)
{
    if (pilha->pilha1.topo == pilha->pilha2.topo - 1 || !pilha)
    {
        printf("Pilha cheia ou invalida!\n");
        return;
    }

    pilha->item[pilha->pilha1.topo + 1] = num;
    pilha->pilha1.topo++;
}

void PushSegundaPilha(PilhaDupla *pilha, int num)
{
    if (pilha->pilha1.topo == pilha->pilha2.topo - 1 || !pilha)
    {
        printf("Pilha cheia ou invalida!\n");
        return;
    }

    pilha->item[pilha->pilha2.topo - 1] = num;
    pilha->pilha2.topo--;
}

int PopPrimeiraPilha(PilhaDupla *pilha)
{
    if (!pilha || pilha->pilha1.topo == -1)
    {
        printf("Pilha vazia ou invalida!\n");
    }
    int i = pilha->item[pilha->pilha1.topo];
    pilha->pilha1.topo--;

    return i;
}

int PopSegundaPilha(PilhaDupla *pilha)
{
    if (!pilha || pilha->pilha2.topo == MaxTam)
    {
        printf("Pilha vazia ou invalida!\n");
    }
    int i = pilha->item[pilha->pilha2.topo];
    pilha->pilha2.topo++;

    return i;
}

void DestroiPilhas(PilhaDupla *pilha)
{
    if (!pilha)
        return;

    free(pilha);
}