/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: laranja
 *
 * Created on 4 de Maio de 2019, 09:26
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char l = '\0';
    while (l != 'a') {
        printf("Digite uma letra!");
        scanf("%c", &l);
        scanf("%*[^\n]");
        scanf("%*c");
    }
    printf("Finalmente voce digitou a!");

    return 0;
}

