#include <stdio.h>
int main(){
int hora,minuto,incremento,somaDosMinutos,dia;
scanf("%d:%d%d",&hora,&minuto,&incremento);

somaDosMinutos=minuto+incremento;
hora=hora+(somaDosMinutos/60);
minuto=(somaDosMinutos%60);
dia=hora/24;
hora=hora%24;

if (dia==1){printf("(%d dia)",dia);}
if (dia>1){printf("(%d dias)",dia);}

if (hora==1){printf("(%d hora)",hora);}
if (hora>1){printf("(%d horas)",hora);}

if (minuto==1){printf("(%d minuto)",minuto);}
if (minuto>1){printf("(%d minutos)",minuto);}

return 0;}
