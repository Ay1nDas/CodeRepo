#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int findGrith(vector<vector<int>> &graph, int curr_node, vector<int> &dist, int curr_dist) {
  int min_grith = INT_MAX;

  // for (auto &i : dist) {
  //   cout << i << " ";
  // }
  // cout <<  endl;

  // cout << "Parent: " << curr_node << " Child: ";
  // for (auto &child : graph[curr_node]) {
  //   cout << child << " ";
  // }
  // cout << endl;
  for (auto &child : graph[curr_node]) {
    if (dist[child] == 0) {
      dist[child] = curr_dist + 1;
      min_grith = min(min_grith, findGrith(graph, child, dist, curr_dist + 1));
      dist[child] = 0;
    } else if (curr_dist - dist[child] > 1) {
      // cout << "Curr: " << dist[child] - curr_dist + 1 << endl;
      min_grith = min(min_grith, curr_dist - dist[child] + 1);
    }
  }

  return min_grith;
}

int main()
{

  fast_io;
  
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    int node_a, node_b;
    cin >> node_a >> node_b;

    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
  }

  vector<int> dist(n + 1);
  dist[1] = 1;
  int min_grith = findGrith(graph, 1, dist, 1);

  cout << (min_grith == INT_MAX ? -1 : min_grith) << endl;
  return 0;
}