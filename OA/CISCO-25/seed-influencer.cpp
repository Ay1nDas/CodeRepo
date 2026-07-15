#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

void getTotalVal(int seed, const vector<vector<int>>& conns, const vector<int>& values, vector<bool>& visited, int d) {
  visited[seed] = true;
  if (d == 0) {
    return;
  }

  for (int i = 0; i < conns[seed].size(); i++) {
    if (!visited[conns[seed][i]]) {
      getTotalVal(conns[seed][i], conns, values, visited, d - 1);
    }
  }
}

int main()
{
  fast_io;

  int user_sz;
  cin >> user_sz;
  int conn_sz;
  cin >> conn_sz;
  vector<vector<int>> conns(conn_sz + 1);
  for (int i = 0; i < conn_sz; i++) {
    int a, b;
    cin >> a >> b;
    conns[a].push_back(b);
    conns[b].push_back(a);

    int seed_sz;
    cin >> seed_sz;
    vector<pair<int, int>> seeds(seed_sz);
    for(auto& seed : seeds) {
      cin >> seed.first >> seed.second;
    }

    vector<int> values(user_sz);
    for(auto& i : values) {
      cin >> i;
    }

    int budget, d;
    cin >> budget >> d;

    vector<vector<bool>> can_reach(seed_sz, vector<bool>(user_sz, false));
    for(int i = 0; i < seed_sz; i++) {
      getTotalVal(seeds[i].first, conns, values, can_reach[i], d);
    }
  }

  return 0;
}