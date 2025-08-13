#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
  {
    int min_time = INT_MAX;
    for (int i = 0; i < landStartTime.size(); i++)
    {
      for (int j = 0; j < waterStartTime.size(); j++)
      {
        int time = 0;

        if (landStartTime.at(i) < waterStartTime.at(j))
        {
          time += landStartTime.at(i) + landDuration.at(i);

          if (time < waterStartTime.at(j))
            time = waterStartTime.at(j) + waterDuration.at(j);
          else
            time += waterDuration.at(j);
        }
        else
        {
          time += waterStartTime.at(j) + waterDuration.at(j);

          if (time < landStartTime.at(i))
            time = landStartTime.at(i) + landDuration.at(i);
          else
            time += landDuration.at(i);
        }

        min_time = min(time, min_time);
      }
    }

    return min_time;
  }
};

int main()
{
  return 0;
}