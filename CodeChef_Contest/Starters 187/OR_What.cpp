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
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> opps;
    vector<int> poss_bits;

    for (int i = 1; i <= n; i++)
    {
      if (i | x == x)
      {
        poss_bits.push_back(i);
      }
    }

    for (int i = 0; i < poss_bits.size(); i++)
    {
      if (!poss_bits.at(i))
      {
        continue;
      }
      for (int j = i; j < poss_bits.size(); j++)
      {
        if (!poss_bits.at(j))
        {
          continue;
        }

        int bit1 = poss_bits.at(i);
        int bit2 = poss_bits.at(j);

        if ((bit1 | bit2) == x)
        {
          opps[bit1] = bit2;
          opps[bit2] = bit1;
          poss_bits.at(i) = 0;
          poss_bits.at(j) = 0;
          break;
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {
      cout << (opps[i] ? opps[i] : i) << " ";
    }
    cout << endl;
  }
  return 0;
}