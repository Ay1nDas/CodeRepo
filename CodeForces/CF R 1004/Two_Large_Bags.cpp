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

    // vector<int> arr(n);
    unordered_map<int, int> arr;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      arr[num]++;
    }

    bool isPossible = true;

    for (int i = 1; i + 1 <= n; i++)
    {
      if (arr[i] > 2)
      {
        arr[i + 1] += arr[i] - 2;
      }
      else if (arr[i] == 1)
      {
        isPossible = false;
      }
    }
    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}