#include <stdio.h>
int main(){
int x0,y0,x,y;
scanf("%i %i %i %i",&x0,&y0,&x,&y);
if (x0<x && y0<y){printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)",x0,y,x0,y0,x,y0,x,y);}
if (x0<x && y0>y){printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)",x0,y0,x0,y,x,y,x,y0);}
if (x0>x && y0>y){printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)",x,y0,x,y,x0,y,x0,y0);}
if (x0>x && y0<y){printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)",x,y,x,y0,x0,y0,x0,y);}
return 0;
}
