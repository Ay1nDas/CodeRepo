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

  // fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, s;
    cin >> n >> s;

    int cnt[3] = {0};
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      sum += num;
      cnt[num]++;
    }

    if (s > sum + 1 || s == sum)
    {
      cout << -1 << endl;
    }
    else
    {
      while (cnt[0]--)
      {
        cout << 0 << " ";
      }
      while (cnt[2]--)
      {
        cout << 2 << " ";
      }
      while (cnt[1]--)
      {
        cout << 1 << " ";
      }
      cout << endl;
    }
  }

  return 0;
}