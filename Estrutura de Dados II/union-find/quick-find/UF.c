#include "UF.h"

static int id[1000];
static int N;
void UF_init(int size)
{
  N = size;
  for (int i = 0; i < N; i++)
  {
    id[i] = i; // Cada objeto comeca na sua propria componente.
  }            // N acessos ao array.
}
int UF_find(int p)
{
  return id[p]; // Retorna o id da componente de p. 1 acesso.
}
void UF_union(int p, int q)
{
  int pid = id[p];
  int qid = id[q];
  for (int i = 0; i < N; i++)
  {
    if (id[i] == pid)
    {              // Troca todas os valores de id[p]
      id[i] = qid; // por id[q].
    }              // No maximo 2N + 2 acessos ao array.
  }
}

bool UF_connected(int p, int q)
{
  return UF_find(p) == UF_find(q);
}