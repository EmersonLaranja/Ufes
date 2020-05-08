#include <stdio.h>
int main (){
char caractere,aux;
scanf("%c",&caractere);
if (caractere >=97 && caractere <=122){
aux =(caractere-32);
printf("%c(%d)",aux,(int)aux);}
else if (caractere <= 64 || caractere >=91 && caractere<97 || caractere > 120){
printf("Nao e letra!");}
else if (caractere>=65 && caractere<=90){
printf("A letra deve ser minuscula!");}
return 0;
}



