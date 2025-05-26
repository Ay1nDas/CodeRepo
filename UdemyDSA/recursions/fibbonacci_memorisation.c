#include <stdio.h>
#include <stdlib.h>

long long fibbo(int n, long long *mem)
{
  if (n <= 1)
  {
    mem[n] = n;
    return n;
  }
  else
  {
    if (mem[n - 1] == -1)
      mem[n - 1] = fibbo(n - 1, mem);
    if (mem[n - 2] == -1)
      mem[n - 2] == fibbo(n - 2, mem);

    mem[n] = mem[n - 1] + mem[n - 2];
    return mem[n];
  }
}

int main()
{
  int n = 100;
  long long *mem = malloc((n + 1) * sizeof(long long));
  for (int i = 0; i <= n; i++)
  {
    mem[i] = -1;
  }
  printf("fibbo: %lld\n", fibbo(n, mem));
  free(mem);

  return 0;
}