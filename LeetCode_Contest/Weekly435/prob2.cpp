#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDistance(string s, int k)
  {
    int N = 0, S, E = 0, W = 0;
    int max_mh = 0, k_lft = k;

    for (int i = 0; i < s.length(); i++)
    {
      if (s.at(i) == 'N')
        N++;
      else if (s.at(i) == 'S')
        S++;
      else if (s.at(i) == 'E')
        E++;
      else if (s.at(i) == 'W')
        W++;

      int current_mh = 0;
      int min_NS = min(N, S);
      int max_NS = max(N, S);

      if (min_NS > k)
      {
        current_mh += max_NS - min_NS + 2 * k;
      }
      else
      {
        current_mh += max_NS + min_NS;
        k_lft -= min_NS;
      }

      int min_EW = min(E, W);
      int max_EW = max(E, W);

      if (min_EW > k_lft)
      {
        current_mh += max_EW - min_EW + 2 * k_lft;
      }
      else
      {
        current_mh += max_EW + min_EW;
      }

      if (current_mh > max_mh)
        max_mh = current_mh;
    }
    return max_mh;
  }
};

int main()
{
  return 0;
}