#include <stdio.h>
#include <stdlib.h>

float FazOperacao(float num1, float num2, char op){
    float resultadoDaOperacao=0;
    if(op=='+'){
        resultadoDaOperacao=num1+num2;
        return resultadoDaOperacao;
    }
    if(op=='-'){
        resultadoDaOperacao=num1-num2;
        return resultadoDaOperacao;
    }
    if(op=='*'){
        resultadoDaOperacao=num1*num2;
        return resultadoDaOperacao;
    }
    if(op=='/'){
        resultadoDaOperacao=num1/num2;
        return resultadoDaOperacao;
    }
}
float ResolveExpressao(float num1,float num2, char op){
    int i=0;
    float resultado=0;
    if(i==0){
        resultado=FazOperacao(num1,num2,op);
        num1=resultado;
        i++;
    }
   while( scanf("%f %c",&num2,&op)==2){
       resultado=FazOperacao(num1,num2,op);
       num1=resultado;
   }
    return resultado;
}

int main() {
    char texto='\0',op='\0';
    float xananan=0,maior=0,num1=0,num2=0,resolveOperacaoInicial=0;
    while(texto!='.'){
        scanf("%c",&texto);
        if(texto=='('){
            scanf("%f %f %c",&num1,&num2,&op);
            resolveOperacaoInicial=ResolveExpressao(num1,num2,op);
            if(xananan=0){
                maior=resolveOperacaoInicial;
            }
            if(resolveOperacaoInicial>maior){
                maior=resolveOperacaoInicial;
            }
            printf("%.2f",resolveOperacaoInicial);
            continue;
        }
        if(texto==')'){
            continue;
        }else{
            printf("%c",texto);
        }
    }
    printf("MAIOR:%.2f",maior);
    
    return 0;
}

