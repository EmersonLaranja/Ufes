#include <stdio.h>

int main() {
    int i = 1, den = 1, qtd = 0, cont = 0;

    scanf("%d", &qtd);

    for (i = 2; i <= qtd; i++) {
        
        while (i >= den) {
            if (i % den == 0) {
                cont++;
                den++;
            } else {
                den++;
            }
        }
        if (cont == 2)
            printf("%d ", i);
        den=1;
        cont=0;
        
        
    }

    return 0;
}