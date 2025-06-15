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
    vector<int> obs(n);

    for (int i = 0; i < n; i++)
      cin >> obs.at(i);

    vector<int> min_obs(n);
    vector<int> max_obs(n);

    for (int i = 0; i < n; i++)
    {
      cin >> min_obs.at(i);
      cin >> max_obs.at(i);
    }

    for (int i = n - 2; i >= 0; i--)
    {
      // if (abs(min_obs.at(i) - min_obs.at(i + 1)) > 1)
      // {
      if (obs.at(i + 1) == 0 && min_obs.at(i) < min_obs.at(i + 1))
        min_obs.at(i) = min_obs.at(i + 1);
      else if (min_obs.at(i) < min_obs.at(i + 1))
        min_obs.at(i) = min_obs.at(i + 1) - 1;
      else if (min_obs.at(i) > min_obs.at(i + 1))
        min_obs.at(i + 1) = min_obs.at(i) - 1;
      // }
    }

    // for (int i = 0; i < n; i++)
    //   cout << min_obs.at(i) << " ";
    // cout << endl;

    for (int i = n - 2; i >= 0; i--)
    {
      // if (abs(min_obs.at(i) - min_obs.at(i + 1)) > 1)
      // {
      if (obs.at(i + 1) == 1 && max_obs.at(i) >= max_obs.at(i + 1))
        max_obs.at(i) = max_obs.at(i + 1) - 1;
      else if (max_obs.at(i) < max_obs.at(i + 1))
        max_obs.at(i + 1) = max_obs.at(i) + 1;
      else if (max_obs.at(i) > max_obs.at(i + 1))
        max_obs.at(i) = max_obs.at(i + 1) + 1;

      // }
    }

    // for (int i = 0; i < n; i++)
    //   cout << min_obs.at(i) << " ";
    // cout << endl;

    // for (int i = 0; i < n; i++)
    //   cout << max_obs.at(i) << " ";
    // cout << endl;

    int curr_pos = 0;
    bool isPossible = true;
    // cout << "Pos: ";
    for (int i = 0; i < n; i++)
    {
      if (obs.at(i) != -1)
      {
        curr_pos += obs.at(i);
      }
      else if (curr_pos < min_obs.at(i))
      {
        obs.at(i) = 1;
        curr_pos++;
      }
      else
      {
        obs.at(i) = 0;
      }

      // cout << curr_pos << " ";
      if (curr_pos < min_obs.at(i) || curr_pos > max_obs.at(i))
      {
        isPossible = false;
        break;
      }
    }
    // cout << endl;

    // cout << "ANSWER: ";
    if (isPossible)
    {
      for (int i = 0; i < n; i++)
        cout << obs.at(i) << " ";
      cout << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }

  return 0;
}