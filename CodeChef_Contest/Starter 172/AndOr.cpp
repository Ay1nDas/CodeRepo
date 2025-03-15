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
    int n;
    cin >> n;
    vector<int> bi_arr(n);
    for (int i = 0; i < n; i++)
      cin >> bi_arr.at(i);

    int pos0, pos1;

    if (n % 2 == 0)
    {
      pos0 = 1;
      pos1 = 0;
    }
    else
    {
      pos0 = 0;
      pos1 = 1;
    }

    int val = 0, pos = -1;

    for (int i = n - 1; i >= 0; i--)
    {
      if ((n - 1 - i) % 2 == 0 && bi_arr.at(i) != pos0)
      {
        val = bi_arr.at(i);
        pos = i;
        break;
      }
      else if ((n - 1 - i) % 2 == 1 && bi_arr.at(i) != pos1)
      {
        val = bi_arr.at(i);
        pos = i;
        break;
      }
    }

    int q;
    cin >> q;

    while (q--)
    {
      int p, x;
      cin >> p >> x;
      bi_arr.at(p - 1) = x;

      if (p - 1 < pos)
      {
        cout << val << endl;
      }
      else
      {
        pos = -1, val = 0;
        for (int i = n - 1; i >= 0; i--)
        {
          if ((n - 1 - i) % 2 == 0 && bi_arr.at(i) != pos0)
          {
            val = bi_arr.at(i);
            pos = i;
            break;
          }
          else if ((n - 1 - i) % 2 == 1 && bi_arr.at(i) != pos1)
          {
            val = bi_arr.at(i);
            pos = i;
            break;
          }
        }
        cout << val << endl;
      }

      // cout << "ANSWER: " << val << endl;
    }
  }

  return 0;
}