#include <stdio.h>
#include <stdlib.h>

struct student
{
  char name[10];
  int roll;
  float cgpa;
};

int main()
{
  struct student *sPtr = malloc(sizeof(struct student));

  printf("Enter student Name: ");
  scanf("%s", sPtr->name);

  printf("Enter student Roll: ");
  scanf("%d", &sPtr->roll);

  printf("Enter student CGPA: ");
  scanf("%f", &sPtr->cgpa);

  printf("Student's Name: %s\n", sPtr->name);
  printf("Student's Roll: %d\n", sPtr->roll);
  printf("Student's CGPA: %.2f\n", sPtr->cgpa);

  return 0;
}