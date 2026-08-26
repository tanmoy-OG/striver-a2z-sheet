#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
  Time complexity: O(n)
  Space complexity: O(n)
*/
int optimalBfs(TreeNode *root)
{
  if (root == NULL)
    return true;
  return bfs(root) != -1;
}
int bfs(TreeNode *node)
{
  if (node == NULL)
    return 0;
  int lh = bfs(node->left);
  if (lh == -1)
    return -1;
  int rh = bfs(node->right);
  if (rh == -1)
    return -1;
  return abs(lh - rh) > 1 ? -1 : 1 + max(lh, rh);
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << optimalBfs(root) << endl;

  return 0;
}