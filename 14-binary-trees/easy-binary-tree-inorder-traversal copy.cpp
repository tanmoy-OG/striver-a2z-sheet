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
  inOrder(root, v);
  return v;
}
void inOrder(TreeNode *root, vector<int> &v)
{
  if (root == NULL)
    return;
  inOrder(root->left, v);
  v.push_back(root->val);
  inOrder(root->right, v);
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(h)
*/
vector<int> optimalIterative(TreeNode *root)
{
  vector<int> v;
  TreeNode *temp = root;
  if (root == NULL)
    return v;
  stack<TreeNode *> st;
  st.push(temp);
  while (!st.empty())
  {
    temp = st.top();
    st.pop();
    v.push_back(temp->val);
    if (temp->right != NULL)
      st.push(temp->right);
    if (temp->left != NULL)
      st.push(temp->left);
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