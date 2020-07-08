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
#include "listaSemSentinela.h"

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

    listaDeAlunos = InsereLista(listaDeAlunos, patricia);
    listaDeAlunos = InsereLista(listaDeAlunos, renato);
    listaDeAlunos = InsereLista(listaDeAlunos, emerson);
    listaDeAlunos = InsereLista(listaDeAlunos, brenda);

    printf("Imprimindo a lista de Alunos:\n");
    ImprimeLista(listaDeAlunos);

    listaDeAlunos = RetiraLista(listaDeAlunos, "Renato");
    printf("Imprimindo a lista de Alunos:\n");
    ImprimeLista(listaDeAlunos);

    //para não termos vazamento de memória:
    DestroiLista(listaDeAlunos);
    DestroiAluno(patricia);
    DestroiAluno(brenda);
    DestroiAluno(renato);
    DestroiAluno(emerson);

    return (EXIT_SUCCESS);
}
