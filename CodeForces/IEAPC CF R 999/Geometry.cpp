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

    // vector<int> sides(n);
    // set<int> unique_sides;
    vector<int> paired_sides;
    map<int, int> sides;

    for (int i = 0; i < n; i++)
    {
      int s;
      cin >> s;

      sides[s]++;
      if (sides[s] == 2)
      {
        sides.erase(s);
        paired_sides.push_back(s);
      }
    }
    // sort(paired_sides.begin(), paired_sides.end());

    if (paired_sides.size() > 1)
    {
      cout << paired_sides.at(0) << " " << paired_sides.at(0) << " " << paired_sides.at(1) << " " << paired_sides.at(1) << endl;
    }
    else if (paired_sides.size() > 0)
    {
      int threshold = 2 * paired_sides.at(0);
      bool isPossible = false;

      auto it = sides.begin();
      int pre_num = it->first;
      it++;

      for (; it != sides.end(); it++)
      {
        int num = it->first;
        if (abs(num - pre_num) < threshold)
        {
          cout << paired_sides.at(0) << " " << paired_sides.at(0) << " " << pre_num << " " << it->first << endl;
          isPossible = true;
          break;
        }
        pre_num = it->first;
      }
      if (!isPossible)
      {
        cout << -1 << endl;
      }
    }
    else
    {
      cout << -1 << endl;
    }
  }

  return 0;
}