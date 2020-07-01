#include <stdio.h>

int main(){
	int a=0, b=0, den=1, i=0, mdc=0, mmc=0, limMDC=0, limMMC=0;

	scanf("%d %d", &a, &b);


	//Acha limites da busca
	if (a < b){ 
		limMDC = a;
		limMMC = a*b;
	} else {
		limMDC = b;
		limMMC = a*b;
	}
	
	//MDC
	for(den=1; den <= limMDC; den++){   
		if((a%den==0) && (b%den==0)){ 
			mdc = den;
		}
	}
	
	//MMC
	i = 1;
	while(i<=(a*b)){
		if((i%a==0) && (i%b==0) && i!=1){     
			mmc = i;
			break; }
                else{
                    i++;
                }
                
	}

	printf("%d %d", mdc, mmc);

	return 0;
}