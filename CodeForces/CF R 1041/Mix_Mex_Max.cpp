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

    unordered_set<int> nums;
    for (int i = 0; i < n; i++)
    {
      int tmp;
      cin >> tmp;
      if (tmp != -1)
        nums.insert(tmp);
    }

    if (nums.size() > 1)
      cout << "NO" << endl;
    else if (nums.size() > 0 && (*nums.begin()) == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}