#include <stdio.h>
#include <stdlib.h>
int main() {
    int i=0,n=0,m=0,ab=0,cd=0,ef=0,resultante=0;
    scanf("%d%d",&n,&m);
    i=n+1;
    while( i>1000 && m<9999 && i<m){
        ab=i/100;
        cd=i-((i/100)*100);
        ef=ab+cd;
        resultante=ef*ef;
        if(resultante==i){
            printf("%d\n",resultante);
        }
        i++;
    }

    return 0;
}

