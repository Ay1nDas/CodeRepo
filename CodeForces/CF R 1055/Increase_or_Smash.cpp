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
    int diff_int = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;

      if (freq[num] == 0)
        diff_int++;
      freq[num]++;
    }

    cout << diff_int * 2 - 1 << endl;
  }

  return 0;
}