#include<math.h>
#include <stdio.h>
#include <stdlib.h>

void CompletaVetor(int* n, int tam) {
    int i;
    for (i = 0; tam > i; i++) {
        scanf("%d", &n[i]);
        
    }
}

int CalculaMaior(int* n, int tam) {
    int i = 0, primeira = 0, maior;
    while (tam > i) {
        if (primeira == 0) {
            maior = n[i];
            primeira++;
            i++;
            continue;
        }
        if (n[i] > maior) {
            maior = n[i];
        }
        i++;
    }
    return maior;
}

int CalculaMenor(int* n, int tam) {
    int i = 0, primeira = 0, menor;
    while (tam > i) {
        if (primeira == 0) {
            menor = n[i];
            primeira++;
            i++;
        }
        if (n[i] < menor) {
            menor = n[i];
        }
        i++;
    }
    return menor;
}

float CalculaMedia(int* n, int tam) {
    float soma=0, media;
    int i = 0;
    while (tam > i) {
        soma = soma + n[i];
        i++;
    }
    media = soma / tam;
    return media;
}

int CalculaAcimaDaMedia(int* n, int tam, float media) {
    int i = 0, cont = 0;
    while (tam > i) {
        if (n[i] > media) {
            cont++;
        }
        i++;
    }
    return cont;
}

int CalculaReprovado(int* n, int tam) {
    int i = 0, cont = 0;
    while (tam > i) {
        if (n[i] < 70) {
            cont++;
        }
        i++;
    }
    return cont;
}

float CalculaDesvio(int tam, int* n, float media) {
    int i=0;
    float  soma = 0, equacao = 0;
    while (tam > i) {
        equacao = ((n[i] - media)*(n[i] - media));
        soma = soma + equacao;
        i++;
    }
    soma = soma * (1 /(float) tam);
    soma = sqrt(soma);
    return soma;
}

int main(int argc, char** argv) {
    int tam, i = 0, maior, menor, acimaDaMedia, reprovado;
    float media, desvio;
    scanf("%d", &tam);
    int n[tam];
    CompletaVetor(n, tam);
    
    
    menor = CalculaMenor(n, tam);
    maior = CalculaMaior(n, tam);
    media = CalculaMedia(n, tam);
    acimaDaMedia = CalculaAcimaDaMedia(n, tam, media);
    reprovado = CalculaReprovado(n, tam);
    desvio = CalculaDesvio(tam, n, media);
    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", menor, maior, media, desvio, acimaDaMedia, reprovado);

    return (EXIT_SUCCESS);
}

