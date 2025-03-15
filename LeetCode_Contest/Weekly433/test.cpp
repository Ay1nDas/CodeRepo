#include <bits/stdc++.h>
using namespace std;

long long comb(int n, int r)
{
  r = min(r, n - r);

  if (r == 0)
    return 1;

  long long numerator = 1, denominator = 1;

  for (int i = 0; i < r; i++)
  {
    numerator *= n;
    denominator *= i + 1;
    n--;
  }
  return numerator / denominator;
}

int main()
{
  cout << comb(5, 3) << endl;
  cout << comb(3, 2) << endl;
  cout << comb(5, 5) << endl;
  return 0;
}