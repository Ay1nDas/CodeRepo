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
  TreeNode *searchBST(TreeNode *root, int val)
  {
    TreeNode *node = root;

    while (node)
    {
      if (val == node->val)
        break;
      else if (val < node->val)
        node = node->left;
      else
        node = node->right;
    }

    return node;
  }
};

int main()
{
  return 0;
}
