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
    pair<int, int> haveChoco;
    cin >> haveChoco.first >> haveChoco.second;

    if (haveChoco.first > haveChoco.second)
    {
      int tmp = haveChoco.first;
      haveChoco.first = haveChoco.second;
      haveChoco.second = tmp;
    }

    ll layerSize = 1;

    pair<int, int> choco;

    int i;
    for (i = 1; i < 32; i++, layerSize *= 2)
    {
      if (i % 2 == 1)
      {
        choco.first += layerSize;
      }
      else
      {
        choco.second += layerSize;
      }

      int minChoco = min(choco.first, choco.second);
      int maxChoco = max(choco.first, choco.second);

      if (minChoco > haveChoco.first || maxChoco > haveChoco.second)
      {
        break;
      }
    }

    cout << i - 1 << endl;
  }

  return 0;
}