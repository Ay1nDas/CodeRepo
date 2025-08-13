#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef struct node
  {
    node *left;
    node *right;
    int val;
  } node;

  int minTime(string s, vector<int> &order, int k)
  {
    vector<int> part(2);
    part.at(0) = -1;
    part.at(1) = s.size();

    node *root = new node;
    root->val = order.at(0);
    root->left = NULL;
    root->right = NULL;

    long long subCnt = static_cast<long long>(order.at(0) + 1) * (s.size() - order.at(0));
    cout << subCnt << endl;

    if (subCnt >= k)
      return 0;

    for (int i = 1; i < order.size(); i++)
    {
      int upper = s.size();
      int lower = -1;

      node *n = root;
      while (n != NULL)
      {
        if (order.at(i) > n->val)
        {
          lower = n->val;
          if (n->right == NULL)
          {
            node *tmp = new node;
            tmp->val = order.at(i);
            tmp->left = NULL;
            tmp->right = NULL;
            n->right = tmp;
            break;
          }
          else
          {
            n = n->right;
          }
        }
        else if (order.at(i) < n->val)
        {
          upper = n->val;
          if (n->left == NULL)
          {
            node *tmp = new node;
            tmp->val = order.at(i);
            tmp->left = NULL;
            tmp->right = NULL;
            n->left = tmp;
            break;
          }
          else
          {
            n = n->left;
          }
        }
      }

      subCnt += static_cast<long long>(order.at(i) - lower) * (upper - order.at(i));
      cout << subCnt << endl;

      if (subCnt >= k)
        return i;
    }
    return -1;
  }
};

int main()
{
  return 0;
}