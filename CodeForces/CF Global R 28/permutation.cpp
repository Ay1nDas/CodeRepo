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
    int n, k;
    cin >> n >> k;

    int front_num{1};
    int end_num{n};

    for (int i = 1; i <= n; i++)
    {
      if (i % k == 0)
        cout << front_num++ << " ";
      else
        cout << end_num-- << " ";
    }
    cout << endl;
  }

  return 0;
}