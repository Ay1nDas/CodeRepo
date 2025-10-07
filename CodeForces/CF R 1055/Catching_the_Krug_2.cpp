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

    vector<int> vertical(2), horizontal(2);

    if (rk < rd)
      vertical = {ck, 0};
    else if (rk > rd)
      vertical = {ck, n};
    else
      vertical = {-1, -1};

    if (ck < cd)
      horizontal = {0, rk};
    else if (ck > cd)
      horizontal = {n, rk};
    else
      horizontal = {-1, -1};

    // cout << vertical.at(0) << " " << vertical.at(1) << endl;
    // cout << horizontal.at(0) << " " << horizontal.at(1) << endl;

    int vDist = 0, hDist = 0;
    if (vertical.at(0) == -1)
    {
      vDist = abs(ck - cd);
    }
    else
    {
      vDist = max(abs(vertical.at(0) - cd), abs(vertical.at(1) - rd));
    }

    if (horizontal.at(0) == -1)
    {
      hDist = abs(rk - rd);
    }
    else
    {
      hDist = max(abs(horizontal.at(0) - cd), abs(horizontal.at(1) - rd));
    }

    // cout << vDist << " " << hDist << endl;
    cout << max(hDist, vDist) << endl;
  }

  return 0;
}