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
    int a, b;
    cin >> a >> b;

    if (a == b)
      cout << 0 << endl;
    else if (a % b == 0 || b % a == 0)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }

  return 0;
}