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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> spots;
    bool notWeak = true;
    int count{0};

    string arr;
    cin >> arr;

    for (int i = 0; i < n; i++)
    {
      if (notWeak == arr.at(i) - '0')
      {
        count++;
      }
      else
      {
        notWeak = !notWeak;
        spots.push_back(count);
        count = 1;
      }
    }
    spots.push_back(count);

    // for (auto i : spots)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    int operations{0}, leftOver{0};
    for (int i = 1; i < spots.size(); i += 2)
    {

      spots.at(i) += leftOver;
      leftOver = 0;

      while (spots.at(i) >= m)
      {
        spots.at(i) -= m + k - 1;
        operations++;
      }

      if (i + 1 < spots.size() && spots.at(i) + spots.at(i + 1) < 0)
        leftOver = spots.at(i) + spots.at(i + 1);
    }
    cout << operations << endl;
  }

  return 0;
}