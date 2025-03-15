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
    int n = 0;
    string wall;
    cin >> n >> wall;

    // cout << "WALL: " << wall << endl;

    vector<int> R(3), G(3), B(3);

    for (int i = 0; i < n; i += 3)
    {
      if (wall.at(i) == 'R')
        R.at(0)++;
      else if (wall.at(i) == 'G')
        G.at(0)++;
      else if (wall.at(i) == 'B')
        B.at(0)++;

      if (i + 1 < n && wall.at(i + 1) == 'R')
        R.at(1)++;
      else if (i + 1 < n && wall.at(i + 1) == 'G')
        G.at(1)++;
      else if (i + 1 < n && wall.at(i + 1) == 'B')
        B.at(1)++;

      if (i + 2 < n && wall.at(i + 2) == 'R')
        R.at(2)++;
      else if (i + 2 < n && wall.at(i + 2) == 'G')
        G.at(2)++;
      else if (i + 2 < n && wall.at(i + 2) == 'B')
        B.at(2)++;
    }

    int min_cnt = INT_MAX;
    int crt_clr = n - (R.at(0) + G.at(1) + B.at(2));
    min_cnt = min(min_cnt, crt_clr);

    crt_clr = n - (R.at(0) + G.at(2) + B.at(1));
    min_cnt = min(min_cnt, crt_clr);

    crt_clr = n - (R.at(1) + G.at(0) + B.at(2));
    min_cnt = min(min_cnt, crt_clr);

    crt_clr = n - (R.at(2) + G.at(0) + B.at(1));
    min_cnt = min(min_cnt, crt_clr);

    crt_clr = n - (R.at(1) + G.at(2) + B.at(0));
    min_cnt = min(min_cnt, crt_clr);

    crt_clr = n - (R.at(2) + G.at(1) + B.at(0));
    min_cnt = min(min_cnt, crt_clr);

    cout << min_cnt << endl;
  }

  return 0;
}