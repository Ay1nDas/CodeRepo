#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

    vector<pair<ll, ll>> coords(n);
    for(int i = 0; i < n; i++) {
      cin >> coords.at(i).first >> coords.at(i).second;
    }

    unordered_map<int, unordered_map<int, ll>> sq_dist;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        ll x_dist = abs(coords.at(i).first - coords.at(j).first);
        ll y_dist = abs(coords.at(i).second - coords.at(j).second);
        sq_dist[i][j] = x_dist * x_dist + y_dist * y_dist;
        sq_dist[j][i] = x_dist * x_dist + y_dist * y_dist;
      }
    }
  }

  return 0;
}
