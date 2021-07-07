#include "item.h"

void sort(Item *a, int lo, int hi)
{
  int j, k;
  for (int i = lo; i <= hi; i++)
  {
    j = i - 1;
    k = a[i];
    while (j >= 0 && k < a[j])
    {
      a[j + 1] = a[j];

      j--;
    }
    a[j + 1] = k;
  }
}