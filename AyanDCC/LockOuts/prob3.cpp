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
  int n;
  cin >> n;
  if (n % 4 == 0 && n != 2)
  {
    cout << 0 << endl;
  }
  else if (n % 2 == 0)
  {
    cout << 1 << endl;
  }
  else if (n % 4 == 3)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << 1 << endl;
  }

  return 0;
}