#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
  {
    vector<string> valid_cpn;

    vector<string> all_bl(4);

    all_bl.at(0) = "electronics";
    all_bl.at(1) = "grocery";
    all_bl.at(2) = "pharmacy";
    all_bl.at(3) = "restaurant";

    for (auto bl : all_bl)
    {
      vector<string> curr_cpn;
      for (int i = 0; i < businessLine.size(); i++)
      {
        if (businessLine.at(i) == bl && isActive.at(i))
        {
          // cout << code.at(i) << endl;
          bool isPush = true;
          for (auto c : code.at(i))
          {
            if ((c < 'A' || c > 'Z') && c != '_' && (c < 'a' || c > 'Z') && (c < '0' || c > '9'))
            {
              // cout << c << endl;
              isPush = false;
              break;
            }
          }

          if (isPush && code.size())
          {
            curr_cpn.push_back(code.at(i));
          }
        }
      }

      sort(curr_cpn.begin(), curr_cpn.end());

      for (auto cpn : curr_cpn)
      {
        cout << cpn << endl;
        valid_cpn.push_back(cpn);
      }
    }

    return valid_cpn;
  }
};

int main()
{
  return 0;
}