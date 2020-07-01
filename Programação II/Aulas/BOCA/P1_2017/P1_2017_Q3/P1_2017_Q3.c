#include <stdio.h>
int main(){
int valido=1;
char c1x,c2x,c1y,c2y; //Caracter 1 do código x e assim por diante
scanf("%c%c %c%c",&c1x,&c2x,&c1y,&c2y);

if (!(((c1x>='A' && c1x<='Z') || (c1x>='a' && c1x<='z')) || (c1x>='0' && c1x<='9'))){valido =0;} 

if (!(((c2x>='A' && c2x<='Z') || (c2x>='a' && c2x<='z')) || (c2x>='0' && c2x<='9'))){valido =0;} 

if (!(((c1y>='A' && c1y<='Z') || (c1y>='a' && c1y<='z')) || (c1y>='0' && c1y<='9'))){valido =0;} 

if (!(((c2y>='A' && c2y<='Z') || (c2y>='a' && c2y<='z')) || (c2y>='0' && c2y<='9'))){valido =0;}
 

if (!valido) {printf("Invalido"); return 0;}

if ((c1x-'a'==c1y-'a') || (c1x-'A'==c1y-'A') || (c1x-'A'==c1y-'a') || (c1x-'a'==c1y-'A')||((c1x>='0' && c1x<='9') && (c1y>='0' && c1y<='9') && (c1x==c1y)))  {

if ((c2x-'a'==c2y-'a') || (c2x-'A'==c2y-'A') || (c2x-'A'==c2y-'a') || (c2x-'a'==c2y-'A')||((c2x>='0' && c2x<='9') && (c2y>='0' && c2y<='9') && (c2x==c2y))){
printf("IGUAIS");}
}else {printf("DIFERENTES");}


return 0;}



