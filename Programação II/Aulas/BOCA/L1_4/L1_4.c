#include <stdio.h>
#include <math.h>
#define pi 3.141592
int main()
{
float raio_area,area,raio_novo;
scanf("%f",&raio_area);
area= raio_area*raio_area*pi;
printf("%.2f ",area);
raio_novo = sqrt(((area/2)/pi));
printf("%.2f",raio_novo);
return 0;
}
