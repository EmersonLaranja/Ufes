#include <stdio.h>
int main(){
int idP1,idP2,valido=1;
scanf("%i%i",&idP1,&idP2);
if ((idP1==idP2) && (idP1>=1 && idP1<=5) && (idP2>=1 && idP2<=5)) {;printf("Um homem");}

if ((idP1!=idP2) && (idP1>=1 && idP1<=5) && (idP2>=1 && idP2<=5)) {printf("Par de homens");}

if ((idP1==idP2) && (idP1>=6 && idP1<=10) && (idP2>=6 && idP2<=10)) {printf("Uma mulher");}

if ((idP1!=idP2) && (idP1>=6 && idP1<=10) && (idP2>=6 && idP2<=10)) {printf("Par de mulheres");}

if ((idP1!=idP2) &&  ((idP1>=1 && idP1<=5) && (idP2>=6 && idP2<=10)) || ((idP1>=6 && idP1<=10) && (idP2>=1 && idP2<=5))){printf("Um casal");}

if (idP1>10 || idP1<1 || idP2>10 || idP2<1){printf("Invalido");}

return 0;}






