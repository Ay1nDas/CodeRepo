#include <stdio.h>
#include <stdlib.h>

int main()
{
  char str[] = "Hi, This is a string!";
  int strSize = sizeof(str) / sizeof(str[0]);
  int vowelCount = 0;
  int consCount = 0;

  for (int i = 0; i < strSize; i++)
  {
    char c = str[i];

    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
      continue;

    switch (c)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      vowelCount++;
      break;
    default:
      consCount++;
    }
  }

  printf("Vowel: %d, Consonent: %d", vowelCount, consCount);

  return 0;
}