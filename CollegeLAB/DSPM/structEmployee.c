#include <stdio.h>
#include <stdlib.h>

struct employee
{
  char name[10];
  double salary;
};

int main()
{
  struct employee *emp = malloc(sizeof(struct employee));

  int sz = 1;
  int idx = 0;
  char addMore = 'y';

  do
  {
    if (idx == sz)
    {
      sz *= 2;
      emp = realloc(emp, sizeof(struct employee) * sz);
    }

    printf("Enter employee Name: ");
    scanf("%s", emp[idx].name);

    printf("Enter employee Salary: ");
    scanf("%lf", &emp[idx].salary);

    idx++;

    printf("Enter More(y/n)? :");
    scanf("%c%c", &addMore, &addMore);

  } while (addMore == 'y');

  printf("\n");

  for (int i = 0; i < idx; i++)
  {
    printf("%s has Salary(rs): %.2lf/- \n", emp[i].name, emp[i].salary);
  }

  return 0;
}