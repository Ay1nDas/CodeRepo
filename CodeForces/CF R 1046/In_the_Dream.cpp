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
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int min1 = min(a1, b1);
    int max1 = max(a1, b1);

    bool isPoss = true;
    if (max1 > (min1 + 1) * 2)
      isPoss = false;

    int min2 = min(a2 - a1, b2 - b1);
    int max2 = max(a2 - a1, b2 - b1);

    if (max2 > (min2 + 1) * 2)
      isPoss = false;

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}