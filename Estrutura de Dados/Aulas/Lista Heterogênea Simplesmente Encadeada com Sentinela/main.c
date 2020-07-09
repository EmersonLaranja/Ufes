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
#include "listaHet.h"

/*
 * 
 */
int main(int argc, char **argv)
{
    Aluno *patricia = InicializaAluno(123, "Patricia", 10);
    Aluno *emerson = InicializaAluno(0, "Emerson", 11);
    Aluno *renato = InicializaAluno(4, "Renato", 6.57);
    Aluno *brenda = InicializaAluno(2, "Brenda", 2);

    Professor *roberta = InicializaProfessor(3878734, "Roberta", 9435.00);
    Professor *flavio = InicializaProfessor(578475, "Flavio", 7432.00);

    ListaHet *listaChurras = IniciaLista();

    InsereAlunoLista(listaChurras, patricia);
    InsereProfessorLista(listaChurras, roberta);
    InsereAlunoLista(listaChurras, emerson);
    InsereAlunoLista(listaChurras, renato);
    InsereProfessorLista(listaChurras, flavio);
    InsereAlunoLista(listaChurras, brenda);

    printf("Imprimindo a lista de Alunos:\n");
    ImprimeLista(listaChurras);

    printf("VALOR: %.2f", ValorChurrasco(listaChurras));

    DestroiAluno(emerson);
    DestroiAluno(brenda);
    DestroiAluno(renato);
    DestroiAluno(patricia);

    DestroiProfessor(roberta);
    DestroiProfessor(flavio);

    return (EXIT_SUCCESS);
}
