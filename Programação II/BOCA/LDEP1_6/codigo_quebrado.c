#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int soma = 0, atual;

	scanf("%d %d", &l, &c);

	
	for (i = 0; i<c; i++){
		for(j = 0; j<l; j++){
			scanf("%d", &atual);
			soma += atual;
		}
		printf("%d\n", soma);
	}

	printf("%d\n", soma);

	return 0;
}
