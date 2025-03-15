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

    vector<ll> pos(1);
    vector<ll> neg(1);

    bool isPositive = true;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;

      if (isPositive && num >= 0)
      {
        pos.at(pos.size() - 1) += num;
      }
      else if (isPositive && num < 0)
      {
        neg.push_back(abs(num));
        isPositive = !isPositive;
      }
      else if (!isPositive && num < 0)
      {
        neg.at(neg.size() - 1) -= num;
      }
      else if (!isPositive && num >= 0)
      {
        pos.push_back(num);
        isPositive = !isPositive;
      }
    }

    // cout << "pos: ";
    // for (auto i : pos)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;
    // cout << "neg: ";
    // for (auto i : neg)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    for (int i = neg.size() - 2; i >= 0; i--)
    {
      neg.at(i) += neg.at(i + 1);
    }

    // cout << "pre: ";
    // for (auto i : neg)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    ll pos_prefix = 0;
    ll max_val = 0;

    for (int i = 0; i < pos.size(); i++)
    {
      max_val = max(neg.at(i) + pos_prefix, max_val);
      pos_prefix += pos.at(i);
    }

    if (pos.size() < neg.size())
    {
      max_val = max(neg.at(pos.size()) + pos_prefix, max_val);
    }
    else
    {
      max_val = max(pos_prefix, max_val);
    }

    cout << max_val << endl;
  }

  return 0;
}