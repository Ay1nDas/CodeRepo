#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
  {
    vector<int> free_time;
    free_time.push_back(startTime.at(0) - 0);

    for (int i = 0; i + 1 < startTime.size(); i++)
    {
      free_time.push_back(startTime.at(i + 1) - endTime.at(i));
    }

    free_time.push_back(eventTime - endTime.at(endTime.size() - 1));

    for (int i : free_time)
    {
      cout << i << " ";
    }
    cout << endl;

    int max_free = 0;
    for (int i = 0; i < k + 1; i++)
    {
      max_free += free_time.at(i);
    }

    int sliding_free = max_free;
    for (int i = k + 1; i < free_time.size(); i++)
    {
      sliding_free += free_time.at(i);
      sliding_free -= free_time.at(i - k - 1);
      if (sliding_free > max_free)
      {
        max_free = sliding_free;
      }
    }

    return max_free;
  }
};

int main()
{
  return 0;
}