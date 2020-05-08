#include <stdio.h>
#include <stdlib.h>
int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    int total,retangulo1,retangulo2,variacaox,variacaoy;
    retangulo1=(r1_x2-r1_x1)*(r1_y2-r1_y1);
    retangulo2=(r2_x2-r2_x1)*(r2_y2-r2_y1);
    total=retangulo1+retangulo2;
    return total;
        
    
}

int area (int x1, int y1, int x2, int y2){
    int variacaoy,variacaox,resultado;
    variacaoy=y2-y1;
    variacaox=x2-x1;
    resultado=variacaox*variacaoy;
    return resultado;
}

int main() {
    int total,retangulo1,retangulo2,r1_x1,r1_y1,r1_x2,r1_y2,r2_x1,r2_y1,r2_x2,r2_y2;
    scanf("%d %d %d %d",&r1_x1,&r1_y1,&r1_x2,&r1_y2);
    retangulo1=area(r1_x1,r1_y1,r1_x2,r1_y2);
    scanf("%d %d %d %d",&r2_x1,&r2_y1,&r2_x2,&r2_y2);
    retangulo2=area(r2_x1,r2_y1,r2_x2,r2_y2);
    total=area_total(r1_x1,r1_y1,r1_x2,r1_y2,r2_x1,r2_y1,r2_x2,r2_y2);
    printf("RESP:%d",total);
    return 0;
}

