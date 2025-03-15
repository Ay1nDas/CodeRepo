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

    vector<vector<int>> tree(n);
    int principal_node;
    cin >> principal_node;
    int buffer_edge;
    cin >> buffer_edge;

    tree.at(principal_node - 1).push_back(buffer_edge);

    for (int i = 2; i < n; i++)
    {
      int node, edge;
      cin >> node >> edge;
      tree.at(node - 1).push_back(edge);
    }

    // for (int i = 0; i < n; i++)
    // {
    //   cout << i << ": ";
    //   for (auto i : tree.at(i))
    //   {
    //     cout << i << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    int max_node = 0;
    int max_size = tree.at(0).size();
    if (principal_node == 1)
      max_size--;
    vector<int> second_max_node;
    int sec_size = 0;

    for (int i = 1; i < n; i++)
    {
      int edges = tree.at(i).size();
      if (i == principal_node - 1)
      {
        edges--;
      }

      if (edges > max_size)
      {
        second_max_node.clear();
        second_max_node.push_back(max_node);
        sec_size = max_size;

        max_node = i;
        max_size = edges;
      }
      else if (second_max_node.size() == 0)
      {
        second_max_node.push_back(i);
        sec_size = edges;
      }
      else if (sec_size < edges)
      {
        second_max_node.clear();
        second_max_node.push_back(i);
        sec_size = edges;
      }
      else if (sec_size == edges)
      {
        second_max_node.push_back(i);
      }
    }

    bool edgeNotFound = false;
    // cout << max_node << " : " << second_max_node.at(0) << endl;

    for (auto i : second_max_node)
    {
      auto it1 = find(tree.at(max_node).begin(), tree.at(max_node).end(), i + 1);

      if (it1 == tree.at(max_node).end())
      {
        auto it2 = find(tree.at(i).begin(), tree.at(i).end(), max_node + 1);
        if (it2 == tree.at(i).end())
          edgeNotFound = true;
        break;
      }
    }

    cout << max_size + sec_size + (edgeNotFound ? 1 : 0) << endl;
  }

  return 0;
}