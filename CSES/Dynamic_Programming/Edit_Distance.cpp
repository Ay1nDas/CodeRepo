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
  string initial, final;
  cin >> initial >> final;

  vector<vector<int>> grid(initial.length() + 1, vector<int>(final.length() + 1));

  for (int i = 0; i <= initial.length(); i++)
    grid.at(i).at(0) = i;
  for (int j = 0; j <= final.length(); j++)
    grid.at(0).at(j) = j;

  for (int i = 1; i <= initial.length(); i++)
  {
    for (int j = 1; j <= final.length(); j++)
    {
      if (initial.at(i - 1) == final.at(j - 1))
      {
        grid.at(i).at(j) = grid.at(i - 1).at(j - 1);
      }
      else
      {
        int add = grid.at(i).at(j - 1);
        int remove = grid.at(i - 1).at(j);
        int replace = grid.at(i - 1).at(j - 1);

        grid.at(i).at(j) = min(add, min(remove, replace)) + 1;
      }
    }
  }

  cout << grid.at(initial.length()).at(final.length()) << endl;
  return 0;
}