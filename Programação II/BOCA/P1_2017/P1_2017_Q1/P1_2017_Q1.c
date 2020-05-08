#include <stdio.h>
int main(){
int n1=0,n2=0,resp=0;
char operacao;
scanf("%d %d %c",&n1,&n2,&operacao);

switch (operacao){
case '+':
resp=n1+n2;
printf("RESP:%d",resp);
break;

case '-':
resp=n1-n2;
printf("RESP:%d",resp);
break;

case '*':
resp=n1*n2;
printf("RESP:%d",resp);
break;

case '/':
resp=n1/n2;
printf("RESP:%d",resp);
break;

default:
printf("Invalido");}

return 0;}
