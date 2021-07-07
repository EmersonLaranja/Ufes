#include <stdio.h>

int josefo(int n, int k)
{
  if (n == 1)
    return 1;
  else
  {
    return (josefo(n - 1, k) + k - 1) % n + 1;
  }
}

int main()
{
  int n = 9;
  int k = 5;
  printf("The chosen place is %d\n", josefo(n, k));
  return 0;
}