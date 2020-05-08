#include <stdio.h>
int main(){
    int num1,num2,operacao,resto;
    char sinal;
    scanf("%d %c %d",&num1,&sinal,&num2);
    switch(sinal){
        case '+':
        operacao=num1+num2;
        printf("SOMA:%d",operacao);
        break;

        case '-':
        operacao=num1-num2;
        printf("SUB:%d",operacao);
        break;

        case '*':
        operacao=num1*num2;
        printf("MULT:%d",operacao);
        break;

        case '/':
        operacao=num1/num2;
        resto=num1%num2;
        if (resto!=0){
            printf("DIV:%d, RESTO:%d",operacao,resto);
            break;
        }else if(resto==0){
            printf("DIV:%d",operacao);
            break;
        }
        

    }return 0;
}