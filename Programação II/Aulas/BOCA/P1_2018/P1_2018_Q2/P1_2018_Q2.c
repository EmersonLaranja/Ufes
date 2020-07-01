#include <stdio.h>
int main(){
int nota5=0,nota1=0,aux1=0,troco1=0,troco2=0,aux2=0;
scanf("%d%d",&troco1,&troco2);

nota5=troco1/5;
troco1=troco1%5;
nota1=troco1;
aux1=nota5+nota1;

nota5=troco2/5;
troco2=troco2%5;
nota1=troco2;
aux2=nota5+nota1;


if (aux1>aux2){printf("QTD troco 1 eh maior!");}

else {
if (aux1<aux2){printf("QTD troco 2 eh maior!");}
else {printf("Iguais!");}
}

return 0;}
