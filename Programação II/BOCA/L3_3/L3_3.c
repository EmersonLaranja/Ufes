#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num) {
    int divisor = 1, cont = 0,result=0;
    while (num >= divisor) {
        if (num % divisor == 0) {
            cont++;
            divisor++;
        } else {
            divisor++;
        }
    }
    if (cont == 2) {
        printf("%d ",num);
    }
    return result;
}

int main() {
    int n, m, num,result;
    scanf("%d %d", &n, &m);
    num = n + 1;
    while (n <= num && num < m) {
        result=EhPrimo(num);
        num++;
    }
    return 0;
}

