/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "listaSemSentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    Aluno *aluno;
    Lista *proxima;
};

Lista *IniciaLista(void)
{
    return NULL;
}

void ImprimeLista(Lista *lista)
{
    Lista *auxiliar;

    for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proxima)
    {
        ImprimeAluno(auxiliar->aluno);
    }
}

//inserindo elementos no inicio
Lista *InsereLista(Lista *lista, Aluno *aluno)
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->aluno = aluno;
    nova->proxima = lista;
    return nova;
}

Lista *RetiraLista(Lista *lista, char *chave)
{
    Lista *listaAuxiliar = lista;
    Aluno *alunoAuxiliar;
    Lista *anterior = NULL;

    //faz a busca
    while (listaAuxiliar != NULL && strcmp(RetornaNome(listaAuxiliar->aluno), chave))
    {
        anterior = listaAuxiliar;
        listaAuxiliar = listaAuxiliar->proxima;
    }

    //lista vazia ou não encontrou o aluno
    if (listaAuxiliar == NULL)
        return NULL;

    //se for a primeira celula
    if (anterior == NULL)
    {
        lista = lista->proxima;
    }
    //caso comum
    else
    {
        anterior->proxima = listaAuxiliar->proxima;
    }

    free(listaAuxiliar);

    return lista;
}

void DestroiLista(Lista *lista)
{
    Lista *p = lista;
    Lista *t = NULL;

    while (p != NULL)
    {
        t = p->proxima;
        DestroiAluno(p->aluno);
        free(p);
        p = t;
    }
}