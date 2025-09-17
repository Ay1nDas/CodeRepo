#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x;

  printf("Enter x: ");
  scanf("%d", &x);

  int netSalary1 = (x + 0.12 * x + 0.15 * x + 0.25 * x - 0.17 * x);
  int netSalary2 = (x + x * 12 / 100 + x * 15 / 100 + x * 25 / 100 - x * 17 / 100);
  // printf("%f %f %f %f\n", 0.12 * x*, 0.15 * x, 0.25 * x, 0.17 * x);
  printf("The Net Salary1: %d\n", netSalary1);
  printf("The Net Salary2: %d\n", netSalary2);
  return 0;
}