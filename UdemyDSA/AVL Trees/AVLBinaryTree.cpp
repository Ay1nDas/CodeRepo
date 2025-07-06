#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
  class treeNode
  {
  public:
    int value;
    int height;
    treeNode *left;
    treeNode *right;

    treeNode(int val = 0)
    {
      value = val;
      height = 1;
      left = right = NULL;
    }

    void updateHeight()
    {
      int lft_ht = left ? left->height : 0;
      int rht_ht = right ? right->height : 0;

      height = max(lft_ht, rht_ht) + 1;
    }

    int getBalanceFactor()
    {
      int lft_ht = left ? left->height : 0;
      int rht_ht = right ? right->height : 0;

      return lft_ht - rht_ht;
    }

    treeNode *llRotation()
    {
      treeNode *topNode = left;
      left = topNode->right;
      topNode->right = this;

      return topNode;
    };

    treeNode *lrRotation()
    {
      treeNode *topNode = left->right;
      left->right = topNode->left;
      topNode->left = left;
      left = topNode->right;
      topNode->right = this;

      topNode->left->updateHeight();
      topNode->right->updateHeight();
      topNode->updateHeight();

      return topNode;
    };

    treeNode *rrRotation()
    {
      treeNode *topNode = right;
      right = topNode->left;
      topNode->left = this;

      return topNode;
    };

    treeNode *rlRotation()
    {
      treeNode *topNode = right->left;
      right->left = topNode->right;
      topNode->right = right;
      right = topNode->left;
      topNode->left = this;

      topNode->left->updateHeight();
      topNode->right->updateHeight();
      topNode->updateHeight();

      return topNode;
    };
  };

  treeNode *root;
  Tree()
  {
    root = NULL;
  }

  treeNode *insert(int val)
  {
    static treeNode *node = root;

    if (node == NULL)
    {
      node = new treeNode(val);
      root = root ? root : node;

      return node;
    }

    treeNode *parent_node = node;

    if (val < node->value)
    {
      node = node->left;
      parent_node->left = this->insert(val);
    }
    else if (val > node->value)
    {
      node = node->right;
      parent_node->right = this->insert(val);
    }
    node = parent_node;

    if (node->getBalanceFactor() == 2 && node->left->getBalanceFactor() == 1)
      node = node->llRotation();
    else if (node->getBalanceFactor() == 2 && node->left->getBalanceFactor() == -1)
      node = node->lrRotation();
    else if (node->getBalanceFactor() == -2 && node->right->getBalanceFactor() == -1)
      node = node->rrRotation();
    else if (node->getBalanceFactor() == -2 && node->right->getBalanceFactor() == 1)
      node = node->rlRotation();

    parent_node->updateHeight();
    if (parent_node == root)
      root = node;

    return node;
  }

  void display(treeNode *node)
  {
    if (node == NULL)
      return;

    display(node->left);
    cout << "Value: " << node->value << " ";
    cout << "BalFact: " << node->getBalanceFactor() << " ";
    cout << "Height: " << node->height << endl;
    display(node->right);
  }
};

int main()
{
  Tree t1;

  int values[] = {10, 20, 30, 25, 28, 27, 5};
  for (int num : values)
  {
    t1.insert(num);
  }

  t1.display(t1.root);

  return 0;
}