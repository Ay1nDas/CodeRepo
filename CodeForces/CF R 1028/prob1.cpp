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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == c)
    {
      if (b == d)
      {
        if (a >= b)
          cout << "Gellyfish" << endl;
        else
          cout << "Flower" << endl;
      }
      else if (b > d)
      {
        if (a >= d)
        {
          cout << "Gellyfish" << endl;
        }
        else
          cout << "Flower" << endl;
      }
      else
      {
        if (a >= b)
          cout << "Gellyfish" << endl;
        else
          cout << "Flower" << endl;
      }
    }
    else if (a > c)
    {
      if (b == d)
      {
        if (c >= b)
          cout << "Gellyfish" << endl;
        else
          cout << "Flower" << endl;
      }
      else if (b > d)
      {
        if (c >= d)
        {
          cout << "Gellyfish" << endl;
        }
        else
          cout << "Flower" << endl;
      }
      else
      {
        if (c >= b)
          cout << "Gellyfish" << endl;
        else
          cout << "Flower" << endl;
      }
    }
    else if (a < c)
    {
    }
  }

  return 0;
}