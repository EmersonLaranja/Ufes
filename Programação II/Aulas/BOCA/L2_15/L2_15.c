
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char j;
    int entrada = 0, qntNegativos = 0, qntPositivos = 0, somaNegativos = 0, somaPositivos = 0, parada = 0;
    while (1) {
        j = '\0';
        scanf("%d%c", &entrada, &j);
        if (j != ' ' && j != '\t' && j != '\r' && j != '\v' && j != '\f' || j == '\0') {
            parada++;
        }
        if (entrada < 0) {
            qntNegativos++;
            somaNegativos = somaNegativos + entrada;
        }
        if (entrada > 0) {
            qntPositivos++;
            somaPositivos = somaPositivos + entrada;
        }
        if (j != ' ' && j != '\t' && j != '\r' && j != '\v' && j != '\f' || j == '\0') {
            parada++;
        }
    }
    printf("%d %d %d %d", qntNegativos, qntPositivos, somaNegativos, somaPositivos);


    return (EXIT_SUCCESS);
}

