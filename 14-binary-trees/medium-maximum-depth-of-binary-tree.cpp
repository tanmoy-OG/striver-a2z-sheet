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
  int maxi = dfs(root);
  return maxi;
}
int dfs(TreeNode *root)
{
  if (root == NULL)
    return 0;
  int lh = dfs(root->left);
  int rh = dfs(root->right);
  return 1 + max(lh, rh);
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(n)
*/
int optimalBfs(TreeNode *root)
{
  int maxi = bfs(root);
  return maxi;
}
int bfs(TreeNode *root)
{
  if (root == NULL)
    return 0;
  queue<TreeNode *> q;
  TreeNode *node = root;
  int maxi = 0;
  q.push(node);
  while (!q.empty())
  {
    int size = q.size();
    maxi++;
    for (int i = 0; i < size; i++)
    {
      node = q.front();
      q.pop();
      if (node->left != NULL)
        q.push(node->left);
      if (node->right != NULL)
        q.push(node->right);
    }
  }
  return maxi;
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
  cout << optimalBfs(root) << endl;

  return 0;
}