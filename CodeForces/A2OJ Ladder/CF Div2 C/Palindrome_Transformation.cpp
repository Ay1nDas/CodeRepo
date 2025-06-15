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
  int n, p;
  cin >> n >> p;
  string str;
  cin >> str;
  p--;
  int change_cnt = 0;

  vector<int> val(n);
  for (int i = 0; i < n / 2; i++)
  {
    val.at(i) = abs(str.at(i) - str.at(n - 1 - i));
    if (val.at(i) > 13)
      val.at(i) = 26 - val.at(i);
    val.at(n - 1 - i) = val.at(i);

    if (val.at(i))
      change_cnt++;
  }

  int rht_val = 0;
  int cpy_cnt = change_cnt;
  int p_cpy = p;

  vector<int> val_cpy = val;
  while (cpy_cnt > 0)
  {
    if (p == n)
      p = 0;

    if (val_cpy.at(p))
      cpy_cnt--;

    rht_val += val_cpy.at(p);
    val_cpy.at(p) = val_cpy.at(n - 1 - p) = 0;
    p++;
    rht_val++;
  }
  rht_val--;

  int lft_val = 0;
  cpy_cnt = change_cnt;
  val_cpy = val;
  p = p_cpy;

  while (cpy_cnt > 0)
  {
    if (p < 0)
      p = n - 1;

    if (val_cpy.at(p))
      cpy_cnt--;

    lft_val += val_cpy.at(p);
    val_cpy.at(p) = val_cpy.at(n - 1 - p) = 0;
    p--;
    lft_val++;
  }
  lft_val--;

  cout << min(lft_val, rht_val) << endl;
  cout << rht_val << endl;
  cout << lft_val << endl;

  return 0;
}