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
    int n, m;
    cin >> n >> m;
    vector<int> room(m);
    for (int i = 0; i < m; i++)
      cin >> room.at(i);

    sort(room.begin(), room.end());

    int bgn = 0, end = m - 1;
    while (n > 0)
    {
      cout << room.at(bgn) << " " << room.at(end) << " " << room.at(bgn) << " " << room.at(end) << " " << room.at(bgn) << " " << room.at(end) << endl;
      if (n - 1 > 0)
        cout << room.at(end) << " " << room.at(bgn) << " " << room.at(end) << " " << room.at(bgn) << " " << room.at(end) << " " << room.at(bgn) << endl;
      bgn++;
      end--;
      n -= 2;
    }
  }

  return 0;
}