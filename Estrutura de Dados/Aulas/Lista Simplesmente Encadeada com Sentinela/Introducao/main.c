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
#include "listaComSentinela.h"

/*
 * 
 */
int main(int argc, char **argv)
{
    Aluno *patricia = InicializaAluno(123, "Patricia", 10);
    Aluno *emerson = InicializaAluno(0, "Emerson", 11);
    Aluno *renato = InicializaAluno(4, "Renato", 6.57);
    Aluno *brenda = InicializaAluno(2, "Brenda", 2);

    Lista *listaDeAlunos = IniciaLista();

    InsereLista(listaDeAlunos, patricia);
    InsereLista(listaDeAlunos, emerson);
    InsereLista(listaDeAlunos, renato);
    InsereLista(listaDeAlunos, brenda);

    printf("Imprimindo a lista de Alunos:\n");
    // ImprimeLista(listaDeAlunos);
    DestroiLista(listaDeAlunos);

    return (EXIT_SUCCESS);
}
