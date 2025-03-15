#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxRectangleArea(vector<vector<int>> &points)
  {
    vector<vector<int>> coordinate(101, vector<int>(101));
    vector<vector<int>> possible_rectangles;

    for (int i = 0; i < points.size(); i++)
      coordinate.at(points.at(i).at(0)).at(points.at(i).at(1))++;

    for (int i = 0; i < points.size(); i++)
    {
      for (int j = 0; j < points.size(); j++)
      {
        if (points.at(j).at(0) > points.at(i).at(0) && points.at(j).at(1) > points.at(i).at(1))
        {
          if (coordinate.at(points.at(i).at(0)).at(points.at(j).at(1)) > 0 && coordinate.at(points.at(j).at(0)).at(points.at(i).at(1)) > 0)
          {
            possible_rectangles.push_back(points.at(i));
            possible_rectangles.push_back(points.at(j));
          }
        }
      }
    }

    int max_area{-1};
    for (int i = 0; i + 1 < possible_rectangles.size(); i += 2)
    {

      int a = possible_rectangles.at(i).at(0);
      int b = possible_rectangles.at(i).at(1);
      int x = possible_rectangles.at(i + 1).at(0);
      int y = possible_rectangles.at(i + 1).at(1);

      if (abs(x - a) * abs(y - b) > max_area)
      {
        bool isArea = true;
        for (int i = 0; i < points.size(); i++)
        {
          if (points.at(i).at(0) > a && points.at(i).at(1) > b && points.at(i).at(0) < x && points.at(i).at(1) < y)
          {
            isArea = false;
            break;
          }
          else if (points.at(i).at(0) == a && points.at(i).at(1) > b && points.at(i).at(1) < y)
          {
            isArea = false;
            break;
          }
          else if (points.at(i).at(0) == x && points.at(i).at(1) > b && points.at(i).at(1) < y)
          {
            isArea = false;
            break;
          }
          else if (points.at(i).at(1) == b && points.at(i).at(0) > a && points.at(i).at(0) < x)
          {
            isArea = false;
            break;
          }
          else if (points.at(i).at(1) == y && points.at(i).at(0) > a && points.at(i).at(0) < x)
          {
            isArea = false;
            break;
          }
        }
        if (isArea)
        {
          max_area = abs(x - a) * abs(y - b);
        }
      }
    }
    return max_area;
  }
};

int main()
{
}