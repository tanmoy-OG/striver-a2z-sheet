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
  int maxi = INT_MIN;
  dfs(root, maxi);
  return maxi;
}
int dfs(TreeNode *node, int maxi)
{
  if (node == NULL)
    return 0;
  int lSum = max(0, dfs(node->left, maxi));
  int rSum = max(0, dfs(node->right, maxi));
  maxi = max(maxi, lSum + rSum + node->val);
  return node->val + max(lSum, rSum);
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