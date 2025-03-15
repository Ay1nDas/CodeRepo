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

    vector<int> ratings;
    vector<int> problems(m);

    int kevin_rating;
    cin >> kevin_rating;

    for (int i = 1; i < n; i++)
    {
      int r;
      cin >> r;

      if (r >= kevin_rating)
        ratings.push_back(r);
    }

    sort(ratings.rbegin(), ratings.rend());

    for (int i = 0; i < m; i++)
      cin >> problems.at(i);
    sort(problems.begin(), problems.end());

    vector<int> solvers(m);
    int index_solver = ratings.size() - 1;

    for (int i = 0; i < m; i++)
    {
      while (index_solver >= 0 && ratings.at(index_solver) < problems.at(i))
        index_solver--;

      solvers.at(i) = index_solver + 1;
    }

    // for (auto r : ratings)
    //   cout << r << " ";
    // cout << endl;

    // for (auto p : problems)
    //   cout << p << " ";
    // cout << endl;

    // for (auto s : solvers)
    //   cout << s << " ";
    // cout << endl;

    // Refines the data till here //

    for (int k = 1; k <= m; k++)
    {
      int total_rating{0};
      int used_front{0}, used_back{m - 1};

      for (int j = 0; j < m / k; j++)
      {
        int max_solved{0};
        bool kevin_solved_all = true;

        if (problems.at(used_front + k - 1) <= kevin_rating)
        {
          total_rating++;
          used_front += k;
          continue;
        }

        for (int i = 0; i < k; i++)
        {
          if (problems.at(used_front) <= kevin_rating)
            used_front++;
          else
          {
            kevin_solved_all = false;
            max_solved = max(max_solved, solvers.at(used_back--));
          }
        }

        if (kevin_solved_all)
          total_rating++;
        else
          total_rating += max_solved + 1;
      }
      cout << total_rating << " ";
    }
    cout << endl;
  }

  return 0;
}