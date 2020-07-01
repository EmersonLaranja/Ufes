/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listaComSentinela.h
 * Author: Emerson
 *
 * Created on 22 de Junho de 2020, 11:30
 */
 
#ifndef LISTACOMSENTINELA_H
#define LISTACOMSENTINELA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "aluno.h"
   
    typedef struct lista Lista;
    
    Lista* IniciaLista();
    
    void InsereLista(Lista* lista, Aluno* aluno);
    void ImprimeLista(Lista* lista);
    Aluno* RetiraLista(Lista* lista, char* chave);
    void DestroiLista(Lista* lista);


#ifdef __cplusplus
}
#endif

#endif /* LISTACOMSENTINELA_H */

