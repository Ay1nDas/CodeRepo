#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
  {
    vector<int> users(numberOfUsers);
    vector<int> on_time(numberOfUsers);

    std::sort(events.begin(), events.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
              { return a[0] > b[0]; });

    std::stable_sort(events.begin(), events.end(), [](const std::vector<std::string> &a, const std::vector<std::string> &b)
                     {
                       return std::stoi(a[1]) < std::stoi(b[1]); // Compare the second element as integers
                     });

    for (auto eve : events)
    {
      for (auto str : eve)
      {
        cout << str << " ";
      }
      cout << endl;
      if (eve.at(0) == "MESSAGE")
      {
        int timestamp = stoi(eve.at(1));

        if (eve.at(2) == "ALL")
        {
          for (int i = 0; i < numberOfUsers; i++)
            users.at(i)++;
        }

        else if (eve.at(2) == "HERE")
        {

          for (int i = 0; i < numberOfUsers; i++)
            if (on_time.at(i) <= timestamp)
              users.at(i)++;
        }

        else
        {
          int id = 0; // This 0 might cause a problem.
          for (int i = 2; i < eve.at(2).size(); i++)
          {
            char c = eve.at(2).at(i);
            if (c >= '0' && c <= '9')
            {
              id *= 10;
              id += c - '0';
            }
            else if (c == ' ')
            {
              users.at(id)++;
              id = 0;
            }
          }
          users.at(id)++;
        }
      }
      else if (eve.at(0) == "OFFLINE")
      {
        int timestamp = stoi(eve.at(1));
        int id = stoi(eve.at(2));
        on_time.at(id) = timestamp + 60;
      }
    }
    return users;
  }
};

int main()
{
  return 0;
}