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
    return 0;
  int maxi = 0;
  bfs(root, maxi);
  return maxi;
}
int bfs(TreeNode *node, int maxi)
{
  if (node == NULL)
    return 0;
  int lh = bfs(node->left, maxi);
  int rh = bfs(node->right, maxi);
  maxi = max(maxi, lh + rh);
  return 1 + max(lh, rh);
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