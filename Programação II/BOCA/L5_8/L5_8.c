
#include <stdio.h>
#include <stdlib.h>

void Inicializacao(int* n,int qtd){
    int i=0;
    for(i=0;qtd>i;i++){
        scanf("%d",&n[i]);
    }
}

void TrocaParEImpar(int vet[], int qtd) {
    int i = 0, aux = 0;
    if(qtd>=2){
    for (i=0;qtd>(i);i++) {
        if (i == 0 || i % 2 == 0) {
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
        }}
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i=0;
    if(qtd==0){printf("{}");}
    if(qtd==1){printf("{%d}",vet[i]);}
    if(qtd>1){
        for(i=0;qtd>i;i++) {
            if (i == 0) {
                printf("{%d,", vet[i]);
            }
            if (i != 0 && i != (qtd)) {
                printf(" %d,", vet[i]);
            }
            if (i == qtd) {
                printf(" %d}", vet[i]);
            }
            
    }
}
}
int main(){
    int qtd=0;
    scanf("%d",&qtd);
    int vet[qtd];
    Inicializacao(vet,qtd);
    TrocaParEImpar(vet,qtd);
    ImprimeDadosDoVetor(vet,qtd);
    
    return 0;
}

