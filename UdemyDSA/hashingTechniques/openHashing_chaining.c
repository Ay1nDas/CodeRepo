#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int val;
  struct node *next;
} Node;

typedef struct hash
{
  int hashCnt;
  Node **table;
  int tableSz;
} Hash;

Hash *createHashTable(int tSz)
{
  Hash *tmpTable = malloc(sizeof(Hash));

  tmpTable->hashCnt = 0;
  tmpTable->table = calloc(tSz, sizeof(Node *));
  tmpTable->tableSz = tSz;
}

bool insertVal(Hash *h, int value)
{
  int key = value % (h->tableSz);
  Node *v = malloc(sizeof(Node));
  v->val = value;
  v->next = NULL;

  if (h->table[key] == NULL)
  {
    h->table[key] = v;
  }
  else
  {
    Node *n = h->table[key];
    while (n->next)
      n = n->next;
    n->next = v;
  }
  h->hashCnt++;
  return true;
}

bool getVal(Hash *h, int value)
{
  int key = value % (h->tableSz);

  Node *n = h->table[key];
  while (n)
  {
    if (n->val == value)
      return true;
    n = n->next;
  }

  return false;
}

bool delVal(Hash *h, int value)
{
  int key = value % (h->tableSz);

  if (h->table[key] && h->table[key]->val == value)
  {
    Node *tmp = h->table[key];
    h->table[key] = h->table[key]->next;

    free(tmp);
    h->hashCnt--;
    return true;
  }

  Node *n = h->table[key];
  while (n)
  {
    if (n->next && n->next->val == value)
    {
      Node *tmp = n->next;
      n->next = n->next->next;

      free(tmp);
      h->hashCnt--;
      return true;
    }
    n = n->next;
  }

  return false;
}

void freeHashTable() {}

int main()
{
  int arr[] = {4, 15, 3, 12, 55, 20, 11, 7};
  int arrSz = sizeof(arr) / sizeof(arr[0]);
  Hash *hashTable = createHashTable(arrSz);

  for (int i = 0; i < arrSz; i++)
    insertVal(hashTable, arr[i]);

  printf("Value %d is%spresent in the arr.\n", 15, getVal(hashTable, 15) ? " " : " not ");
  printf("Value %d is%spresent in the arr.\n", 7, getVal(hashTable, 7) ? " " : " not ");
  printf("Value %d is%spresent in the arr.\n", 0, getVal(hashTable, 0) ? " " : " not ");

  printf("Value %d is%spresent in the arr.\n", 55, getVal(hashTable, 55) ? " " : " not ");
  delVal(hashTable, 55);
  printf("Value %d is%spresent in the arr.\n", 55, getVal(hashTable, 55) ? " " : " not ");

  for (int i = 0; i < arrSz; i++)
    delVal(hashTable, arr[i]);

  return 0;
}