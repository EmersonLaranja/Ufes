#include <stdio.h>
#include <stdlib.h>
int main() {
    int n=0,m=0,a=0,b=1;
    scanf("%d%d",&n,&m);
    a=n;    
    while (a>=n && a<=m){
        
        while(b>=1 && b<=10){
            printf("%d x %d = %d\n",a,b,a*b);
            b++;
        }
        a++;
        b=1;
    }
    

    return 0;
}

