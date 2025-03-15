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
    int buns;
    cin >> buns;

    if (buns % 2 == 1)
    {
      cout << -1;
    }
    else
    {
      for (int i = 1; i <= buns / 2; i++)
        cout << i << " " << i << " ";
    }
    cout << endl;
  }

  return 0;
}