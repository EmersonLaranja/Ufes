#include <stdio.h>
int main (){
int hora1,minuto1,segundo1,hora2,minuto2,segundo2,soma,aux;
scanf("%d%d%d%d%d%d",&hora1,&minuto1,&segundo1,&hora2,&minuto2,&segundo2);

if (hora1>hora2){
soma=hora1+minuto1+segundo1;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}

else if (hora1<hora2){
soma=hora2+minuto2+segundo2;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}



if (hora1==hora2 && hora1+minuto1>hora2+minuto2){
soma=hora1+minuto1+segundo1;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}

else if (hora1==hora2 && hora1+minuto1<hora2+minuto2){
soma=hora2+minuto2+segundo2;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}



if ((hora1==hora2) && (minuto1==minuto2) && (hora1+minuto1+segundo1>hora2+minuto2+segundo2)){
soma=hora1+minuto1+segundo1;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}

else if ((hora1==hora2) && (minuto1==minuto2) && (hora1+minuto1+segundo1<hora2+minuto2+segundo2)){
soma=hora2+minuto2+segundo2;
aux=soma/10;
soma=aux;
aux=(soma/10)*10;
soma=soma-aux;
printf("RESP:%d",soma);}

if ((hora1==hora2) && (minuto1==minuto2) && (segundo1==segundo2)){
printf("IGUAIS");}

return 0;}


