#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} Node;

void radixSort(int arr[], int arrSize)
{
  Node *radix[10];
  for (int i = 0; i < 10; i++)
    radix[i] = NULL;

  int max = arr[0];
  for (int i = 1; i < arrSize; i++)
    if (arr[i] > max)
      max = arr[i];

  int dig = 1;
  while (dig <= max)
  {
    for (int i = 0; i < arrSize; i++)
    {
      Node *new = malloc(sizeof(Node));
      new->val = arr[i];
      new->next = NULL;

      int curr_radix = (arr[i] / dig) % 10;
      Node *top = radix[curr_radix];

      if (top)
      {
        while (top->next)
          top = top->next;
        top->next = new;
      }
      else
      {
        radix[curr_radix] = new;
      }
    }

    int arrIdx = 0;
    for (int i = 0; i < 10; i++)
    {
      if (radix[i])
      {
        Node *n = radix[i];
        while (n)
        {
          arr[arrIdx++] = n->val;
          Node *tmp = n;
          n = n->next;

          free(tmp);
        }
        radix[i] = NULL;
      }
    }

    dig *= 10;
  }
}

int main()
{
  int arr[] = {237, 146, 259, 348, 152, 164, 23, 1000, 2};
  radixSort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
