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
    int n;
    cin >> n;

    unordered_map<int, int> freq;
    bool isPoss = false;

    for (int i = 0; i < n; i++)
    {
      int num = 0;
      cin >> num;

      freq[num]++;
      if (freq[num] > 1)
        isPoss = true;
    }

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}