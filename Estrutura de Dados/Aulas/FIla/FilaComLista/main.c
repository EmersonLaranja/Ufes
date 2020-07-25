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
#include "fila.h"

/*
 * 
 */
int main(int argc, char **argv)
{
    Aluno *patricia = InicializaAluno(123, "Patricia", 10);
    Aluno *emerson = InicializaAluno(0, "Emerson", 11);
    Aluno *renato = InicializaAluno(4, "Renato", 6.57);
    Aluno *brenda = InicializaAluno(2, "Brenda", 2);

    Fila *fila1 = InicializaFila();
    Fila *fila2 = InicializaFila();

    InsereFila(fila1, patricia);
    InsereFila(fila1, emerson);
    InsereFila(fila1, renato);
    InsereFila(fila1, brenda);

    printf("\nImprimindo a fila1 de Alunos:\n");
    ImprimeFila(fila1);

    InsereFila(fila2, RetiraFila(fila1));

    printf("\nImprimindo a fila1 de Alunos:\n");
    ImprimeFila(fila1);

    printf("\nImprimindo a fila2 de Alunos:\n");
    ImprimeFila(fila2);

    InsereFila(fila2, RetiraFila(fila1));

    printf("\nImprimindo a fila1 de Alunos:\n");
    ImprimeFila(fila1);

    printf("\nImprimindo a fila2 de Alunos:\n");
    ImprimeFila(fila2);

    DestroiAluno(patricia);
    DestroiAluno(emerson);
    DestroiAluno(renato);
    DestroiAluno(brenda);

    DestroiFila(fila1);
    DestroiFila(fila2);

    return (EXIT_SUCCESS);
}
