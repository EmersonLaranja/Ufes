#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    long int numero=0,numerador=0,denominador=0;
    double soma=0,operacao=0;
    scanf("%d",&numero);
    if(numero==1){
        numerador=1;
        denominador=1;
        soma=0;
        while (denominador>=1 && denominador<=50){
            operacao=(float)numerador/denominador;
            soma=soma+operacao;
            numerador=numerador+2;
            denominador++;
        }printf("%.6f",soma);
    }
    if (numero==2){
        numerador=2;
        denominador=50;
        soma=0;
        while(denominador<=50 && denominador>=1){
            operacao=(float)numerador/denominador;
            soma=soma+operacao;
            numerador=numerador*2;
            denominador--;
        }printf("%.6f",soma);
            
        
        
    }

    return (EXIT_SUCCESS);
}

