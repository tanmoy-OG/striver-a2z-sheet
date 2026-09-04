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
vector<int> optimalCommon(TreeNode *root)
{
  vector<int> v;
  preOrder(root, v);
  return v;
}
void preOrder(TreeNode *root, vector<int> &v)
{
  if (root == NULL)
    return;
  v.push_back(root->val);
  preOrder(root->left, v);
  preOrder(root->right, v);
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(h)
*/
vector<int> optimalIterative(TreeNode *root)
{
  vector<int> v;
  TreeNode *node = root;
  if (root == NULL)
    return v;
  stack<TreeNode *> st;
  st.push(node);
  while (!st.empty())
  {
    node = st.top();
    st.pop();
    v.push_back(node->val);
    if (node->right != NULL)
      st.push(node->right);
    if (node->left != NULL)
      st.push(node->left);
  }
  return v;
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<int> res = optimalCommon(root);
  for (int val : res)
  {
    cout << val << " ";
  }
  cout << endl;

  vector<int> res = optimalIterative(root);
  for (int val : res)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}