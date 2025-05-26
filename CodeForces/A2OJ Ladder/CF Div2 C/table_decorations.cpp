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
  vector<int> color(3);
  int total_table = 0;

  for (int i = 0; i < 3; i++)
  {
    cin >> color.at(i);
  }

  sort(color.begin(), color.end());

  int tab = (color.at(2) - color.at(1)) / 2;
  tab = min(color.at(0), tab);

  color.at(0) -= tab;
  total_table += tab;
  color.at(2) -= tab * 2;

  if (color.at(0))
  {
    color.at(1) -= color.at(0);
    color.at(2) -= color.at(0);
    total_table += color.at(0);
  }

  if (color.at(2) > color.at(1))
  {
    int new_tab = color.at(2) - color.at(1);
    new_tab = min(new_tab, color.at(1));
    color.at(2) -= new_tab * 2;
    color.at(1) -= new_tab;
    total_table += new_tab;
  }

  if (color.at(1) == color.at(2))
  {
    total_table += (color.at(1) + color.at(2)) / 3;
  }

  cout << total_table << endl;

  return 0;
}