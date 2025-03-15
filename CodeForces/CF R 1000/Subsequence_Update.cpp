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
    int n, l, r;
    cin >> n >> l >> r;
    l--;

    vector<int> seq_before;
    vector<int> sub_seq;
    vector<int> seq_after;

    for (int i = 0; i < l; i++)
    {
      int num;
      cin >> num;
      seq_before.push_back(num);
    }

    for (int i = l; i < r; i++)
    {
      int num;
      cin >> num;
      sub_seq.push_back(num);
    }
    for (int i = r; i < n; i++)
    {
      int num;
      cin >> num;
      seq_after.push_back(num);
    }

    sort(seq_before.begin(), seq_before.end());
    sort(sub_seq.rbegin(), sub_seq.rend());
    sort(seq_after.begin(), seq_after.end());

    ll before_sum = 0;

    for (int i = 0; i < sub_seq.size(); i++)
    {
      if (i < seq_before.size() && seq_before.at(i) < sub_seq.at(i))
        before_sum += seq_before.at(i);
      else
        before_sum += sub_seq.at(i);
    }

    ll after_sum = 0;

    for (int i = 0; i < sub_seq.size(); i++)
    {
      if (i < seq_after.size() && seq_after.at(i) < sub_seq.at(i))
        after_sum += seq_after.at(i);
      else
        after_sum += sub_seq.at(i);
    }

    cout << min(before_sum, after_sum) << endl;
  }

  return 0;
}