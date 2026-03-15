#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

bool dfs(int i, vector<vector<int>>& connections, unordered_map<int, int>& used, int lvl) {
  used[i] = lvl % 2 + 1;

  for(auto j : connections.at(i)) {
    bool isPoss = true;
    if(used[j] == 0) {
      isPoss = dfs(j, connections, used, lvl + 1);
    }
    
    if(!isPoss || used[j] == used[i]) {
      return false;
    }
  }
  return true;
}

int main()
{

  fast_io;
  int n, m;
  cin >> n >> m;

  unordered_map<int, int> used;
  vector<vector<int>> connections(n+1);

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    connections.at(a).push_back(b);
    connections.at(b).push_back(a);
  }

  bool isPoss = true;
  for(int i=1; i<=n; i++) {
    if(used[i] == 0) {
      isPoss = dfs(i, connections, used, 0);
    }

    if(!isPoss) {
      break;
    }
  }

  if(!isPoss) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      cout << used[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
