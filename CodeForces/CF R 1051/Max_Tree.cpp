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

void assignPermutation(vector<vector<vector<int>>> &tree, int v, int p, int &low, int &high, vector<int> &reqdPerm)
{
  // cout << "v p c x y: " << v << " " << p << " " << tree.at(v).at(i).at(0) << " " << tree.at(v).at(i).at(0) << " " << tree.at(v).at(i).at(0) << endl;

  // cout << "v p: " << v << " " << p << endl;

  // for (int i = 0; i < tree.at(v).size(); i++)
  // {
  //   for (auto i : tree.at(v).at(i))
  //     cout << i << " ";
  //   cout << endl;
  // }
  // cout << endl;

  for (int i = 0; i < tree.at(v).size(); i++)
  {
    if (tree.at(v).at(i).at(0) == p)
      continue;

    assignPermutation(tree, tree.at(v).at(i).at(0), v, low, high, reqdPerm);

    int c = tree.at(v).at(i).at(0);
    int x = tree.at(v).at(i).at(1);
    int y = tree.at(v).at(i).at(2);

    if (x > y)
    {
      if (c < v)
        reqdPerm.at(c) = high--; // NEED low?
      else
        reqdPerm.at(c) = low++;
    }
    else
    {
      if (c < v)
        reqdPerm.at(c) = low++; // NEED high?
      else
        reqdPerm.at(c) = high--;
    }
  }
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<vector<vector<int>>> tree(n + 1);

    for (int i = 1; i < n; i++)
    {
      int u, v, x, y;
      cin >> u >> v >> x >> y;

      tree.at(u).push_back({v, x, y});
      tree.at(v).push_back({u, x, y});
    }

    int low = 1, high = n;
    vector<int> reqdPerm(n + 1);

    assignPermutation(tree, 1, 0, low, high, reqdPerm);
    reqdPerm.at(1) = low++;

    // cout << "Ans: ";
    for (int i = 1; i <= n; i++)
      cout << reqdPerm.at(i) << " ";
    cout << endl;
  }

  return 0;
}