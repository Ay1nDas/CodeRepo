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
  int a, b;
  cin >> a >> b;

  int min_num = min(a, b);

  if (min_num == 0)
  {
    cout << "0" << endl;
  }
  else
  {
    cout << min_num + 1 << endl;

    for (int i = 0; i <= min_num; i++)
    {
      cout << min_num - i << " " << i << endl;
    }
  }

  return 0;
}