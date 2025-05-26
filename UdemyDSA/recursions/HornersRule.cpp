#include <bits/stdc++.h>
using namespace std;

double e(double x, int n)
{

  if (n == 0)
  {
    return 1;
  }
  else
  {
    static double r = 1;

    return 1 + (x / r++) * e(x, n - 1);
  }
}

int main()
{
  cout << e(1, 10) << endl;
  return 0;
}