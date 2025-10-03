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
    int n, m;
    cin >> n >> m;
    vector<char> command(n);
    for (auto &c : command)
      cin >> c;

    vector<int> blackCells(m);
    vector<int> newBlack;

    for (int i = 0; i < m; i++)
      cin >> blackCells.at(i);

    int cellIdx = 1;
    int blackIdx = 0;
    for (auto c : command)
    {
      if (c == 'A')
      {
        cellIdx++;
        if (blackIdx >= blackCells.size() || blackCells.at(blackIdx) != cellIdx)
        {
          newBlack.push_back(cellIdx);
        }
        while (blackIdx < blackCells.size() && blackCells.at(blackIdx) <= cellIdx)
        {
          blackIdx++;
        }
      }
      else
      {
        cellIdx++;
        while (blackIdx < blackCells.size() && cellIdx == blackCells.at(blackIdx))
        {
          blackIdx++;
          cellIdx++;
        }
        newBlack.push_back(cellIdx);
      }
    }

    cout << blackCells.size() + newBlack.size() << endl;
    int pre = 0, after = 0;
    while (pre < blackCells.size() && after < newBlack.size())
    {
      if (blackCells.at(pre) < newBlack.at(after))
        cout << "b" << blackCells.at(pre++) << " ";
      else
        cout << "n" << newBlack.at(after++) << " ";
    }

    for (int i = pre; i < blackCells.size(); i++)
      cout << "b" << blackCells.at(i) << " ";
    for (int i = pre; i < newBlack.size(); i++)
      cout << "n" << newBlack.at(i) << " ";

    cout << endl;
  }

  return 0;
}