#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int multiply(int n, int mi, int mj, int dimensions[])
{
  if (mi == mj)
    return 0;

  int minCost = INT_MAX;
  for (int k = mi; k < mj; k++)
  {
    int cost = multiply(n, mi, k, dimensions) + multiply(n, k + 1, mj, dimensions) + dimensions[mi - 1] * dimensions[k] * dimensions[mj];

    minCost = min(cost, minCost);
  }

  return minCost;
}

int main()
{
  fast_io;
  int n = 4;
  int dimensions[] = {3, 2, 4, 2, 5};

  cout << "MinCost to Multiply: " << multiply(n, 1, 4, dimensions) << endl;
  return 0;
}