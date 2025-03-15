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
    int num;
    cin >> num;
    if (num == 1)
    {
      cout << num << endl;
      continue;
    }
    else if (num <= 4)
    {
      cout << 2 << endl;
      continue;
    }

    int changed{4}, opp_used{2};
    while (changed < num)
    {
      changed = (changed + 1) * 2;
      opp_used++;
    }

    cout << opp_used << endl;
  }

  return 0;
}