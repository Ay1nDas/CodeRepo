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
  int n;
  cin >> n;
  vector<vector<char>> grid(n + 1, vector<char>(n + 1));
  vector<vector<string>> words(n + 1, vector<string>(n + 1));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> grid.at(i).at(j);
  words.at(1).at(1) += grid.at(1).at(1);

  for (int i = 2; i <= n; i++)
  {
    words.at(1).at(i) = words.at(1).at(i - 1) + grid.at(1).at(i);
    words.at(i).at(1) = words.at(i - 1).at(1) + grid.at(i).at(1);
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 2; j <= n; j++)
    {
      if (words.at(i - 1).at(j) < words.at(i).at(j - 1))
        words.at(i).at(j) = words.at(i - 1).at(j) + grid.at(i).at(j);
      else
        words.at(i).at(j) = words.at(i).at(j - 1) + grid.at(i).at(j);

      words.at(i - 1).at(j) = string();
      // words.at(i).at(j - 1) = string();
    }
  }

  cout << words.at(n).at(n) << endl;
  return 0;
}