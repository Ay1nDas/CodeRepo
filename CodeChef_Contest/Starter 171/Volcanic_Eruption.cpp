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
    int n, p;
    cin >> n >> p;
    vector<int> site(n), lava, lt_build, rt_build;
    vector<int> min_time;

    int max_height = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> site.at(i);

      max_height = max(max_height, site.at(i));

      if (site.at(i) == 0)
      {
        lava.push_back(i);
        if (i > 0)
          lt_build.push_back(i - 1);
        else
          lt_build.push_back(-1);

        if (i + 1 < n)
          rt_build.push_back(i + 1);
        else
          rt_build.push_back(-1);
      }
    }
  }

  return 0;
}