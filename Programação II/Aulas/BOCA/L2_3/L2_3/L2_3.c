#include <stdio.h>
#include <stdlib.h>
int main() {
    float media=0,soma=0;
    int qnt=0,i=0,numero=0,maior=0,menor=0,contpar=0,contimpar=0;
    printf("Forneca um numero indicando a quantidade: ");
    scanf("%d",&qnt);
    i=0;
    maior=numero;
    menor=numero;
    soma=0;
        while(i<qnt){
        printf("Forneca um numero em questao: ");
        scanf("%d",&numero);
      
          if(i==0){
            menor=numero;
        }
        if(numero>maior){
            maior=numero;            
        }
        if(numero<menor){
            menor=numero;
        }
        if (numero%2==0){
            contpar++;
        } if (numero%2!=0){
            contimpar++;
        }
        soma=soma+numero;
        i++;
         
    }
    media=soma/qnt;
    printf("%d %d %d %d %.6f",maior,menor,contpar,contimpar,media);

    return 0;
}

