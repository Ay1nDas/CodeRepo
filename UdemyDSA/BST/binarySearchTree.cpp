#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
  int value;
  treeNode *left;
  treeNode *right;

  treeNode(int val = 0)
  {
    value = val;
    left = right = NULL;
  }
};

class Tree
{
public:
  treeNode *root;

  Tree()
  {
    root = NULL;
  }

  bool insert(int val)
  {
    treeNode *node = root;
    treeNode *preNode = NULL;

    if (node == NULL)
    {
      root = new treeNode;
      root->value = val;
    }
    else
    {
      while (node)
      {
        preNode = node;

        if (val < node->value)
          node = node->left;
        else if (val > node->value)
          node = node->right;
        else
          return false;
      }

      treeNode *newNode = new treeNode(val);
      if (val < preNode->value)
        preNode->left = newNode;
      else
        preNode->right = newNode;
    }
    return true;
  }

  treeNode *find(int value)
  {
    treeNode *node = root;
    while (node != NULL && node->value != value)
    {
      if (value < node->value)
        node = node->left;
      else if (value > node->value)
        node = node->right;
    }

    return node;
  }

  bool remove(treeNode *node)
  {
    if (node == NULL)
      return false;

    treeNode *tail = root;
    while (tail != node)
    {
      if (node->value < tail->value)
      {
        if (node->value == tail->left->value)
          break;
        else
          tail = tail->left;
      }
      else if (node->value > tail->value)
      {
        if (node->value == tail->right->value)
          break;
        else
          tail = tail->right;
      }
    }
    // cout << tail->value << endl;

    if (node->left == NULL && node->right == NULL)
    {
      if (tail->left == node)
        tail->left = NULL;
      else
        tail->right = NULL;

      return true;
    }

    treeNode *retNode = NULL;
    if (node->left)
    {
      retNode = node->left;
      while (retNode->right)
        retNode = retNode->right;
    }
    else if (node->right)
    {
      retNode = node->right;
      while (retNode->left)
        retNode = retNode->left;
    }

    cout << retNode->value << endl;

    remove(retNode);

    retNode->left = node->left;
    retNode->right = node->right;

    if (retNode->value < tail->value)
      tail->left = retNode;
    else if (retNode->value > tail->value)
      tail->right = retNode;

    node->left = node->right = NULL;

    if (node == root)
      root = retNode;

    return true;
  }

  void display(treeNode *node)
  {
    if (node == NULL)
      return;

    display(node->left);
    cout << node->value << " ";
    display(node->right);
  }
};

int main()
{

  Tree t1;

  int vals[] = {23, 12, 22, 89, 102, 1, 33, 50};

  for (int num : vals)
  {
    t1.insert(num);
  }

  t1.display(t1.root);
  cout << endl;

  t1.remove(t1.find(23));

  t1.display(t1.root);
  cout << endl;
  return 0;
}