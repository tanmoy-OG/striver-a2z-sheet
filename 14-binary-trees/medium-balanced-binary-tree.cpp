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
int optimalDfs(TreeNode *root)
{
  if (root == NULL)
    return true;
  return dfs(root) != -1;
}
int dfs(TreeNode *node)
{
  if (node == NULL)
    return 0;
  int lh = dfs(node->left);
  if (lh == -1)
    return -1;
  int rh = dfs(node->right);
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

  cout << optimalDfs(root) << endl;

  return 0;
}