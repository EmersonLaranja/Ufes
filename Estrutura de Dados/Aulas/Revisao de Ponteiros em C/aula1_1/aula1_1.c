#include <stdio.h>

int main()
{
  int var1, var2, var3, var4;
  int *p1 = &var1, *p2 = &var2, *p3 = &var3, *p4 = &var4;

  printf("Digite 4 numeros aqui: ");
  scanf(" %d %d %d %d", p1, p2, p3, p4);
  printf("\nVar1: %d, Ponteiro1: %d. Uau! Que coincidencia!!\n", var1, *p1);
  printf("Var2: %d, Ponteiro2: %d. Uau! Que coincidencia!!\n", var2, *p2);
  printf("Var3: %d, Ponteiro3: %d. Uau! Que coincidencia!!\n", var3, *p3);
  printf("Var4: %d, Ponteiro4: %d. Uau! Que coincidencia!!\n\n", var4, *p4);

  *p1 = *p1 + 10;  //similar a var1=var1+10
  *p2 = *p3 * *p3; //similar a var2=var3*var3
  p3 = p4;         //similar a var3=var4

  printf("Primeiro Ponteiro:%d\n", *p1);
  printf("Segundo Ponteiro:%d\n", *p2);
  printf("Terceiro Ponteiro:%d\n", *p3);
  printf("Quarto Ponteiro:%d\n", *p4);

  return 0;
}
