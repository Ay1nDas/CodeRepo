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

    vector<ll> odds, evens;
    for (int i = 0; i < n; i++)
    {
      ll num = 0;
      cin >> num;

      if (num % 2 == 0)
      {
        evens.push_back(num);
      }
      else
      {
        odds.push_back(num);
      }
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    vector<ll> outVal(n);

    if (odds.size() > 0 && evens.size() > 0)
    {
      int i = 0;
      outVal.at(i++) = odds.back();

      int evenIt = evens.size() - 1;
      for (i = 1; i < n && evenIt >= 0; i++)
      {
        outVal.at(i) = outVal.at(i - 1) + evens.at(evenIt--);
      }

      ll add = -evens.at(0);

      for (i; i < n; i++)
      {
        outVal.at(i) = outVal.at(i - 1) + add;
        add = -add;
      }

      if (odds.size() % 2 == 0)
      {
        outVal.back() = 0;
      }
    }
    else if (evens.size() == 0)
    {
      for (int i = 0; i < n; i += 2)
      {
        outVal.at(i) = odds.back();
      }
    }

    // cout << "ANS: ";

    for (auto &i : outVal)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}

/*

5
1 2 3

Odds: 1
Evens: 2

Bags: 0

Ans: 3 5 0





*/