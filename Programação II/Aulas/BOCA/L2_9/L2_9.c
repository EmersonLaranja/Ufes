
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 1, n, m, cont = 0, sucessorParaN = 0, j = 0, contMult = 0;
    scanf("%d%d", &n, &m);
    while (n > 0 && n < m - 1) {
        sucessorParaN = n + 1;
        n++;
        cont = 0;
        i = 1;
        contMult = 0;

        while (sucessorParaN >= i) {
            if (sucessorParaN % i == 0) {
                cont++;
                i++;
            } else {
                i++;
            }
        }
        if (cont == 2) {
            printf("%d\n", sucessorParaN);
            j = sucessorParaN + 1;
            while (j <= m - 1) {
                if (j % sucessorParaN == 0) {
                    printf("%d ", j);
                    contMult++;
                    j++;
                } else {
                    j++;
                }
            }
            if (contMult == 0) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
