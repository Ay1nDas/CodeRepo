#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    unordered_map<int, int> visited_rooms;
    queue<int> queued_rooms;
    queued_rooms.push(0);
    visited_rooms[0] = 1;

    while (queued_rooms.size() != 0)
    {
      int curr_room = queued_rooms.front();
      queued_rooms.pop();

      for (auto key : rooms.at(curr_room))
      {
        if (visited_rooms[key] == 0)
          queued_rooms.push(key);
        visited_rooms[key] = 1;
      }
    }

    for (int i = 0; i < rooms.size(); i++)
    {
      if (visited_rooms[i] == 0)
        return false;
    }
    return true;
  }
};

int main()
{
  return 0;
}