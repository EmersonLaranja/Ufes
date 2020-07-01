#include <stdio.h>
#include <stdlib.h>

int main() {
    char l = '\0';
    scanf("%c", &l);
    printf("RESP:");
    while (l != '!' && l != '.' && l != '?') {
        if (l == ' ') {
            printf("");
        } else {
            printf("%c", l);
        }
        scanf("%c", &l);
    }
    printf("%c", l);

    return 0;
}

