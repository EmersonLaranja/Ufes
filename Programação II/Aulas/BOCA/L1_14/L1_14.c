#include <stdio.h>
int main(){
float x0=0,y0=0,x=0,y=0,px=0,py=0;
scanf("%f%f%f%f%f%f",&x0,&y0,&x,&y,&px,&py);
if (px>=x0 && py>=y0 && px<=x && py<=y){
printf("Dentro");}
else{
printf("Fora");}
return 0;
}
