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
    string a, b, c;
    cin >> a >> b >> c;

    int a_index{0}, b_index{0};
    int c_index{0};

    for (int i = 0; i < c.size() && a_index < a.size() && b_index < b.size(); i++)
    {
      if (c.at(i) == a.at(a_index))
        a_index++;
      else if (c.at(i) == b.at(b_index))
        b_index++;
      else if ()
    }
  }

  return 0;
}