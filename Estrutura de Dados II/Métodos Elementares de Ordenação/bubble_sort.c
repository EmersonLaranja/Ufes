#include "item.h"

void sort(Item *a, int lo, int hi)
{
  int temp;
  for (int i = lo; i <= hi; i++)
  {
    for (int j = 0; j <= hi - i - 1; j++)
    {
      if (a[j + 1] < a[j])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}