//
//  produto.c
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

#include <stdio.h>
#include "produto.h"
#include <stdlib.h>
#include <string.h>

#define MAXTAM 20

struct produto {
    char* nome;
    int calorias;
    int topo;
    char* ingredientes[MAXTAM];
};

TProduto* InicProd (char* nome, int calorias){
    TProduto* prod = (TProduto*) malloc (sizeof (TProduto));
    prod->calorias = calorias;
    prod->nome = strdup (nome);
    prod->topo = 0;
    return prod;
}

void InsereIngrediente (TProduto* prod, char* ingrediente){
    if (prod->topo == MAXTAM)
        return;
    prod->ingredientes[prod->topo] = strdup (ingrediente);
    prod->topo++;
    
}

void ImprimeIngredientes (TProduto* prod){
    int i;
    printf("\nProduto: %s \nIngredientes: ", prod->nome);
    for (i=0; i<prod->topo; i++){
        if (i == (prod->topo -1))
           printf("%s\n", prod->ingredientes[i]);
        else
            printf("%s,", prod->ingredientes[i]);
    }
    printf("\n");
}

TProduto* DestroiProd(TProduto* prod){
    int i;

    for (i=0; i<prod->topo; i++){
        free(prod->ingredientes[i]);
    }
    free (prod->nome);
    free (prod);
    return NULL;
}

//verifica se tem o ingrediente
int VerificaIngrediente (TProduto* prod, char* ingrediente){
    int i;
    
    for (i=0; i<prod->topo; i++){
        if (strcmp (prod->ingredientes[i], ingrediente) == 0)
            return 1;
    }
    return 0;
}

int Calorias (TProduto* prod){
    return prod->calorias;
}

char* RetornaNome (TProduto* prod){
    return prod->nome;
}
