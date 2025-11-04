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

  int k;
  cin >> k;
  unordered_map<string, int> dict;

  for (int i = 0; i < k; i++)
  {
    string word;
    cin >> word;
    dict[word]++;
  }

  vector<ll> dp(str.length());
  dp.at(0) = 1;
  for (int i = 1; i < str.length(); i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (dp.at(j - 1) > 0 && dict.find(str.substr(j, i - j + 1)) != dict.end())
      {
        dp.at(i) = (dp.at(i) + dp.at(j - 1)) % mod;
      }
    }
  }
  cout << dp.back() << endl;
  return 0;
}