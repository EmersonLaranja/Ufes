#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF INT_MAX

typedef struct
{
  int u, v, w;
} Edge;

int dist[MAX_NODES], pred[MAX_NODES];
Edge edge[MAX_EDGES];
int n, m;

int BellmanFord(int source)
{
  int i, j;

  for (i = 0; i < n; i++)
  {
    dist[i] = INF;
    pred[i] = -1;
  }
  dist[source] = 0;

  for (i = 0; i < n - 1; i++)
    for (j = 0; j < m; j++)
    {
      if (dist[edge[j].v] > dist[edge[j].u] + edge[j].w)
      {
        dist[edge[j].v] = dist[edge[j].u] + edge[j].w;
        pred[edge[j].v] = edge[j].u;
      }
    }

  for (j = 0; j < m; j++)
  {
    if (dist[edge[j].v] > dist[edge[j].u] + edge[j].w)
      return 0;
  }
  return 1;
}

int main()
{
  int qntCases, i;
  scanf("%d", &qntCases);
  while (qntCases--)
  {
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    if (BellmanFord(0))
      printf("not ");
    printf("possible\n");
  }
  return 0;
}