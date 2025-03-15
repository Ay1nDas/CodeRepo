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
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
      cin >> nums.at(i);

    bool isPossible{true};

    for (int i = 0; i < n; i++)
    {
      isPossible = true;
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;

        if (abs(nums.at(i) - nums.at(j)) % k == 0)
        {
          isPossible = false;
          break;
        }
      }
      if (isPossible)
      {
        cout << "YES" << endl;
        cout << i + 1 << endl;
        break;
      }
    }
    if (!isPossible)
      cout << "NO" << endl;
  }

  return 0;
}