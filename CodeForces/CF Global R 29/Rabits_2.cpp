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

    if (zeros.size() && zeros.at(0) == 0)
      looking.at(0) = -1;
    else if (zeros.size())
      looking.at(0) = 2;

    for (int i = 0; i < zeros.size(); i++)
    {
      int before, after;
      if (i == 0)
        before = 0;
      else
        before = zeros.at(i - 1);

      if (i == zeros.size() - 1)
        after = n;
      else
        after = zeros.at(i + 1);

      if (zeros.at(i) - before > 2 && after - zeros.at(i) > 2)
        isPoss = false;
    }

    for (int i = 1; i < zeros.size(); i++)
    {
      // cout << i << " : " << zeros.at(i) << zeros.at(i - 1) << " ";

      if (zeros.at(i) - zeros.at(i - 1) == 1)
      {
        looking.at(i) = -1;
      }
      else if (zeros.at(i) - zeros.at(i - 1) == 2)
      {
        looking.at(i) = -looking.at(i - 1);
      }
      else
      {
        if (looking.at(i - 1) == 2)
        {
          isPoss = false;
          break;
        }

        looking.at(i) = 2;
      }
    }
    // cout << endl;

    if (zeros.size() && looking.back() == 2 && zeros.back() != n - 1)
      isPoss = false;

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}