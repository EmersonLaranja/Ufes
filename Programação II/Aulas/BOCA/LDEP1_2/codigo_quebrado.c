#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int idade;

    scanf("%d", &idade);

    if(idade < 16)  printf("vc não pode votar!");
    if(idade >= 16 && idade < 18) printf("vc pode votar, mas nao eh obrigado!");
    if(idade >= 18 && idade < 65) printf("vc eh obrigado a votar!");
    if(idade >= 65) printf("vc pode votar, mas nao eh obrigado!");
    

    return 0;
}
