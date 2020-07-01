#include <stdio.h>
#include <stdlib.h>

int main() {
    int contaMenor=0,menor=0,primeiraVez=0,quantidadeDeNumerosDaLista=0,i=0,numero=0,proximoNumero=0;
    scanf("%d",&quantidadeDeNumerosDaLista);
    if(quantidadeDeNumerosDaLista==0){
        return 0;
    }
    while(i<=quantidadeDeNumerosDaLista){
        if(primeiraVez==0){
            scanf("%d",&numero);
            i++;
            primeiraVez++;
            menor=numero;
            contaMenor++;
        }
        scanf("%d",&proximoNumero);
        i++;
        if(proximoNumero==0){
            continue;
        }
        if(proximoNumero<menor){
            menor=proximoNumero;
            contaMenor++;
        }else{
            
        }
    }
    printf("POS:%d",contaMenor);
    return 0;
}

