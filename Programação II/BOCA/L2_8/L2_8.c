
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 1, n, m, cont = 0, sucessorParaN = 0;
    scanf("%d%d", &n, &m);
    printf("RESP:");
    while (n > 0 && n < m-1) {
        sucessorParaN = n + 1;
        n++;
        cont = 0;
        i = 1;

        while (sucessorParaN >=i) {
            if (sucessorParaN % i == 0) {
                cont++;
                i++;
            } else {
                i++;
            }
        }
        if (cont == 2) {
            printf("%d ", sucessorParaN);
        }
    }

    return 0;
}
