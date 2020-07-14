//
//  progpedidos4.c
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//
/*----------------------------------------------------------------------
 *  Primeira Prova Parcial de ED 1 - 07/10/2019
 *
 *  Sistema Gerenciador de Pedidos do MC'DONALDS!!!!
 *
 *  Testador 4: valendo 10 pontos!!!! Veja que o programa precisa rodar com todos os testadores anteriores!!!!
 *----------------------------------------------------------------------*/

#include <stdio.h>
#include "pedido.h"


int main() {
    
    //Cadastrando produtos, seus ingredientes e o numero de calorias
    TProduto* BigMac = InicProd("BigMac", 502);
    InsereIngrediente(BigMac, "hamburguer");
    InsereIngrediente(BigMac, "pao");
    InsereIngrediente(BigMac, "alface");
    InsereIngrediente(BigMac, "molho especial");
    InsereIngrediente(BigMac, "picles");
    InsereIngrediente(BigMac, "cebola");
    
    TProduto* McFlurry = InicProd("McFlurry", 465);
    InsereIngrediente(McFlurry, "chocolate");
    InsereIngrediente(McFlurry, "coco");
    InsereIngrediente(McFlurry, "sorvete baunilha");
    
    TProduto* GigaTasty = InicProd("GigaTasty", 1350);
    InsereIngrediente(GigaTasty, "hamburguer");
    InsereIngrediente(GigaTasty, "pao");
    InsereIngrediente(GigaTasty, "quejo");
    InsereIngrediente(GigaTasty, "alface");
    InsereIngrediente(GigaTasty, "molho tasty");
    InsereIngrediente(GigaTasty, "cebola crispy");
    
    //Iniciando o pedido de Patricia
    TPedido* patricia = InicPedido("Patricia");
    
    //Obvio que Patricia vai pedir tudo que tem no cardapio :)
    IncluiProdutoPedido(patricia, BigMac);
    IncluiProdutoPedido(patricia, McFlurry);
    IncluiProdutoPedido(patricia, GigaTasty);
    
    // Imprimindo o pedido de Patricia para verificar se esta tudo OK
    printf ("==============================");
    ImprimePedido(patricia);
    
    //-----------------------------------------------------
    // Iniciando o pedido de John
    TPedido* john = InicPedido("John");
    
    IncluiProdutoPedido(john, BigMac);
    IncluiProdutoPedido(john, McFlurry);
   
    // Imprimindo o pedido de John para verificar se esta tudo OK
    printf ("==============================");
    ImprimePedido(john);
    
    //--------------------------------------------------------------
    //Tenta enviar o pedido de Patricia, porem, ela esta de  dieta e tem a restricao calorica de 600
    //Ou seja, o pedido nao pode ser enviado ate que tenha menos de 600 calorias (somando-se as calorias de todos os produtos de seu pedido)
    //Patricia nao tem restricao alimentar
    int i = EnviaPedido(patricia, 600, "");
    
    //testando se o pedido de Patricia foi enviado. Caso nao tenha sido, imprime o pedido novamente.
    if (i==1) printf ("Pedido de Patricia enviado!\n");
    else {
        printf ("==============================");
        ImprimePedido(patricia);
    }
    //-----------------------------------------------------
    //Agora, Patricia (muito triste) vai tentar tirar os produtos do seu pedido para que este seja enviado
    
    //Retira o McFlurry (que triste...)
    RetiraProdutoPedido(patricia, "McFlurry");
    printf ("==============================");
    ImprimePedido(patricia);
    
    //Tenta enviar novamente!
    i = EnviaPedido(patricia, 600,"");
    
    //testando pela segunda vez se o pedido de Patricia foi enviado. Caso nao tenha sido, imprime o pedido novamente.
    if (i==1) printf ("Pedido de Patricia enviado!\n");
    else {
        printf ("==============================");
        ImprimePedido(patricia);
    }
    
    //retira agora o GigaTasty
    RetiraProdutoPedido(patricia, "GigaTasty");
    printf ("==============================");
    ImprimePedido(patricia);
    
    // tenta novamente enviar. agora tem que dar certo!
    i = EnviaPedido(patricia, 600,"");
    
    if (i==1) printf ("Pedido de patricia enviado!\n");
    else {
        printf ("==============================");
        ImprimePedido(patricia);
    }
    
    //--------------------------------------------------------------
    // Envia o pedido de John. Ele nao tem restricao calorica (por isso o valor alto de calorias). No entanto, ele nao pode comer pao.
    i = EnviaPedido(john, 10000, "pao");
    
    if (i==1) printf ("Pedido de John enviado!\n");
    else {
        printf ("==============================");
        ImprimePedido(john);
    }

    //Retira o BigMac (contem pao)
    RetiraProdutoPedido(john, "BigMac");
    
    // Tenta novamente enviar o pedido de John.
    i = EnviaPedido(john, 10000,"pao");
    
    if (i==1) printf ("Pedido de John enviado!\n");
    else {
        printf ("==============================");
        ImprimePedido(john);
    }

    // Destroi os produtos alocados!
    DestroiProd(BigMac);
    DestroiProd(McFlurry);
    DestroiProd(GigaTasty);
    
    return 0;
}
