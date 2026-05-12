// LeetCode 51. N-Queens (https://leetcode.com/problems/n-queens)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isOccupied(vector<string>& grid, int i, int j) {
    for(int k = 0; k < grid.size(); k++) {
      if(grid.at(k).at(j) == 'Q') {
        return true;
      } else if(grid.at(i).at(k) == 'Q') {
        return true;
      }
    }

    int r = i, c = j;
    while(r >= 0 && c >= 0) {
      if(grid.at(r).at(c) == 'Q') {
        return true;
      } else {
        r--; c--;
      }
    }

    r = i, c = j;
    while(r < grid.size() && c < grid.at(r).size()) {
      if(grid.at(r).at(c) == 'Q') {
        return true;
      } else {
        r++; c++;
      }
    }

    r = i, c = j;
    while(r < grid.size() && c >= 0) {
      if(grid.at(r).at(c) == 'Q') {
        return true;
      } else {
        r++; c--;
      }
    }

    r = i, c = j;
    while(r >= 0 && c < grid.at(r).size()) {
      if(grid.at(r).at(c) == 'Q') {
        return true;
      } else {
        r--; c++;
      }
    }

    return false;
  }

  vector<vector<string>> recurseQueens(vector<string>& grid, int i, int n) {
    if(i == n) {
      return {grid};
    }

    vector<vector<string>> result;
    for(int j = 0; j < n; j++) {
      if(!isOccupied(grid, i, j)) {
        grid.at(i).at(j) = 'Q';
        auto curr_res = recurseQueens(grid, i + 1, n);
        result.insert(result.end(), curr_res.begin(), curr_res.end());
        grid.at(i).at(j) = '.';
      }
    }

    return result;
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> grid(n);
    for(auto& str : grid) {
      str.assign(n, '.');
    }

    return recurseQueens(grid, 0, n);
  }
};

int main()
{
  int n = 9;

  for(auto sol : Solution().solveNQueens(n)) {
    for(auto str : sol) {
      cout << str << endl;
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
