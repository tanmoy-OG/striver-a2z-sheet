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
  Time complexity: O(logn^2)
  Space complexity: O(logn)
*/
int optimal(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int lh = leftHeight(root);
  int rh = rightHeight(root);
  if (lh == rh)
    return (1 << lh) - 1;
  return 1 + optimal(root->left) + optimal(root->right);
}
int leftHeight(TreeNode *root)
{
  int cnt = 1;
  while (root->left)
  {
    cnt++;
    root = root->left;
  }
  return cnt;
}
int rightHeight(TreeNode *root)
{
  int cnt = 1;
  while (root->right)
  {
    cnt++;
    root = root->right;
  }
  return cnt;
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int res = optimal(root);
  cout << res << endl;

  return 0;
}