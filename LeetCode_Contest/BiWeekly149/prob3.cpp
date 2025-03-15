#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
  {
    vector<int> even_duration;
    vector<int> free_time;
    vector<int> sorted_free_time;
    unordered_map<int, int> free_freq;

    free_time.push_back(startTime.at(0) - 0);
    free_freq[startTime.at(0) - 0]++;
    for (int i = 0; i + 1 < startTime.size(); i++)
    {
      free_time.push_back(startTime.at(i + 1) - endTime.at(i));
      free_freq[startTime.at(i + 1) - endTime.at(i)]++;
      even_duration.push_back(endTime.at(i) - startTime.at(i));
    }
    free_time.push_back(eventTime - endTime.at(endTime.size() - 1));
    free_freq[eventTime - endTime.at(endTime.size() - 1)]++;
    even_duration.push_back(endTime.at(endTime.size() - 1) - startTime.at(endTime.size() - 1));

    sorted_free_time = free_time;
    sort(sorted_free_time.rbegin(), sorted_free_time.rend());

    for (auto i : even_duration)
      cout << i << " ";
    cout << endl;

    for (auto i : free_time)
      cout << i << " ";
    cout << endl;

    int max_time = INT_MIN;

    for (int i = 0; i < even_duration.size(); i++)
    {
      int time = free_time.at(i) + free_time.at(i + 1);
      max_time = max(max_time, time);

      if (time + even_duration.at(i) > max_time)
      {
        int found_left = 1, found_right = 1;
        bool found = false;

        for (int j = 0; j < sorted_free_time.size(); j++)
        {
          if (even_duration.at(i) > sorted_free_time.at(j))
            break;

          else if (sorted_free_time.at(j) == free_time.at(i) && found_left > 0)
          {
            found_left--;
          }
          else if (sorted_free_time.at(j) == free_time.at(i + 1) && found_right > 0)
          {
            found_right--;
          }
          else
          {
            found = true;
            break;
          }
        }

        if (found)
          max_time = time + even_duration.at(i);
      }
    }
    return max_time;
  }
};

int main()
{
  return 0;
}