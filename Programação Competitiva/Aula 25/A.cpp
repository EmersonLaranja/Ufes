#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, i, j, k, fa[100], t, aux, b[100];
  scanf("%d", &n);

  for (i = 2; i <= n; i++)
    scanf("%d", &fa[i]);

  j = 0;
  fa[1] = 0;
  aux = n;
  while (fa[aux] != 0)
  {
    j++;
    b[j] = aux;
    aux = fa[aux];
  }
  cout << 1 << " ";
  for (i = j; i >= 1; i--)
    cout << b[i] << " ";
  return 0;
}