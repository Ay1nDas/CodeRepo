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
    int n;
    cin >> n;
    vector<vector<int>> bombs(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
      cin >> bombs.at(i).at(0);
      cin >> bombs.at(i).at(1);
    }

    int xi, yi, xt, yt;
    cin >> xi >> yi >> xt >> yt;

    ll dist = pow(xi - xt, 2) + pow(yi - yt, 2);
    bool possibleToReach = true;
    // cout << "DIST: " << dist << endl
    //  << endl;

    for (auto bomb : bombs)
    {
      // cout << "X: " << bomb.at(0) << " " << "Y: " << bomb.at(1) << endl;
      // cout << "Value: " << pow(bomb.at(0) - xt, 2) + pow(bomb.at(1) - yt, 2) << endl;
      if (pow(bomb.at(0) - xt, 2) + pow(bomb.at(1) - yt, 2) <= dist)
      {
        // cout << "HERE!" << endl;
        possibleToReach = false;
        break;
      }
    }
    // cout << possibleToReach << endl;
    cout << (possibleToReach ? "YES" : "NO") << endl;
  }
  return 0;
}