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
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    for (int i = 0; i < n; i++)
      cin >> b.at(i);

    int chosen_i = -1, chosen_j = -1;
    int min_diff = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int curr_val = abs(a.at(i) - b.at(i)) + abs(a.at(j) - b.at(j));
        vector<int> optimum(4);
        optimum.at(0) = a.at(i);
        optimum.at(1) = b.at(i);
        optimum.at(2) = a.at(j);
        optimum.at(3) = b.at(j);

        sort(optimum.begin(), optimum.end());
        int opt_val = optimum.at(3) - optimum.at(0) + optimum.at(2) - optimum.at(1);

        if (opt_val - curr_val < min_diff)
        {
          // cout << "ij: " << i << " " << j << endl;
          chosen_i = i;
          chosen_j = j;
          min_diff = opt_val - curr_val;
        }
        if (min_diff == 0)
          break;
      }
      if (min_diff == 0)
        break;
    }
    vector<int> optimum(4);
    optimum.at(0) = a.at(chosen_i);
    optimum.at(1) = b.at(chosen_i);
    optimum.at(2) = a.at(chosen_j);
    optimum.at(3) = b.at(chosen_j);

    sort(optimum.begin(), optimum.end());

    a.at(chosen_i) = optimum.at(0);
    b.at(chosen_i) = optimum.at(3);
    a.at(chosen_j) = optimum.at(1);
    b.at(chosen_j) = optimum.at(2);

    ll max_val = 0;
    for (int i = 0; i < n; i++)
      max_val += abs(a.at(i) - b.at(i));

    cout << max_val << endl;
  }

  return 0;
}