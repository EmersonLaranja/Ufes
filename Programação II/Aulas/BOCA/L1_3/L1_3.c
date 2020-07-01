#include <stdio.h>
int main(){
float x0,y0,x,y,perimetro;
scanf("%f%f%f%f",&x0,&y0,&x,&y);
perimetro=(2*(x-x0))+(2*(y-y0));
printf("%.2f",perimetro);
return 0;
}


