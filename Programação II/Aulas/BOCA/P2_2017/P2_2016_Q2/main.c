#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num){
    int cont=0,i=1;
    while(i<=num){
        if(num%i==0){
            cont++;
            i++;
        }else{
            i++;
        }
    }
    if(cont==2){
        return 1;
    }
    if(cont!=2){
        return 0;
    }
}

int MaiorDigitoPrimo(int num){
    int resto,n=num,resultado,maior;
    maior=0;
    while(n!=0){
        resto=n%10;
        n=n/10;
        resultado=EhPrimo(resto);
        if(resultado==1){
            if(resto>maior){
                maior=resto;
            }
        }
    }
    return maior;
}




int main() {
    int entrada=0,soma=0,resultado=0;
    while(scanf("%d",&entrada)==1){
        resultado=MaiorDigitoPrimo(entrada);
        soma=soma+resultado;
    }
    printf("SOMA:%d",soma);
    
    return 0;
}

