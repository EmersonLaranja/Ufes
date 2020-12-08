// /*
//  * File:   Pilha.h
//  * Author: Emerson
//  *
//  * Created on 22 de Junho de 2020, 11:30
//  */

// #include <stdlib.h>
// #include <stdio.h>
// #include "pilha.h"
// #define TAM 10

// struct pilha
// {
//   // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
//   int topo; //vai começar com 0 (na minha implementação)
//   Arv *arv[TAM];
// };

// //inicializa a estrutura da pilha
// Pilha *InicializaPilha(void)
// {
//   Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
//   pilha->topo = 0;
//   return pilha;
// }

// void Push(Pilha *pilha, Arv *arv)
// {
//   if (!pilha || pilha->topo >= TAM || !arv)
//   {
//     printf("Pilha cheia ou Arv invalido!!\n");
//     return;
//   }

//   pilha->arv[pilha->topo] = arv;
//   pilha->topo++;
// }

// Arv *Pop(Pilha *pilha)
// {
//   if (!pilha || pilha->topo == 0)
//   {
//     printf("Pilha vazia!\n");
//     return NULL; //retorna deve ser conhecido do cliente, para fazer os tratamentos
//   }
//   Arv *arv = pilha->arv[pilha->topo - 1];
//   pilha->topo--;
//   return arv;

//   // LEMBRANDO QUE TOPO ARMAZENA A PRIMEIRA POSIÇÃO VAZIA DO VETOR
// }

// void ImprimePilha(Pilha *pilha)
// {
//   if (!pilha)
//     return;

//   for (int i = (pilha->topo - 1); i >= 0; i--)
//     ImprimeArv(pilha->arv[i]);
// }

// void DestroiPilha(Pilha *pilha)
// {
//   if (!pilha)
//     return;

//   free(pilha);
// }
