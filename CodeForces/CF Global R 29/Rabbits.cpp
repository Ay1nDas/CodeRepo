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
    string pots;
    cin >> n >> pots;

    vector<int> zeros;
    for (int i = 0; i < n; i++)
    {
      if (pots.at(i) == '0')
        zeros.push_back(i);
    }

    vector<int> looking(zeros.size(), 0);
    bool isPoss = true;

    for (int i = 0; i < zeros.size(); i++)
    {
      if (looking.at(i) != 0)
        continue;

      if (zeros.at(i) == 0)
      {
        looking.at(i) = -1;
      }
      else if (zeros.at(i) == n - 1)
      {
        looking.at(i) = 1;
      }
      else if (i + 1 < zeros.size() && zeros.at(i + 1) - zeros.at(i) == 1)
      {
        looking.at(i) = 2;
      }
      else if (i - 1 >= 0 && zeros.at(i) - zeros.at(i - 1) == 1)
      {
        looking.at(i) = -1;
      }
      else if (i + 1 < zeros.size() && zeros.at(i + 1) - zeros.at(i) == 2)
      {
        if (i - 1 > 0 && zeros.at(i) - zeros.at(i - 1) == 2 && looking.at(i - 1) != -2)
        {
          looking.at(i) = 1;
          looking.at(i + 1) = -1;
        }
        else
        {
          looking.at(i) = 2;
          looking.at(i + 1) = -2;
        }
      }
      else if (i - 1 >= 0 && zeros.at(i) - zeros.at(i - 1) == 2 && looking.at(i - 1) != -2)
      {
        looking.at(i) = -2;
        looking.at(i - 1) = 2;
      }
      else
      {
        isPoss = false;
        break;
      }
    }

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}