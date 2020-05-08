#include <stdio.h>
int main(){
int N1=0,N2=0,N3=0,auxn1=0,auxn2=0,auxn3=0;
scanf("%d%d%d",&N1,&N2,&N3); 

auxn1=(N1/100);
N1=auxn1;
auxn1=((N1/10)*10);
N1=N1-auxn1;


auxn2=(N2/100);
N2=auxn2;
auxn2=((N2/10)*10);
N2=N2-auxn2;


auxn3=(N3/100);
N3=auxn3;
auxn3=((N3/10)*10);
N3=N3-auxn3;

if (N1<=N3 && N3<=N2){if (N1>0){printf("N1");}else{if(N3>0){printf("N3");}}}
if (N1<=N2 && N2<N3){if (N1>0){printf("N1");}else{printf("N2");}}
if (N2<=N3 && N3<N1){if (N2>0){printf("N2");}else{printf("N3");}}
if (N2<N1 && N1<N3){if (N2>0){printf("N2");}else{printf("N1");}}
if (N3<N1 && N1<N2){if (N3>0){printf("N3");}else{printf("N1");}}
if (N3<N2 && N2<N1){if (N3>0){printf("N3");}else{printf("N2");}}

else {if (N1==0 && N2 == 0 && N3 == 0)printf("Nenhum");}

return 0;}
