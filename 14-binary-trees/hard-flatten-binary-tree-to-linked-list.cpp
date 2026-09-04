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
  Space complexity: O(h)
*/
void brute(TreeNode *root)
{
  TreeNode *prev = NULL;
  dfs(root, prev);
}
void dfs(TreeNode *node, TreeNode *&prev)
{
  if (!node)
    return;
  dfs(node->right, prev);
  dfs(node->left, prev);
  node->right = prev;
  node->left = NULL;
  prev = node;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(h)
*/
void better(TreeNode *root)
{
  if (!root)
    return;
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty())
  {
    TreeNode *node = st.top();
    st.pop();
    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
    node->left = NULL;
    if (!st.empty())
      node->right = st.top();
  }
}

/*------------------------------------*/

/*
  Time complexity: O(2n)
  Space complexity: O(1)
*/
void optimal(TreeNode *root)
{
  TreeNode *node = root;
  while (node)
  {
    if (node->left)
    {
      TreeNode *temp = node->left;
      while (temp->right)
        temp = temp->right;
      temp->right = node->right;
      node->right = node->left;
      node->left = NULL;
    }
    node = node->right;
  }
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  brute(root);
  cout << root->val << endl;

  better(root);
  cout << root->val << endl;

  optimal(root);
  cout << root->val << endl;

  return 0;
}