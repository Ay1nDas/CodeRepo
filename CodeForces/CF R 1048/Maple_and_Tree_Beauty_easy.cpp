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

int leastDeep(vector<vector<int>> &tree, int node, int curr_lvl)
{
  if (tree.at(node).size() == 0)
    return curr_lvl;

  int lowest = INT_MAX;
  for (auto n : tree.at(node))
  {
    int depth = leastDeep(tree, n, curr_lvl + 1);
    lowest = min(depth, lowest);
  }

  return lowest;
}

int maxColoredElements(const vector<int> &nodeCnt, int zeroCnt, int oneCnt)
{
  int m = nodeCnt.size();
  ll total = 0;
  vector<char> dp(zeroCnt + 1, 0);
  dp[0] = 1;

  int best = 0;
  for (int k = 1; k <= m; ++k)
  {
    int x = nodeCnt[k - 1];
    total += x;

    if (total > (ll)zeroCnt + (ll)oneCnt)
      break;

    int upto = min<ll>(zeroCnt, total);
    for (int s = upto; s >= x; --s)
    {
      if (!dp[s] && dp[s - x])
        dp[s] = 1;
    }

    int low = max<ll>(0, total - oneCnt);
    int high = upto;
    bool ok = false;
    if (low <= high)
    {
      for (int s = low; s <= high; ++s)
      {
        if (dp[s])
        {
          ok = true;
          break;
        }
      }
    }
    if (ok)
      best = k;
    else
      break;
  }

  return best;
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> tree(n + 1);

    for (int i = 2; i <= n; i++)
    {
      int parent;
      cin >> parent;

      tree.at(parent).push_back(i);
    }

    int lowestLvl = leastDeep(tree, 1, 0);
    // cout << lowestLvl << endl;

    vector<int> nodeCnt(lowestLvl + 1);

    queue<int> q;
    q.push(1);
    int level = 0;

    while (q.size() > 0 && level <= lowestLvl)
    {

      int currSz = q.size();

      while (currSz--)
      {
        int node = q.front();
        q.pop();

        for (auto i : tree.at(node))
          q.push(i);

        nodeCnt.at(level)++;
      }
      level++;
    }
    int zeroCnt = k, oneCnt = n - k;
    // cout << "Zero: " << zeroCnt << " One: " << oneCnt << endl;
    // cout << "Nodes to select: ";
    // for (auto i : nodeCnt)
    //   cout << i << " ";
    // cout << endl;

    cout << maxColoredElements(nodeCnt, zeroCnt, oneCnt) << endl;
  }

  return 0;
}