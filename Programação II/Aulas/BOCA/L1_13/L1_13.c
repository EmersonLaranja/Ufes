#include <stdio.h>
int main(){
int pessoas,itens,resto;
scanf("%i%i",&pessoas,&itens);
resto = itens%pessoas;
if (resto == 0){printf("RESP:%i",pessoas);}
else {printf("RESP:%i",resto);}
return 0; }


