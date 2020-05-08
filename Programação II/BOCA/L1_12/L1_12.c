#include <stdio.h>
int main (){
int n1=0,n2=0,n3=0;
scanf("%d%d%d",&n1,&n2,&n3);
if (n1>n2 && n2>n3){printf("N3 = %d, N2 = %d, N1 = %d",n3,n2,n1);}
if (n1>n3 && n3>n2){printf("N2 = %d, N3 = %d, N1 = %d",n2,n3,n1);}
if (n2>n1 && n1>n3){printf("N3 = %d, N1 = %d, N2 = %d",n3,n1,n2);}
if (n2>n3 && n3>n1){printf("N1 = %d, N3 = %d, N2 = %d",n1,n3,n2);}
if (n3>n1 && n1>n2){printf("N2 = %d, N1 = %d, N3 = %d",n2,n1,n3);}
if (n3>n2 && n2>n1){printf("N1 = %d, N2 = %d, N3 = %d",n1,n2,n3);}
return 0;
}
