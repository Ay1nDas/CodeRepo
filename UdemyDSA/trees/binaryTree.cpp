#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;

} TreeNode;

typedef struct Node
{
  TreeNode *data;
  struct Node *next;
} Node;

class Stack
{
public:
  int size;
  Node *top;

  Stack()
  {
    size = 0;
    top = NULL;
  }

  bool isEmpty()
  {
    return size == 0 ? true : false;
  }

  bool push(TreeNode *tNode)
  {
    Node *n = new Node;
    if (!n)
      return false;

    n->data = tNode;
    n->next = top;
    top = n;
    size++;

    return true;
  }

  TreeNode *pop()
  {
    if (!(this->isEmpty()))
    {
      Node *tmp = top;
      top = top->next;
      size--;

      TreeNode *retNode = tmp->data;
      free(tmp);
      return retNode;
    }
    else
    {
      return NULL;
    }
  }
};

class Queue
{
public:
  int size;
  Node *front;
  Node *rear;

  Queue()
  {
    size = 0;
    front = NULL;
    rear = NULL;
  }

  bool isEmpty()
  {
    return size == 0 ? true : false;
  }

  bool enQueue(TreeNode *node)
  {
    Node *newNode = new Node;
    if (newNode == NULL)
    {
      printf("Stack Full! \n");
      return false;
    }

    newNode->data = node;
    newNode->next = NULL;

    if (this->isEmpty())
      front = newNode;
    else
      rear->next = newNode;

    rear = newNode;
    size++;

    return true;
  }

  TreeNode *deQueue()
  {
    if (this->isEmpty())
      return NULL;

    Node *first = front;
    front = front->next;
    size--;

    if (this->isEmpty())
      rear = front = NULL;

    TreeNode *retVal = first->data;
    free(first);

    return retVal;
  }

  void displayQueue()
  {
    cout << "The Queue with " << size << " element(s) is: " << endl;
    for (Node *ptr = front; ptr != NULL; ptr = ptr->next)
      cout << ptr->data << " ";

    cout << endl;
  }
};

class Tree
{
public:
  TreeNode *root;

  Tree(vector<int> &values)
  {
    root = new TreeNode;
    root->value = values.at(0);
    root->left = NULL;
    root->right = NULL;

    Queue treeQueue;
    treeQueue.enQueue(root);
    int idx = 1;

    while (!treeQueue.isEmpty() && idx < values.size())
    {
      TreeNode *currNode = treeQueue.deQueue();
      if (!currNode)
      {
        idx += 2;
        continue;
      }

      if (values[idx] != -1 && idx < values.size())
      {
        // printf("%d ", values[idx]);
        TreeNode *newNode = new TreeNode;
        newNode->value = values.at(idx);
        newNode->left = NULL;
        newNode->right = NULL;

        currNode->left = newNode;
        treeQueue.enQueue(newNode);
      }
      else
      {
        treeQueue.enQueue(NULL);
      }
      idx++;

      if (values[idx] != -1 && idx < values.size())
      {
        // printf("%d ", values[idx]);
        TreeNode *newNode = new TreeNode;
        newNode->value = values.at(idx);
        newNode->left = NULL;
        newNode->right = NULL;

        currNode->right = newNode;
        treeQueue.enQueue(newNode);
      }
      else
      {
        treeQueue.enQueue(NULL);
      }
      idx++;
    }
  }

  void displayTree()
  {
    Stack treeStack;
    TreeNode *node = root;

    cout << "The Tree is: " << endl;
    while (node != NULL || !treeStack.isEmpty())
    {
      if (node)
      {
        cout << node->value << " ";
        treeStack.push(node);
        node = node->left;
      }
      else
      {
        node = treeStack.pop();

        // cout << "n: " << node << endl;
        node = node->right;
      }
    }
    cout << endl;
  }
};

int main()
{

  vector<int> values(5);
  values.at(0) = 1;
  values.at(1) = 2;
  values.at(2) = -1;
  values.at(3) = -1;
  values.at(4) = 5;

  Tree t1(values);
  t1.displayTree();

  return 0;
}