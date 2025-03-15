#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double separateSquares(vector<vector<int>> &squares)
  {
    unordered_map<int, int> area_dist;
    double total_area = 0;
    int max_y = 0;

    for (auto vec : squares)
    {
      int lmt = vec.at(1) + vec.at(2);
      if (lmt > max_y)
        max_y = lmt;

      for (int j = vec.at(1); j < lmt; j++)
      {
        area_dist[j] += vec.at(2);
        total_area += vec.at(2);
      }
    }
    double below = 0;
    for (int y = 0; y < max_y; y++)
    { // Change to below
      below += area_dist[y];

      if (below > total_area - below && area_dist[y])
      {
        below -= area_dist[y];
        cout << below << " " << total_area << endl;
        return y + (total_area - below * 2) / 2 / area_dist[y];
      }
      else if (below * 2 == total_area)
      {
        return y + 1;
      }
    }
    return 0;
  }
};

int main()
{
  return 0;
}