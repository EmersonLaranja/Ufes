#include <stdio.h>
int main(){
char codx1,codx2,codx3,cody1,cody2,cody3,r1,r2,r3;
scanf("%c%c%c %c%c%c",&codx1,&codx2,&codx3,&cody1,&cody2,&cody3);

if( (codx1>='0' && codx1<='9') && (cody1>='0' && cody1<='9')  )
	{if (codx1 == cody1) {r1 ='I';}
		else {r1 ='D';}}			
			else {printf("Codigo invalido!");return 0;}




if(  (codx2>='a' && codx2<='z') && (cody2>='a' && cody2<='z')  )
	{if (codx2==cody2) {r2='I';}
		else {r2 ='D';}}
			else {printf("Codigo invalido!");return 0;}
			


if(  ((codx3>='A' && codx3 <='Z')||(codx3>='a' && codx3 <='z')) && ((cody3>='a' && cody3 <='z')||(cody3>='A' && cody3 <='Z'))  )
	{if (codx3==cody3){r3='I';}
	else {if  ((cody3-codx3!=32)||(codx3-cody3!=-32)) {r3='D';}}}
						else {printf("Codigo invalido!");return 0;}


if(  ((codx3>='A' && codx3 <='Z')||(codx3>='a' && codx3 <='z')) && ((cody3>='a' && cody3 <='z')||(cody3>='A' && cody3 <='Z'))  )
	if ((cody3-codx3==32)||(codx3-cody3==-32)) {r3 = 'C';}
						else {printf("Codigo invalido!");return 0;}


	






printf("%c%c%c",r1,r2,r3);
return 0;}
