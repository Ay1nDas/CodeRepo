#include <bits/stdc++.h>
using namespace std;

long long fibbo(int n)
{
  if (n <= 1)
  {
    return n;
  }
  return fibbo(n - 2) + fibbo(n - 1);
}

int main()
{
  cout << fibbo(45) << endl;
  return 0;
}