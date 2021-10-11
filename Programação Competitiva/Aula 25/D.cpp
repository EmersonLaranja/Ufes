#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int a[30000];
  for (int i = 1; i <= n - 1; i++)
  {
    scanf("%d", &a[i]);
  }
  int aux = 0;
  for (int i = 1; i < n;)
  {
    i = i + a[i];
    if (i == m)
    {
      aux = 1;
    }
  }

  if (aux == 1)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}