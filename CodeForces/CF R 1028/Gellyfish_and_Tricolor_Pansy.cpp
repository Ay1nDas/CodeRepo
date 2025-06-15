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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (min(a, c) > min(b, d))
    {
      cout << "Gellyfish" << endl;
    }
    else if (min(a, c) == min(b, d))
    {
      cout << "Gellyfish" << endl;
    }
    else
    {
      cout << "Flower" << endl;
    }
  }

  return 0;
}