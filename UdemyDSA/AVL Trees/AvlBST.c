#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
  int val;
  int height;
  struct treeNode *left;
  struct treeNode *right;

} TreeNode;

int getBalanceFactor(TreeNode *node)
{
  if (node == NULL)
    return 0;

  int lftHight = node->left == NULL ? 0 : node->left->height;
  int rhtHight = node->right == NULL ? 0 : node->right->height;

  return lftHight - rhtHight;
}

void updateHeight(TreeNode *node)
{
  if (node == NULL)
    return;

  int lftHight = node->left == NULL ? 0 : node->left->height;
  int rhtHight = node->right == NULL ? 0 : node->right->height;

  node->height = (lftHight > rhtHight ? lftHight : rhtHight) + 1;
}

/*
 * LL rotation  (left-left case)  — perform a RIGHT rotation at root
 *      30
 *      /             20
 *    20         ->  /  \
 *    /             10  30
 *  10
 */
TreeNode *llRotation(TreeNode *parentNode)
{
  TreeNode *newTop = parentNode->left;
  parentNode->left = newTop->right;
  newTop->right = parentNode;

  updateHeight(newTop->left);
  updateHeight(newTop->right);
  updateHeight(newTop);

  return newTop;
}

/*
 * RR rotation (Left Rotation)
 *    10
 *      \             20
 *       20      ->  /  \
 *        \         10  30
 *         30
 */
TreeNode *rrRotation(TreeNode *parentNode)
{
  TreeNode *newTop = parentNode->right;
  parentNode->right = newTop->left;
  newTop->left = parentNode;

  updateHeight(newTop->left);
  updateHeight(newTop->right);
  updateHeight(newTop);

  return newTop;
}

/*
 * LR rotation (Left-Right Rotation)
 *
 *      30                  20
 *     /                   /  \
 *   10         ->        10  30
 *     \
 *     20
 */
TreeNode *lrRotation(TreeNode *parentNode)
{
  TreeNode *newTop = parentNode->left->right;
  TreeNode *topLeft = newTop->left;
  TreeNode *topRight = newTop->right;

  newTop->left = parentNode->left;
  newTop->right = parentNode;

  newTop->left->right = topLeft;
  newTop->right->left = topRight;

  updateHeight(newTop->left);
  updateHeight(newTop->right);
  updateHeight(newTop);

  return newTop;
}

/*
 * RL rotation (Right-Left Rotation)
 *
 *    10                     20
 *      \                   /  \
 *      30       ->        10  30
 *     /
 *    20
 */
TreeNode *rlRotation(TreeNode *parentNode)
{
  TreeNode *newTop = parentNode->right->left;
  TreeNode *topLeft = newTop->left;
  TreeNode *topRight = newTop->right;

  newTop->right = parentNode->right;
  newTop->left = parentNode;

  newTop->left->right = topLeft;
  newTop->right->left = topRight;

  updateHeight(newTop->left);
  updateHeight(newTop->right);
  updateHeight(newTop);

  return newTop;
}

TreeNode *insertInBST(TreeNode *root, int value)
{
  if (root == NULL)
  {
    TreeNode *new = malloc(sizeof(TreeNode));
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    updateHeight(new);

    return new;
  }

  if (value < root->val)
  {
    root->left = insertInBST(root->left, value);
  }
  else if (value > root->val)
  {
    root->right = insertInBST(root->right, value);
  }

  updateHeight(root);

  if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == 1)
  {
    root = llRotation(root);
  }
  else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == -1)
  {
    root = rrRotation(root);
  }
  else if (getBalanceFactor(root) == 2 && getBalanceFactor(root->left) == -1)
  {
    root = lrRotation(root);
  }
  else if (getBalanceFactor(root) == -2 && getBalanceFactor(root->right) == 1)
  {
    root = rlRotation(root);
  }

  return root;
}

/*
***************************
FOR Displaying the tree
***************************
*/

typedef struct NodeInfo
{
  int x, y;     // Position on canvas
  char str[20]; // Value as text
} NodeInfo;

// Place nodes on canvas recursively
void placeNodes(TreeNode *root, int x, int y, int offset, NodeInfo arr[], int *idx)
{
  if (!root)
    return;

  // Store node info
  arr[*idx].x = x;
  arr[*idx].y = y;
  sprintf(arr[*idx].str, "%d", root->val);
  (*idx)++;

  // Recurse left + right
  if (root->left)
    placeNodes(root->left, x - offset, y + 2, offset / 2, arr, idx);

  if (root->right)
    placeNodes(root->right, x + offset, y + 2, offset / 2, arr, idx);
}

// Draw tree vertically
void displayTree(TreeNode *root)
{
  if (!root)
  {
    printf("(empty tree)\n");
    return;
  }

  int height = root->height;
  int width = 6 * (1 << height); // Enough horizontal space

  char canvas[200][500];
  for (int i = 0; i < 200; i++)
    for (int j = 0; j < 500; j++)
      canvas[i][j] = ' ';

  NodeInfo arr[200];
  int idx = 0;

  int startX = width / 2;

  placeNodes(root, startX, 0, width / 4, arr, &idx);

  // Draw nodes
  for (int i = 0; i < idx; i++)
  {
    int x = arr[i].x;
    int y = arr[i].y;
    int len = strlen(arr[i].str);
    for (int j = 0; j < len; j++)
      canvas[y][x + j] = arr[i].str[j];
  }

  // Print the canvas
  for (int i = 0; i < 200; i++)
  {
    int blank = 1;
    for (int j = 0; j < width; j++)
      if (canvas[i][j] != ' ')
        blank = 0;

    if (!blank)
    {
      for (int j = 0; j < width; j++)
        putchar(canvas[i][j]);
      putchar('\n');
    }
  }
}

/*
**************************************
EOF
**************************************
*/

int main()
{
  TreeNode *root = NULL;
  // int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int values[] = {10, 20, 30, 25, 28, 27, 5};
  for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
  {
    root = insertInBST(root, values[i]);
  }

  displayTree(root);
  return 0;
}