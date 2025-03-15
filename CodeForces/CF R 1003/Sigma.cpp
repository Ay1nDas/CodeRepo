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

    // vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<ll>> score_sum(n, vector<ll>(2));

    for (int i = 0; i < n; i++)
    {
      vector<int> arr(m);
      cin >> arr.at(0);
      ll score = arr.at(0);
      ll sum = arr.at(0);

      for (int j = 1; j < m; j++)
      {
        cin >> arr.at(j);
        sum += arr.at(j);

        arr.at(j) += arr.at(j - 1);
        score += arr.at(j);
      }

      score_sum.at(i).at(0) = sum;
      score_sum.at(i).at(1) = score;
    }

    sort(score_sum.rbegin(), score_sum.rend(), [](const vector<long long> &a, const vector<long long> &b)
         { return a[0] < b[0]; });

    // for (auto vec : score_sum)
    // {
    //   cout << "sum: " << vec.at(0) << endl
    //        << "Score: " << vec.at(1) << endl
    //        << endl;
    // }

    unsigned long long end_score = 0;

    for (int i = 0; i < n; i++)
    {
      end_score += score_sum.at(i).at(1);
      end_score += score_sum.at(i).at(0) * (n - i - 1) * m;
    }

    cout << end_score << endl;
  }

  return 0;
}