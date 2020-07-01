
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int i=1,cont=0,entrada=0;
    scanf("%d",&entrada);
    while(i<=entrada){
        if(entrada%i==0){
            cont++;
            i++;
        }else{
            i++;
        }
    }
    if(cont==2){
        printf("Primo");
    }
    else{
        printf("Nao Primo");
    }   

    return (EXIT_SUCCESS);
}

