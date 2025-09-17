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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    bool isPoss = false;
    int l, r;

    for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        int s1 = 0;
        for (int k = 0; k <= i; k++)
          s1 += arr.at(k);

        int s2 = 0;
        for (int k = i + 1; k <= j; k++)
          s2 += arr.at(k);

        int s3 = 0;
        for (int k = j + 1; k < n; k++)
          s3 += arr.at(k);

        // cout << s1 << " " << s2 << " " << s3 << endl;
        s1 %= 3;
        s2 %= 3;
        s3 %= 3;

        if (s1 == s2 && s2 == s3)
        {
          isPoss = true;
          l = i;
          r = j;
          break;
        }
        else if (s1 != s2 && s2 != s3 && s1 != s3)
        {
          isPoss = true;
          l = i;
          r = j;
          break;
        }
      }
      if (isPoss)
        break;
    }

    // cout << "ans: ";
    if (!isPoss)
      cout << 0 << " " << 0 << endl;
    else
      cout << l + 1 << " " << r + 1 << endl;
  }

  return 0;
}