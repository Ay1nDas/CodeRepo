#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 998244353;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    ll val = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr.at(i) != 1)
        continue;

      // cout << "i: " << i << endl;

      ll two_count = 0;
      for (int j = i + 1; j < n; j++)
      {
        if (arr.at(j) == 2)
        {
          two_count++;
          continue;
        }
        else if (arr.at(j) == 1)
        {
          continue;
        }
        // cout << "j: " << j << endl;
        ll temp_val = 1;
        ll base = 2;
        ll two_count_cpy = two_count;

        // cout << "j: " << j << " cnt: " << two_count << endl;

        while (two_count_cpy > 0)
        {
          if (two_count_cpy % 2 == 1)
          {
            temp_val = (temp_val * base) % mod;
          }
          base = (base * base) % mod;
          two_count_cpy /= 2;
        }
        // cout << "tmp: " << temp_val << endl;
        val += (temp_val - 1) % mod;

        // val += pow(2, two_count) - 1;
        // cout << "Val: " << val << endl;
      }
    }

    cout << val % mod << endl;
  }

  return 0;
}