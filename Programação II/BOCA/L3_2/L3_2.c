#include <stdio.h>

float Soma(float num1, float num2) {
    float result;
    result = num1 + num2;
    return result;
}

float Subtracao(float num1, float num2) {
    float result;
    result = num1 - num2;
    return result;
}

float Divisao(float num1, float num2) {
    float result;
    result = num1 / num2;
    return result;
}

float Multiplicacao(float num1, float num2) {
    float result;
    result = num1*num2;
    return result;
}

int main() {
    float num1 = 0, num2 = 1, result = 0, i = 0;
    char operador = '\0';
    if (i == 0) {
        scanf("%f", &num1);
        i++;
    }
    while (scanf(" %f %c", &num2, &operador) == 2) {
        if (operador == '+') {
            result = Soma(num1, num2);
            num1 = result;
        }
        if (operador == '-') {
            result = Subtracao(num1, num2);
            num1 = result;
        }
        if (operador == '/') {
            result = Divisao(num1, num2);
            num1 = result;
        }
        if (operador == '*') {
            result = Multiplicacao(num1, num2);
            num1 = result;
        }
    }


    printf("%.2f", result);




    return 0;

}