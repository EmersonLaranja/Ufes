#include <stdio.h>
int main(){
float tempIni=0,aux1=0,aux2=0;
char unidadeIni;
scanf("%f %c",&tempIni,&unidadeIni);
if (unidadeIni == 'f' || unidadeIni == 'F'){
aux1 = (tempIni-32)/(1.8);
printf("%.2f(C)",aux1);}
else {if (unidadeIni == 'c' || unidadeIni == 'C');
aux2=(tempIni*(1.8))+32;
printf("%.2f(F)",aux2);} 
return 0;
}

