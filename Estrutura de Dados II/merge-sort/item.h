#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))
#define CUTOFF 16
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) \
  {                \
    Item t = A;    \
    A = B;         \
    B = t;         \
  }
#define compexch(A, B) \
  if (less(B, A))      \
  exch(A, B)

#endif /* ITEM_H */