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

int main()
{

  fast_io;
  int n;
  cin >> n;

  vector<int> minVals(n + 1, 1);

  for (int i = 10; i <= n; i++)
  {
    int num = i;
    int minSteps = INT_MAX;
    while (num)
    {
      int currDig = num % 10;
      num /= 10;

      if (currDig == 0)
        continue;

      int currStep = minVals.at(i - currDig) + 1;
      minSteps = min(currStep, minSteps);
    }

    minVals.at(i) = minSteps;
  }

  cout << minVals.at(n) << endl;

  return 0;
}