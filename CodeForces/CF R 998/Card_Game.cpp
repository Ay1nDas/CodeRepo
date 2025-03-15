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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> deck(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> deck.at(i).at(j);
      }
      sort(deck.at(i).begin(), deck.at(i).end());

      // for (int i : deck.at(i))
      // {
      //   cout << i << " ";
      // }
      // cout << endl;
    }

    bool isPossible = true;
    vector<int> reqd_permutation(n);

    for (int i = 0; i < n; i++)
    {
      if (deck.at(i).at(0) < n)
      {
        reqd_permutation.at(deck.at(i).at(0)) = i + 1;
      }
      else
      {
        isPossible = false;
        // cout << "HERE1" << endl;
        break;
      }

      for (int j = 1; j < m; j++)
      {
        if (deck.at(i).at(j) - deck.at(i).at(j - 1) != n)
        {
          isPossible = false;
          // cout << "HERE2" << endl;
          break;
        }
      }
      if (!isPossible)
      {
        break;
      }
    }

    if (isPossible)
    {
      for (auto i : reqd_permutation)
      {
        cout << i << " ";
      }
      cout << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }

  return 0;
}