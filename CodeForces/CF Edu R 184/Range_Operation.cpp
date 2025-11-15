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
    int n;
    cin >> n;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> arr.at(i);
    }

    vector<ll> prefixSum(n + 1);

    prefixSum.at(1) = arr.at(1);
    for (int i = 2; i <= n; i++)
    {
      prefixSum.at(i) = prefixSum.at(i - 1) + arr.at(i);
    }

    ll maxAdd = 0;

    for (int i = 1; i <= n; i++)
    {
      ll addVal = prefixSum.at(i - 1) + i * 2;
      maxAdd = max(maxAdd, addVal - prefixSum.at(i));

      // cout << "ADD: " << addVal << endl;
      if (addVal > prefixSum.at(i))
      {
        int j;
        for (j = i + 1; j <= n; j++)
        {
          if ((i + j) * (j - i + 1) + prefixSum.at(i - 1) >= prefixSum.at(j))
          {
            addVal = (i + j) * (j - i + 1) + prefixSum.at(i - 1);
            maxAdd = max(maxAdd, addVal - prefixSum.at(j));
          }
          else
          {
            break;
          }
        }
        i = j - 1;

        maxAdd = max(maxAdd, addVal - prefixSum.at(i));
        // cout << "MAX: " << maxAdd << endl;
      }
    }

    // cout << "ANS: ";
    cout << prefixSum.back() + maxAdd << endl;
  }

  return 0;
}