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
  cin >> str;
  str = ' ' + str;
  vector<int> pi(str.length());
  int stridx = 1;
  for (int i = 2; i < str.length(); i++)
  {
    // cout << str.at(i) << str.at(stridx) << endl;
    while (stridx > 1 && str.at(i) != str.at(stridx))
    {
      // cout << stridx << endl;
      stridx = pi.at(stridx - 1);
      stridx++;
    }

    if (str.at(stridx) == str.at(i))
    {
      pi.at(i) = stridx++;
    }
  }

  // for (auto i : pi)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;

  stack<int> vals;

  int cnt = pi.back();
  while (cnt != 0)
  {
    vals.push(cnt);
    cnt = pi.at(cnt);
  }

  while (vals.size())
  {
    cout << vals.top() << " ";
    vals.pop();
  }
  cout << endl;

  return 0;
}