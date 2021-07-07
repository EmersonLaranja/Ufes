#include "item.h"

void sort(Item *a, int lo, int hi)
{
  int i, j, temp;
  for (i = lo; i <= hi / 2; i++)
  {
    for (j = i - 1; j < hi - i; j++)
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    for (j = hi - i - 1; j >= i; j--)
      if (a[j] < a[j - 1])
      {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
  }
}