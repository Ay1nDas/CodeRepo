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
  string s;
  cin >> s;

  int streak = 1;
  bool isPreCpl = false;
  char curr = s.at(0);

  for (int i = 1; i < s.length(); i++)
  {
    if (s.at(i) == curr)
      streak++;
    else
    {
      if (streak > 1)
        isPreCpl = true;
      else
        isPreCpl = false;
      streak = 1;
      curr = s.at(i);
    }

    if (streak == 2 && isPreCpl)
    {
      streak--;
      s.at(i) = '_';
    }
    else if (streak > 2)
    {
      streak--;
      s.at(i) = '_';
    }
  }

  string fixedStr;
  for (auto c : s)
  {
    if (c != '_')
      fixedStr += c;
  }

  cout << fixedStr << endl;

  return 0;
}