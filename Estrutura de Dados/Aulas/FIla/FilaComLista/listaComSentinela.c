/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "listaComSentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula
{
    Aluno *aluno;
    Celula *proxima;
};

struct lista
{
    Celula *primeira;
    Celula *ultima;
};

Lista *IniciaLista(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->primeira = NULL;
    lista->ultima = NULL;

    return lista;
}

void ImprimeLista(Lista *lista)
{
    Celula *auxiliar;
    if (lista == NULL)
    {
        printf("Lista vazia");
        exit(1);
    }
    for (auxiliar = lista->primeira; auxiliar != NULL; auxiliar = auxiliar->proxima)
    {
        ImprimeAluno(auxiliar->aluno);
    }
}

//inserindo elementos no inicio
void InsereLista(Lista *lista, Aluno *aluno)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->aluno = aluno;
    nova->proxima = lista->primeira;
    lista->primeira = nova;

    if (lista->ultima == NULL)
        lista->ultima = nova;
}
void InsereListaFim(Lista *lista, Aluno *aluno)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->aluno = aluno;
    nova->proxima = NULL;

    if (lista->primeira == NULL)
    {
        lista->primeira = lista->ultima = nova;
        return;
    }
    lista->ultima->proxima = nova;
    lista->ultima = nova;
}

Aluno *RetiraLista(Lista *lista, char *chave)
{
    Celula *celulaAuxiliar = lista->primeira;
    Aluno *alunoAuxiliar;
    Celula *anterior = NULL;

    //faz a busca
    while (celulaAuxiliar != NULL && strcmp(RetornaNome(celulaAuxiliar->aluno), chave))
    {
        anterior = celulaAuxiliar;
        celulaAuxiliar = celulaAuxiliar->proxima;
    }

    //lista vazia ou não encontrou o aluno
    if (celulaAuxiliar == NULL)
        return NULL;

    //atribui o aluno de retorno
    alunoAuxiliar = celulaAuxiliar->aluno;

    //se for uma unica celula
    if (lista->primeira == celulaAuxiliar && lista->ultima == celulaAuxiliar)
    { //lista vazia
        lista->primeira =
            lista->ultima =
                NULL;
    }
    else if (lista->primeira == celulaAuxiliar)
    {
        lista->primeira = celulaAuxiliar->proxima; //se for o primeiro
    }
    else if (lista->ultima == celulaAuxiliar)
    { //se for o ultimo
        lista->ultima = anterior;
        lista->ultima->proxima = NULL; //poderia ser anterior->proxima=NULL
    }

    else
    { //caso comum, retirar elementos que não são os extremos
        anterior->proxima = celulaAuxiliar->proxima;
    }

    free(celulaAuxiliar);

    return alunoAuxiliar;
}

Aluno *RetiraPosicao(Lista *lista, int posicao)
{
    Celula *celulaAuxiliar = lista->primeira;
    Aluno *alunoAuxiliar;
    Celula *anterior = NULL;
    int i = 0;

    //faz a busca
    while (i < posicao && celulaAuxiliar != NULL)
    {
        anterior = celulaAuxiliar;
        i++;
        celulaAuxiliar = celulaAuxiliar->proxima;
    }

    //lista vazia ou não encontrou o aluno
    if (celulaAuxiliar == NULL)
        return NULL;

    //atribui o aluno de retorno
    alunoAuxiliar = celulaAuxiliar->aluno;

    //se for uma unica celula
    if (lista->primeira == celulaAuxiliar && lista->ultima == celulaAuxiliar)
    { //lista vazia
        lista->primeira =
            lista->ultima =
                NULL;
    }
    else if (lista->primeira == celulaAuxiliar)
    {
        lista->primeira = celulaAuxiliar->proxima; //se for o primeiro
    }
    else if (lista->ultima == celulaAuxiliar)
    { //se for o ultimo
        lista->ultima = anterior;
        lista->ultima->proxima = NULL; //poderia ser anterior->proxima=NULL
    }

    else
    { //caso comum, retirar elementos que não são os extremos
        anterior->proxima = celulaAuxiliar->proxima;
    }

    free(celulaAuxiliar);

    return alunoAuxiliar;
}

void DestroiLista(Lista *lista)
{
    Celula *p = lista->primeira;
    Celula *t = NULL;

    while (p != NULL)
    {
        t = p->proxima;
        if (p->aluno != NULL)
        {
            // DestroiAluno(p->aluno);
            free(p);
        }
        p = t;
    }
    //liberando a sentinela
    free(lista);
}