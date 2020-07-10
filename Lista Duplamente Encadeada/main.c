// /*
//  * To change this license header, choose License Headers in Project Properties.
//  * To change this template file, choose Tools | Templates
//  * and open the template in the editor.
//  */

// /*
//  * File:   main.c
//  * Author: Emerson
//  *
//  * Created on 22 de Junho de 2020, 11:27
//  */

#include <stdio.h>
#include <stdlib.h>
#include "listadpl.h"

/*
 *
 */
int main(int argc, char **argv)
{
  TipoItem *patricia = InicializaTipoItem("Patricia", 10, "aqui");
  TipoItem *emerson = InicializaTipoItem("Emerson", 11, "ali");
  TipoItem *renato = InicializaTipoItem("Renato", 67, "la");
  TipoItem *brenda = InicializaTipoItem("Brenda", 2, "ca");

  TipoListaDpl *lista;

  lista = Insere(patricia, lista);
  lista = Insere(renato, lista);
  lista = Insere(emerson, lista);
  lista = Insere(brenda, lista);

  printf("Imprimindo a lista :\n");
  Imprime(lista);

  lista = Retira(lista, "Renato");
  printf("Imprimindo a lista :\n");
  Imprime(lista);

  //para não termos vazamento de memória:
  libera(lista);

  return (EXIT_SUCCESS);
}
