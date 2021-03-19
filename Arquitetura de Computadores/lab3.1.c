#include "limits.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
  int a = INT_MAX, b = INT_MAX;
  // Demonstrando comportamento em roleta
  printf("%d\n", a + 0);
  printf("%d\n", a + 1);
  printf("%d\n", a + 2);
  printf("%d\n", a + 3);
  printf("...\n");
  printf("%d\n", a + b);
  return 0;
}
