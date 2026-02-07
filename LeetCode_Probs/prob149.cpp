#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map <double, unordered_map<double, set<int>>> freq;
        unordered_map<double, set<int>> inf_x;
        int max_val = 1;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                double x1 = points.at(i).at(0);
                double y1 = points.at(i).at(1);
                double x2 = points.at(j).at(0);
                double y2 = points.at(j).at(1);
                
                double theta = atan2(y2 - y1, x2 - x1);
                if (theta < 0) {
                    theta += M_PI;
                }

                if(theta == 0 || theta == M_PI) {
                    inf_x[y1].insert(i);
                    inf_x[y1].insert(j);

                    max_val = max(max_val, static_cast<int>(inf_x[y1].size()));
                    continue;
                }

                double x = x1 - (y1 / tan(theta));

                freq[theta][x].insert(i);
                freq[theta][x].insert(j);

                max_val = max(max_val, static_cast<int>(freq[theta][x].size()));
            }
        }

        return max_val;
    }
};

int main()
{
  return 0;
}