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
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    sort(arr.begin(), arr.end());

    int strt = 0, end = n - 1;
    int cnt1 = 0;
    while ((arr.at(strt) + arr.at(end)) % 2)
    {
      strt++;
      cnt1++;
    }

    strt = 0;
    end = n - 1;
    int cnt2 = 0;
    while ((arr.at(strt) + arr.at(end)) % 2)
    {
      end--;
      cnt2++;
    }

    cout << min(cnt1, cnt2) << endl;
  }

  return 0;
}