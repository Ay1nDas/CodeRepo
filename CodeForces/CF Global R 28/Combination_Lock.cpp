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
    string x;
    cin >> x;

    int sum[2] = {0};
    for (int i = 0; i < x.length(); i++)
      sum[i % 2] += x.at(i) - '0';

    // cout << "SUM: " << endl
    //      << sum[0] << endl
    //      << sum[1] << endl;

    if (abs(sum[0] - sum[1]) % 11 == 0 && (sum[0] + sum[1]) % 3 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}