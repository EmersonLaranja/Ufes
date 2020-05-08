#include <stdio.h>
#include <stdlib.h>
int main() {
    int primeiraLinha=0,segundaLinha=0,i=0,menorDaPrimeiraLinha=0,posicaoInicial=0,posicaoFinal=0,contInicial=0;
    char lixo;

    while (scanf("%d",&primeiraLinha)==1){  
        if (i==0){
            menorDaPrimeiraLinha=primeiraLinha;
            i++;
        }
        if (primeiraLinha<menorDaPrimeiraLinha){
            menorDaPrimeiraLinha=primeiraLinha;
        }        
    }
    scanf("%c",&lixo);
    scanf("%*[^\n]");
    scanf("%c");
    
    while (scanf("%d",&segundaLinha)==1){
        if(posicaoInicial==menorDaPrimeiraLinha){
            contInicial;            
        }else{
            contInicial++;
        }
        
    }
       
    printf("%d ",menorDaPrimeiraLinha);
    printf("%d ",posicaoInicial);
    printf("%d",posicaoFinal);


    
    
    
    
    
    
    
    
    
            
    return 0;
}

