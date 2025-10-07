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
    int n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    if (rk == rd && ck == cd)
    {
      cout << 0 << endl;
      continue;
    }

    vector<int> north(2), east(2), south(2), west(2);
    north = {ck, rk};
    east = {ck, rk};
    south = {ck, rk};
    west = {ck, rk};

    vector<int> dGridMin(2), dGridMax(2);
    dGridMin = {cd, rd};
    dGridMax = {cd, rd};

    int rounds = 1;

    while (dGridMin.at(0) > 0 || dGridMin.at(1) > 0 || dGridMax.at(0) < n || dGridMax.at(1) < n)
    {
      dGridMin.at(0) = max(0, dGridMin.at(0) - 1);
      dGridMin.at(1) = max(0, dGridMin.at(1) - 1);

      dGridMax.at(0) = min(n, dGridMax.at(0) + 1);
      dGridMax.at(1) = min(n, dGridMax.at(1) + 1);

      north.at(1) = min(n, north.at(1) + 1);
      south.at(1) = max(0, south.at(1) - 1);
      east.at(0) = min(n, east.at(0) + 1);
      west.at(0) = max(0, west.at(0) - 1);

      int pts = 4;

      if (north.at(0) >= dGridMin.at(0) && north.at(0) <= dGridMax.at(0) &&
          north.at(1) >= dGridMin.at(1) && north.at(1) <= dGridMax.at(1))
        pts--;

      if (south.at(0) >= dGridMin.at(0) && south.at(0) <= dGridMax.at(0) &&
          south.at(1) >= dGridMin.at(1) && south.at(1) <= dGridMax.at(1))
        pts--;

      if (east.at(0) >= dGridMin.at(0) && east.at(0) <= dGridMax.at(0) &&
          east.at(1) >= dGridMin.at(1) && east.at(1) <= dGridMax.at(1))
        pts--;

      if (west.at(0) >= dGridMin.at(0) && west.at(0) <= dGridMax.at(0) &&
          west.at(1) >= dGridMin.at(1) && west.at(1) <= dGridMax.at(1))
        pts--;

      if (pts != 0)
        rounds++;
      else
        break;
    }

    cout << rounds << endl;
  }

  return 0;
}