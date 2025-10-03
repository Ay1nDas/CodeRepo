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

void getConnected(vector<vector<int>> &roads, int v, unordered_map<int, int> &connected)
{
  connected[v]++;

  queue<int> cities;
  cities.push(v);

  while (cities.size())
  {
    int curr_city = cities.front();
    cities.pop();
    connected[curr_city]++;

    for (auto i : roads.at(curr_city))
    {
      if (connected[i] == 0)
        cities.push(i);
    }
  }
}

int main()
{

  fast_io;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> roads(n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;

    roads.at(a).push_back(b);
    roads.at(b).push_back(a);
  }

  unordered_map<int, int> connected;
  getConnected(roads, 1, connected);

  vector<vector<int>> reqd_roads;
  for (int i = 2; i <= n; i++)
  {
    if (connected[i] == 0)
    {
      reqd_roads.push_back({i, 1});
      getConnected(roads, i, connected);
    }
  }

  cout << reqd_roads.size() << endl;
  for (auto r : reqd_roads)
    cout << r.at(0) << " " << r.at(1) << endl;

  return 0;
}