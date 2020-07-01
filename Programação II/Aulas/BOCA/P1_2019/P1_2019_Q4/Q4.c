#include <stdio.h>
#include <stdlib.h>
int main(){
    int soma=0,verificacaoDig10=0,verificacaoDig11=0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,bloco1,bloco2,bloco3,bloco4,aux1,aux2,aux3;
    scanf("%d.%d.%d-%d",&bloco1,&bloco2,&bloco3,&bloco4);
    d1=bloco1/100;
    aux1=bloco1%100;
    d2=aux1/10;
    d3=aux1%10;
    
    d4=bloco2/100;
    aux2=bloco2%100;
    d5=aux2/10;
    d6=aux2%10;
    
    d7=bloco3/100;
    aux3=bloco3%100;
    d8=aux3/10;
    d9=aux3%10;
    
    d10=bloco4/10;
    d11=bloco4%10;
    
    
    if(d1==d2 && d2==d3 && d3==d4 && d4==d5 && d5==d6 && d6==d7 && d7==d8 && d8==d9 && d9==d10 && d10==d11){
        printf("CPF invalido: digitos iguais!");
        return 0;
    }
    
    soma=(d1*10)+(d2*9)+(d3*8)+(d4*7)+(d5*6)+(d6*5)+(d7*4)+(d8*3)+(d9*2);
    if(soma%11<2){
        verificacaoDig10=0;
    }else if(soma%11>=2){
        verificacaoDig10=11-(soma%11);
    }
    
    soma=(d1*11)+(d2*10)+(d3*9)+(d4*8)+(d5*7)+(d6*6)+(d7*5)+(d8*4)+(d9*3)+(verificacaoDig10*2);
    if(soma%11<2){
        verificacaoDig11=0;
    }else if(soma%11>=2){
        verificacaoDig11=11-(soma%11);
    }
    
    
    
    if(verificacaoDig10!=d10 && verificacaoDig11!=d11){
        printf("CPF invalido: dois digitos!");
    }
    if(verificacaoDig10!=d10 && verificacaoDig11==d11){
        printf("CPF invalido: primeiro digito!");
    }
    if(verificacaoDig10==d10 && verificacaoDig11!=d11){
        printf("CPF invalido: segundo digito!");
    }
    
    else if (verificacaoDig10==d10 && verificacaoDig11==d11){
        printf("CPF valido!");
    }
    
    
    
    return 0;
}