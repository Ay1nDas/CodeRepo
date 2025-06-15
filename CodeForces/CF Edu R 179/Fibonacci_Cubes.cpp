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

  vector<int> fibo(11);
  fibo.at(0) = 0;
  fibo.at(1) = 1;
  fibo.at(2) = 2;

  for (int i = 3; i <= 10; i++)
  {
    fibo.at(i) = fibo.at(i - 1) + fibo.at(i - 2);
  }

  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;

    // vector<int> possible(m);
    // int poss_ptr = 0;
    while (m--)
    {
      int l, b, h;
      cin >> l >> b >> h;

      if (l < fibo.at(n) || b < fibo.at(n) || h < fibo.at(n))
      {
        cout << 0;
        continue;
      }

      int max_vol = fibo.at(n) + fibo.at(n - 1);
      if (l >= max_vol || b >= max_vol || h >= max_vol)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
  }

  return 0;
}
