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
    string str;
    cin >> str;
    bool isInfinite = false;

    for (int i = 0; i < str.length(); i++)
    {
      if (str.at(i) == '*')
      {
        if (i > 0 && (str.at(i - 1) == '>' || str.at(i - 1) == '*'))
        {
          isInfinite = true;
        }
        else if (i + 1 < str.length() && (str.at(i + 1) == '<' || str.at(i + 1) == '*'))
        {
          isInfinite = true;
        }
      }
    }

    int minRight = str.length();
    int maxLeft = -1;

    for (int i = 0; i < str.length(); i++)
    {
      if (str.at(i) == '>')
      {
        minRight = min(minRight, i);
      }
      else if (str.at(i) == '<')
      {
        maxLeft = max(maxLeft, i);
      }
    }

    if (minRight < maxLeft)
    {
      isInfinite = true;
    }

    if (isInfinite)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << max(static_cast<ll>(minRight), static_cast<ll>(str.length() - maxLeft - 1)) << endl;
    }
  }

  return 0;
}