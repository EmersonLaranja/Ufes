#include <stdio.h>
int main(){
int n1,n2;
float media;
scanf("%i%i",&n1,&n2);
media =((float)(n1+n2))/2;
if (media>=7){
printf("%.1f - Aprovado",media);}
else if (media>=5 && media<7){
printf("%.1f - De Recuperacao",media);}
else{
printf("%.1f - Reprovado",media);}
return 0;
}
