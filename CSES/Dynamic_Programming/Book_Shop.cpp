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
  int n, x;
  cin >> n >> x;

  vector<int> pages(n + 1);
  vector<int> prices(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> prices.at(i);
  for (int i = 1; i <= n; i++)
    cin >> pages.at(i);

  vector<vector<int>> priceGrid(n + 1, vector<int>(x + 1));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= x; j++)
    {
      int notTaken = priceGrid.at(i - 1).at(j);
      int taken = (prices.at(i) <= j ? priceGrid.at(i - 1).at(j - prices.at(i)) + pages.at(i) : 0);

      priceGrid.at(i).at(j) = max(notTaken, taken);
    }
  }

  cout << priceGrid.at(n).at(x) << endl;
  return 0;
}