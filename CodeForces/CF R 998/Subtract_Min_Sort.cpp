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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      cin >> nums.at(i);
    }

    bool isPossible = true;
    for (int i = 0; i + 1 < n; i++)
    {
      if (nums.at(i) <= nums.at(i + 1))
      {
        nums.at(i + 1) -= nums.at(i);
        nums.at(i) = 0;
      }
      else
      {
        isPossible = false;
        break;
      }
    }

    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}