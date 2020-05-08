
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char** argv) {
    float pi,soma,k;
    int n=0;
    scanf("%d",&n);
    k=1;
    soma=0;
    while (k<=n){
        soma=soma+(6/(k*k));
        k++;        
    }
    pi= sqrt(soma);
    printf("%.6f",pi);
    return (EXIT_SUCCESS);
}

