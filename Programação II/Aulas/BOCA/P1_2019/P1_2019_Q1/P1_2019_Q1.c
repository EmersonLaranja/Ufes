#include <stdio.h>
int main(){
    int n1,n2,n3;
    scanf("%d%d%d",&n1,&n2,&n3);
    if (n1>n2 && n2>n3){
        printf("DECRESCENTE");
    }else if (n3>n2 && n2>n1){
        printf("CRESCENTE");
    }else {printf("TUDO DOIDO");
    }
    return 0;
}