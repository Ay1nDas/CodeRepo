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
  string str;
  string p;
  cin >> str >> p;
  p = ' ' + p;

  vector<int> pi(p.length());

  int bgn = 1;
  for (int i = 2; i < p.length(); i++)
  {
    while (bgn > 1 && p.at(i) != p.at(bgn))
    {
      bgn = pi.at(bgn - 1);
      bgn++;
    }

    if (p.at(i) == p.at(bgn))
    {
      pi.at(i) = bgn;
      bgn++;
    }
  }

  // for (auto i : pi)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;

  int pIdx = 0;
  int cnt = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (p.at(pIdx + 1) == str.at(i))
    {
      pIdx++;
    }
    else
    {
      while (pIdx > 0 && p.at(pIdx + 1) != str.at(i))
      {
        pIdx = pi.at(pIdx);
      }

      if (p.at(pIdx + 1) == str.at(i))
      {
        pIdx++;
      }
    }

    if (pIdx == pi.size() - 1)
    {
      cnt++;
      pIdx = pi.at(pIdx);
    }
  }
  cout << cnt << endl;
  return 0;
}