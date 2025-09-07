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
  TreeNode *reverseOddLevels(TreeNode *root)
  {
    queue<TreeNode *> q;
    queue<TreeNode *> q_rev;
    TreeNode *revRoot = root;

    q.push(root);
    q_rev.push(revRoot);

    int level = 1;

    while (!q.empty())
    {
      vector<int> vals;
      int cnt = q.size();

      while (cnt--)
      {
        TreeNode *n = q.front();
        q.pop();
        if (n->left)
        {
          q.push(n->left);
          vals.push_back(n->left->val);
        }
        if (n->right)
        {
          q.push(n->right);
          vals.push_back(n->right->val);
        }
      }

      int cnt_rev = q_rev.size();
      int idx_rev = vals.size() - 1;
      while (cnt_rev--)
      {
        TreeNode *n_rev = q_rev.front();
        q_rev.pop();

        if (n_rev->left)
          q_rev.push(n_rev->left);
        if (n_rev->right)
          q_rev.push(n_rev->right);

        if (level % 2 == 1)
        {
          if (n_rev->left)
            n_rev->left->val = vals.at(idx_rev--);
          if (n_rev->right)
            n_rev->right->val = vals.at(idx_rev--);
        }
      }
      level++;
    }
    return revRoot;
  }
};

int main()
{
  return 0;
}