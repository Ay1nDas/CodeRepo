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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1);

  for (int i = 1; i < n + 1; i++)
    cin >> a.at(i);
  for (int i = 1; i < m + 1; i++)
    cin >> b.at(i);

  vector<vector<int>> LCS(n + 1, vector<int>(m + 1));

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      if (a.at(i) == b.at(j))
        LCS.at(i).at(j) = LCS.at(i - 1).at(j - 1) + 1;
      else
        LCS.at(i).at(j) = max(LCS.at(i).at(j - 1), LCS.at(i - 1).at(j));
    }
  }

  int maxVal = LCS.at(n).at(m);
  vector<int> resLCS(maxVal);

  int i = n, j = m;
  while (i > 0 && j > 0)
  {
    if (LCS.at(i - 1).at(j) == LCS.at(i).at(j))
    {
      i--;
    }
    else if (LCS.at(i).at(j - 1) == LCS.at(i).at(j))
    {
      j--;
    }
    else
    {
      resLCS.at(--maxVal) = a.at(i);
      i--;
      j--;
    }
  }

  cout << resLCS.size() << endl;
  for (auto i : resLCS)
    cout << i << " ";
  cout << endl;

  return 0;
}