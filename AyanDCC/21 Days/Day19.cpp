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
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n + 1);

    for (int i = 2; i <= n; i++)
    {
      if (numbers.at(i) > 0)
        continue;

      for (int j = i; j <= n; j += i)
        numbers.at(j)++;
    }

    int count{0};
    for (int num : numbers)
    {
      if (num == k)
        count++;
    }

    cout << count << endl;
  }

  return 0;
}