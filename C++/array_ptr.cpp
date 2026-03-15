#include <bits/stdc++.h>
using namespace std;

void func(int *arr) {
  cout << arr[0] << arr[1] << arr[2] << endl;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  func(&arr[2]);
  return 0;
}