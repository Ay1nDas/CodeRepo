#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;

    int total_cnt = 0;
    for (int i = 0; i < n / 2; i++) {
      if (str[i] != str[n - 1 - i]) {
        total_cnt += str[i] == ch ? 0 : 1;
        total_cnt += str[n - 1 - i] == ch ? 0 : 1;
      }
    }

    cout << total_cnt << endl;
  }

  return 0;
}