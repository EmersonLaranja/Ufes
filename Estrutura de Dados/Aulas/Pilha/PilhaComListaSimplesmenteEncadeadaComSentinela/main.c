/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:27
 */

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "pilha.h"

/*
 * 
 */
int main(int argc, char **argv)
{
    Aluno *patricia = InicializaAluno(123, "Patricia", 10);
    Aluno *emerson = InicializaAluno(0, "Emerson", 11);
    Aluno *renato = InicializaAluno(4, "Renato", 6.57);
    Aluno *brenda = InicializaAluno(2, "Brenda", 2);

    Pilha *pilha1 = InicializaPilha();
    Pilha *pilha2 = InicializaPilha();

    Push(pilha1, patricia);
    Push(pilha1, emerson);
    Push(pilha1, renato);
    Push(pilha1, brenda);

    printf("Imprimindo a Pilha P1:\n");
    ImprimePilha(pilha1);

    Push(pilha2, Pop(pilha1));
    Push(pilha2, Pop(pilha1));
    Push(pilha2, Pop(pilha1));

    printf("Imprimindo a Pilha P2:\n");
    ImprimePilha(pilha2);

    DestroiPilha(pilha1);
    DestroiPilha(pilha2);

    DestroiAluno(patricia);
    DestroiAluno(emerson);
    DestroiAluno(renato);
    DestroiAluno(brenda);

    return (EXIT_SUCCESS);
}
