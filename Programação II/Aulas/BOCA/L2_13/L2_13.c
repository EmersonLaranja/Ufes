#include <stdio.h>
#include <stdlib.h>

int main() {
    char l = '\0';
    scanf("%c", &l);
    while (l != '.' && l != '!' && l != '?') {
        if (l >= 'a' && l <= 'z') {
            printf("%c", l - 32);
        } else {
            printf("%c", l);
        }

        scanf("%c", &l);

    }
    printf("%c", l);


    return 0;
}

