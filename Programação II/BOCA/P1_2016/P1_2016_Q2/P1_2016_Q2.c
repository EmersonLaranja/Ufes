#include <stdio.h>
int main(){
int fx1,fx2,fx3,a,b,x1,y1,x2,y2,x3,y3;
scanf("%i%i%i%i%i%i%i%i",&a,&b,&x1,&y1,&x2,&y2,&x3,&y3);

fx1=(a*x1)+b;
fx2=(a*x2)+b;
fx3=(a*x3)+b;

if (fx1==y1 && fx2==y2 && fx3==y3) {printf("Todos");}

if ((fx1!=y1 && fx2!=y2 && fx3==y3)||(fx1!=y1 && fx2==y2 && fx3!=y3) || (fx1 ==y1 && fx2!=y2 && fx3!=y3)){printf("Um");}

if ((fx1==y1 && fx2==y2 && fx3!=y3)||(fx1==y1 && fx2!=y2 && fx3==y3)||(fx1!=y1 && fx2==y2 && fx3==y3)) {printf("Dois");}

if (fx1!=y1 && fx2!=y2 && fx3!=y3) {printf("Nenhum");}

return 0;
}




