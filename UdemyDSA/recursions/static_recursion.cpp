#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
  static int x = 0;
  if (n > 0)
  {
    x++;
    return static_cast<float>(x) + func(n - 1);
  }
  return 0;
}

int main()
{
  cout << func(5) << endl;
  return 0;
}