#include "item.h"

void sort(Item *a, int lo, int hi)
{

  for (int i = lo; i <= hi; i++)
  {
    for (int j = i + 1; j <= hi; j++)
    {
      if (a[j] < a[i])
      {
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
      }
    }
  }
}