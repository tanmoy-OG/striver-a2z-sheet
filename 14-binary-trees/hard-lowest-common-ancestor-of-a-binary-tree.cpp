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
TreeNode *optimalDfs(TreeNode *node, TreeNode *p, TreeNode *q)
{
  if (node == NULL || node == p || node == q)
    return node;
  TreeNode *left = optimalDfs(node->left, p, q);
  TreeNode *right = optimalDfs(node->right, p, q);
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;
  return node;
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  TreeNode *p = root->left;
  TreeNode *q = root->left->right;

  cout << optimalDfs(root, p, q) << endl;

  return 0;
}