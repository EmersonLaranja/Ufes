#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
extern void sort(Item *a, int lo, int hi);

int main(int argc, char const *argv[])
{
  clock_t start, stop;
  FILE *file = fopen(argv[1], "r");

  int qntItems = atoi(argv[2]);
  int *itemsArray = (Item *)malloc(qntItems * sizeof(Item));

  for (int i = 0; i < qntItems; i++)
    fscanf(file, "%d", &itemsArray[i]);
  fclose(file);

  start = clock();
  //sort algorithm
  sort(itemsArray, 0, qntItems - 1);
  stop = clock();

  // for (int i = 0; i < qntItems; i++)
  //   printf("%d ", itemsArray[i]);

  double time_taken = ((double)stop - start) / CLOCKS_PER_SEC;

  printf(" %.4f\n", time_taken);

  free(itemsArray);
  return 0;
}
