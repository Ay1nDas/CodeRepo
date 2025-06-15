#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getPermu(int *vals, char stack[], int currLen, int maxStrLen)
{
  if (currLen == maxStrLen)
  {
    static int count = 0;
    stack[currLen] = '\0';
    printf("%d. %s\n", ++count, stack);
    return;
  }

  for (int i = 0; i < 'z' - 'A' + 1; i++)
  {
    if (vals[i])
    {
      stack[currLen] = i + 'A';
      vals[i]--;
      getPermu(vals, stack, currLen + 1, maxStrLen);
      vals[i]++;
    }
  }
}

void displayPermutation(char str[])
{
  int *vals = calloc('z' - 'A' + 1, sizeof(int));
  char *stack = calloc(strlen(str) + 1, sizeof(char));

  for (int i = 0; str[i] != '\0'; i++)
    vals[str[i] - 'A']++;
  getPermu(vals, stack, 0, strlen(str));

  free(vals);
  free(stack);
}

long long fact(int n)
{
  long long f = 1;
  for (int i = 1; i <= n; i++)
    f *= i;
  return f;
}

long long countPermutation(char str[])
{
  int *vals = calloc('z' - 'A' + 1, sizeof(int));

  for (int i = 0; str[i] != '\0'; i++)
    vals[str[i] - 'A']++;

  long long count = fact(strlen(str));
  for (int i = 0; i < 'z' - 'A' + 1; i++)
    count /= fact(vals[i]);

  free(vals);
  return count;
}

int main()
{

  char str[] = "ABC";
  printf("Permtation Count: %lld\n", countPermutation(str));
  displayPermutation(str);

  return 0;
}