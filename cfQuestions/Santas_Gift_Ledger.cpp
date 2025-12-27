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
  int n, k;
  cin >> n >> k;

  unordered_map<string, int> freq;
  bool isPoss = true;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;

    freq[str]++;

    if (freq[str] > k)
    {
      isPoss = false;
    }
  }

  std::cout << (isPoss ? "YES" : "NO") << std::endl;

  return 0;
}