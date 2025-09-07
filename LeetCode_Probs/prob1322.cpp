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
  int deepestLeavesSum(TreeNode *root)
  {
    queue<TreeNode *> childs;
    childs.push(root);
    int end_sum = root->val;

    while (!childs.empty())
    {
      end_sum = 0;
      int child_cnt = childs.size();
      while (child_cnt--)
      {
        TreeNode *n = childs.front();
        childs.pop();

        end_sum += n->val;

        if (n->left)
          childs.push(n->left);
        if (n->right)
          childs.push(n->right);
      }
    }

    return end_sum;
  }
};

int main()
{
  return 0;
}