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

void getDepth(vector<vector<int>> &tree, vector<int> &depth, int parent, int node)
{
  for (auto child : tree.at(node))
  {
    if (child != parent)
    {
      depth.at(child) = depth.at(node) + 1;
      getDepth(tree, depth, node, child);
    }
  }
}

int main()
{

  fast_io;

  int n;
  cin >> n;

  vector<vector<int>> tree(n + 1);
  vector<int> depth(n + 1);

  for (int i = 0; i < n - 1; i++)
  {
    int parent, child;
    cin >> parent >> child;
    tree.at(child).push_back(parent);
    tree.at(parent).push_back(child);
  }

  getDepth(tree, depth, 0, 1);

  int deepest_node = 1;
  int max_depth = 0;
  for (int i = 1; i <= n; i++)
  {
    if (max_depth < depth.at(i))
    {
      max_depth = depth.at(i);
      deepest_node = i;
    }
    depth.at(i) = 0;
  }

  getDepth(tree, depth, 0, deepest_node);
  max_depth = 0;

  for (int i = 1; i <= n; i++)
  {
    if (max_depth < depth.at(i))
      max_depth = depth.at(i);
  }

  cout << max_depth << endl;

  return 0;
}