#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef long long ll;

ll min(ll a, ll b)
{
  return (a > b ? b : a);
}

ll min_cost(int **nodes, char tgt, char dest, int *visited)
{
  if (tgt == dest)
  {
    return 0;
  }

  ll min_val = INT_MAX;
  visited[tgt - 'a']++;
  for (int c = 'a'; c <= 'z'; c++)
  {
    if (nodes[tgt - 'a'][c - 'a'] == 0 || visited[c - 'a'])
    {
      continue;
    }

    ll curr_val = min_cost(nodes, c, dest, visited);
    if (curr_val != INT_MAX)
    {
      min_val = min(curr_val + nodes[tgt - 'a'][c - 'a'], min_val);
    }
  }

  visited[tgt - 'a']--;
  return min_val;
}

long long minimumCost(char *source, char *target, char *original, int originalSize, char *changed, int changedSize, int *cost, int costSize)
{
  int **nodes = malloc(sizeof(int *) * 26);
  for (int i = 0; i < 26; i++)
  {
    nodes[i] = calloc(sizeof(int), 26);
    // for (int j = 0; j < 26; j++)
    // {
    //   nodes[i][j] = 0;
    // }
  }

  ll memorize[26][26];
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      memorize[i][j] = -1;
    }
  }

  for (int i = 0; i < originalSize; i++)
  {
    nodes[original[i] - 'a'][changed[i] - 'a'] = cost[i];
  }

  ll total_cst = 0;
  for (int i = 0; source[i] != '\0'; i++)
  {
    int visited[26] = {0};
    if (memorize[source[i] - 'a'][target[i] - 'a'] == -1)
    {
      memorize[source[i] - 'a'][target[i] - 'a'] = min_cost(nodes, source[i], target[i], visited);
    }
    if (memorize[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
    {
      return -1;
    }
    total_cst += memorize[source[i] - 'a'][target[i] - 'a'];
    // printf("%c %c %lld \n", source[i], target[i], cst);
  }

  for (int i = 0; i < 26; i++)
  {
    free(nodes[i]);
  }
  free(nodes);

  return total_cst;
}

int main()
{

  return 0;
}
