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
  string blocks;
  cin >> blocks;

  int w = 0, b = 0;
  for (auto c : blocks)
  {
    if (c == 'W')
      w++;
    else
      b++;
  }
  char ch;
  if (w % 2 == 1 && b % 2 == 1)
  {
    cout << -1 << endl;
    return 0;
  }
  else if (w % 2 == 0)
  {
    ch = 'W';
  }
  else
  {
    ch = 'B';
  }

  vector<int> opps;

  for (int i = 0; i + 1 < n; i++)
  {
    if (blocks.at(i) == ch)
    {
      opps.push_back(i + 1);

      if (blocks.at(i + 1) == 'W')
        blocks.at(i + 1) = 'B';
      else
        blocks.at(i + 1) = 'W';
    }
  }

  cout << opps.size() << endl;
  for (auto i : opps)
    cout << i << " ";
  cout << endl;

  return 0;
}