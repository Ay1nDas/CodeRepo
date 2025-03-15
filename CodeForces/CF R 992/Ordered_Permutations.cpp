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
    ll k;
    cin >> k;

    // if (n == 1)
    // {
    //   cout << 1 << endl;
    //   continue;
    // }

    vector<int> used(n + 1, 1); // BE CAREFULL OF 0.
    vector<ll> indexing(n + 1); // BE CAREFULL OF 0.

    indexing.at(n - 1) = 1;
    for (int i = n - 2; i > 0; i--)
      indexing.at(i) = 2 * indexing.at(i + 1);

    string reqd_num;
    int current_int{1};
    bool isPossible = true;
    while (k > 0)
    {
      if (indexing.at(current_int) < k)
      {
        k -= indexing.at(current_int++);
      }
      else
      {
        reqd_num += to_string(current_int);
        reqd_num += ' ';
        used.at(current_int++) = 0;
      }

      if (current_int >= n)
      {
        break;
      }
    }

    if (k > 1)
    {
      cout << -1 << endl;
      continue;
    }

    for (int i = n; i > 0; i--)
    {
      if (used.at(i) != 0)
      {
        reqd_num += to_string(i);
        reqd_num += ' ';
      }
    }

    cout << reqd_num << endl;
  }

  return 0;
}