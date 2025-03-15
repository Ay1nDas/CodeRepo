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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n + 1);
    vector<int> bits(32);
    arr.at(0) = bits;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;

      for (int j = 0; j < 32 && num > 0; j++)
      {
        bits.at(j) += num % 2;
        num /= 2;
      }
      arr.at(i + 1) = bits;
      // for (int n : arr.at(i + 1))
      // {
      //   cout << n << " ";
      // }
      // cout << endl;
    }

    while (q--)
    {
      int l, r;
      cin >> l >> r;
      l--;

      long long value{0};

      for (int i = 31; i >= 0; i--)
      {
        if (arr.at(l).at(i) != arr.at(r).at(i))
          value += pow(2, i);
      }
      cout << value << endl;
    }
  }

  return 0;
}