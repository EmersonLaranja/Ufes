#include <stdio.h>
#include <stdlib.h>

void Inicializacao(int* vet, int tam) {
    int i;
    for (i = 0; tam > i; i++) {
        scanf("%d", &vet[i]);
    }
}

int EhMenor(int a,int b){
    return a<b;
}

int MenorDosProximos(int* vet,int a,int b){
    int i,id=a,menor=vet[a];
    for(i=a+1;b>=i;i++){
        if(EhMenor(vet[i],menor)){
            menor=vet[i];
            id=i;
        }
    }
    return id;
}




void TrocaValor(int* vet,int i,int ind){
    int aux;
    aux=vet[ind];
    vet[ind]=vet[i];
    vet[i]=aux;
           
}
void OrdenaCrescente(int vet[], int qtd){
    int i=0,menor,ind;
    for(i=0;qtd-1>i;i++){
        menor=vet[i];
        ind=MenorDosProximos(vet,i+1,qtd-1);
        if(EhMenor(vet[ind],vet[i])){
            TrocaValor(vet,i,ind);
        }
    }
}

int EstaContido(int c, int* vetX, int x) {
    int i;
    for (i = 0; x > i; i++) {
        if (vetX[i] == c) {
            return 1;
        }
    }
    return 0;
}

void ImprimeLoucamente(int* vetA, int a, int* vetB, int b, int* vetC, int c) {
    int i = 0;
    for (i = 0; c > i; i++) {
        if (EstaContido(vetC[i], vetA, a)) {
            printf("A");
        }
        if (EstaContido(vetC[i], vetB, b)) {
            printf("B");
        }
    }
}

void NovaSequencia(int* vetA, int a, int* vetB, int b, int* vetC, int c) {
    int i = 0, j = 0;
    while (a > i) {
        vetC[i] = vetA[i];
        i++;
    }
    while (b > j) {
        vetC[i + j] = vetB[j];
        j++;
    }
}

int main() {
    int a, b, c;

    scanf("%d", &a);
    int vetA[a];
    Inicializacao(vetA, a);
    scanf("%d", &b);
    int vetB[b];
    Inicializacao(vetB, b);
    OrdenaCrescente(vetA, a);
    OrdenaCrescente(vetB, b);
    c = a + b;
    int vetC[c];
    NovaSequencia(vetA, a, vetB, b, vetC, c);
    OrdenaCrescente(vetC, c);
    ImprimeLoucamente(vetA, a, vetB, b, vetC, c);

    return 0;
}

