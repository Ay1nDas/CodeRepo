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
  string num;
  cin >> num;
  int a, b;
  cin >> a >> b;
  bool isPossible = false;
  int break_pt = -1;

  ll div = 0;

  for (int i = 0; i + 1 < num.length(); i++)
  {
    div = div * 10 + (num.at(i) - '0');
    div %= a;
    if (num.at(i + 1) == '0')
      continue;

    if (div == 0)
    {
      ll div_2 = 0;
      for (int j = i + 1; j < num.length(); j++)
      {
        div_2 = div_2 * 10 + (num.at(j) - '0');
        div_2 %= b;
      }

      if (div_2 == 0)
      {
        isPossible = true;
        break_pt = i + 1;
        break;
      }
    }
  }

  if (isPossible)
  {
    cout << "YES" << endl;
    for (int i = 0; i < num.length(); i++)
    {
      if (i == break_pt)
        cout << endl;

      cout << num.at(i);
    }
    cout << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}