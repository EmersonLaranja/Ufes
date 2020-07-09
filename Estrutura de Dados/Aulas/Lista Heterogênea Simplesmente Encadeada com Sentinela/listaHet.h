/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaHet.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */

#ifndef LISTAHET_H
#define LISTAHET_H

#ifdef __cplusplus
extern "C"
{
#endif

// lista heterogenea
#include <stdio.h>
#include "aluno.h"
#include "professor.h"

    typedef struct listahet ListaHet;

    ListaHet *IniciaLista(void);
    void InsereAlunoLista(ListaHet *lista, Aluno *aluno);
    void InsereProfessorLista(ListaHet *lista, Professor *professor);
    void ImprimeLista(ListaHet *lista);
    float ValorChurrasco(ListaHet *lista);

    void DestroiLista(ListaHet *lista);

#ifdef __cplusplus
}
#endif

#endif /* LISTAHET_H */
