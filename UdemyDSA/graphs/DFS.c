#include <stdio.h>
#include <stdlib.h>

void dfs(int **graph, int *visited, int sz, int node)
{
  if (visited[node] == 0)
  {
    printf("%d ", node);
    visited[node] = 1;
  }

  for (int vertex = 1; vertex <= sz; vertex++)
  {
    if (graph[node][vertex] == 1 && visited[vertex] == 0)
      dfs(graph, visited, sz, vertex);
  }
}

int main()
{
  int n, edgeSize;
  scanf("%d %d", &n, &edgeSize);

  int **graph = malloc((n + 1) * sizeof(int *));
  for (int i = 0; i < n + 1; i++)
    graph[i] = calloc(n + 1, sizeof(int));

  for (int i = 0; i < edgeSize; i++)
  {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    graph[n1][n2] = 1;
    graph[n2][n1] = 1;
  }

  int *visited = calloc((n + 1), sizeof(int));
  dfs(graph, visited, n, 1);

  // for (int i = 0; i < n; i++)
  //   printf("%d ", dfsVale[i]);
  printf("\n");
  return 0;
}