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
    vector<int> series(4);
    for (int i = 0; i < 4; i++)
    {
      cin >> series.at(i);
    }

    int c1 = series.at(0) + series.at(1);
    int c2 = series.at(2) - series.at(1);
    int c3 = series.at(3) - series.at(2);

    if (c1 == c2 && c2 == c3)
    {
      cout << 3 << endl;
    }
    else if (c1 == c2 || c2 == c3 || c1 == c3)
    {
      cout << 2 << endl;
    }
    else
    {
      cout << 1 << endl;
    }
  }

  return 0;
}