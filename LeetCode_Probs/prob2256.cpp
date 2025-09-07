#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<int> subTreeSum(TreeNode *subRoot, int &cnt)
  {
    if (subRoot == NULL)
      return {0, 0};

    vector<int> left_vals = subTreeSum(subRoot->left, cnt);
    vector<int> right_vals = subTreeSum(subRoot->right, cnt);

    vector<int> ret_vals(2);
    ret_vals.at(0) = left_vals.at(0) + subRoot->val + right_vals.at(0);
    ret_vals.at(1) = left_vals.at(1) + 1 + right_vals.at(1);

    if (ret_vals.at(0) / ret_vals.at(1) == subRoot->val)
      cnt++;

    return ret_vals;
  }

  int averageOfSubtree(TreeNode *root)
  {
    int cnt = 0;
    subTreeSum(root, cnt);
  }
};

int main()
{
  return 0;
}