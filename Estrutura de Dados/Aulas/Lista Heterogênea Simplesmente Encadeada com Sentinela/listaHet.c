/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "listaHet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROF 0
#define ALU 1

typedef struct celula Celula;
struct celula
{
    Celula *prox;
    void *item; //aqui há uma conversão de tipo implicita (downcasting) quando evocamos funções
    int tipo;
};

// sentinela
struct listahet
{
    Celula *inicio;
    Celula *fim;
};

ListaHet *IniciaLista(void)
{
    ListaHet *lista = (ListaHet *)malloc(sizeof(ListaHet));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void InsereAlunoLista(ListaHet *lista, Aluno *aluno)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->item = aluno;
    nova->tipo = ALU;
    nova->prox = lista->inicio;
    lista->inicio = nova;
    if (lista->fim == NULL)
        lista->fim = nova;
}

void InsereProfessorLista(ListaHet *lista, Professor *professor)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->item = professor;
    nova->tipo = PROF;
    nova->prox = lista->inicio;
    lista->inicio = nova;
    if (lista->fim == NULL)
        lista->fim = nova;
}

void ImprimeLista(ListaHet *lista)
{
    for (Celula *p = lista->inicio; p != NULL; p = p->prox)
    {
        if (p->tipo == ALU)
        {
            printf("Aluno: ");
            ImprimeAluno(p->item); //conversão implicita
            // ImprimeAluno((Aluno *)p->item); //conversão explicita
        }
        if (p->tipo == PROF)
        {
            printf("Professor: ");
            ImprimeProfessor(p->item);
        }
    }
}

/*
    Valor do churrasco! |Professor contribui com 2% do salário e Aluno contribui
    com taxa fixa de 30 reais
*/

float ValorChurrasco(ListaHet *lista)
{
    Celula *p = lista->inicio;
    float valor = 0.0;

    while (p != NULL)
    {
        if (p->tipo == ALU)
            valor = valor + 30.0;

        if (p->tipo == PROF)
            valor = valor + 0.02 * RetornaSalario(p->item);

        p = p->prox;
    }
    return valor;
}

void DestroiLista(ListaHet *lista)
{
    Celula *p = lista->inicio;
    Celula *t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
    free(lista);
}
