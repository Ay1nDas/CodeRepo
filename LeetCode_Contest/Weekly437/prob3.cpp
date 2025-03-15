#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool maxSubstringLength(string s, int k)
  {

    if (!k)
      return true;

    vector<int> start_ch(26, -1);
    vector<int> end_ch(26, -1);

    for (int i = 0; i < s.length(); i++)
    {
      if (start_ch.at(s.at(i) - 'a') == -1)
      {
        start_ch.at(s.at(i) - 'a') = i;
        end_ch.at(s.at(i) - 'a') = i;
      }
      else
      {
        end_ch.at(s.at(i) - 'a') = i;
      }
    }

    // for (auto i : start_ch)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : end_ch)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    std::vector<int> nums;
    for (int i = 0; i <= 25; ++i)
    {
      nums.push_back(i);
    }

    std::vector<bool> select(nums.size(), false);
    std::fill(select.begin(), select.begin() + k, true);

    vector<int> comb;
    do
    {
      comb.clear();
      cout << "combinations: ";
      for (size_t i = 0; i < nums.size(); ++i)
      {
        if (select[i])
        {
          cout << i << " ";
          comb.push_back(i);
        }
      }
      cout << endl;

      vector<int> comb_start;
      vector<int> comb_end;
      bool toCont = false;

      for (auto n : comb)
      {

        if (start_ch.at(n) == -1)
        {
          toCont = true;
          break;
        }

        for (int j = 0; j < comb_end.size(); j++)
        {
          if (start_ch.at(n) <= comb_end.at(j))
          {
            toCont = true;
            break;
          }
        }

        if (toCont)
          break;

        comb_start.push_back(start_ch.at(n));
        comb_end.push_back(end_ch.at(n));
      }

      if (!toCont)
        return true;

    } while (std::prev_permutation(select.begin(), select.end()));
    return false;
  }
};

int main()
{
  return 0;
}