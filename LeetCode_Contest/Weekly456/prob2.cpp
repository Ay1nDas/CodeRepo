#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> longestCommonPrefix(vector<string> &words)
  {
    vector<vector<int>> prefix(words.size() - 1, vector<int>(2));
    vector<int> answer(words.size());
    int ans_idx = 0;

    for (int i = 0; i + 1 < words.size(); i++)
    {
      int cnt = 0;
      for (int j = 0; j < words.at(i).length() && j < words.at(i + 1).length(); j++)
      {
        if (words.at(i).at(j) != words.at(i + 1).at(j))
          break;
        cnt++;
      }
      prefix.at(i).at(0) = cnt;
      prefix.at(i).at(1) = i;
    }

    sort(prefix.begin(), prefix.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] > b[0]; });

    // for (auto pre : prefix)
    // {
    //   cout << pre.at(0) << " " << pre.at(1) << endl;
    // }

    for (int i = 0; i < words.size(); i++)
    {
      int max_prefix = 0;

      if (i > 0 && i + 1 < words.size())
      {
        // cout << words.at(i - 1) << " " << words.at(i + 1) << endl;
        for (int j = 0; j < words.at(i - 1).length() && j < words.at(i + 1).length(); j++)
        {
          if (words.at(i - 1).at(j) != words.at(i + 1).at(j))
            break;
          max_prefix++;
        }
      }

      for (int j = 0; j < prefix.size(); j++)
      {
        if (prefix.at(j).at(1) == i - 1 || prefix.at(j).at(1) == i)
          continue;

        if (prefix.at(j).at(0) > max_prefix)
          max_prefix = prefix.at(j).at(0);

        break;
      }

      answer.at(ans_idx++) = max_prefix;
    }

    return answer;
  }
};

int main()
{
  return 0;
}
