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
  postOrder(root, v);
  return v;
}
void postOrder(TreeNode *root, vector<int> &v)
{
  if (root == NULL)
    return;
  postOrder(root->left, v);
  postOrder(root->right, v);
  v.push_back(root->val);
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(h)
*/
vector<int> bruteIterative(TreeNode *root)
{
  vector<int> v;
  if (root == NULL)
    return v;
  stack<TreeNode *> st1, st2;
  TreeNode *node = root;
  st1.push(node);
  while (!st1.empty())
  {
    node = st1.top();
    st1.pop();
    st2.push(node);
    if (node->left != NULL)
      st1.push(node->left);
    if (node->right != NULL)
      st1.push(node->right);
  }
  while (!st2.empty())
  {
    node = st2.top();
    st2.pop();
    v.push_back(node->val);
  }
  return v;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(n)
*/
vector<int> optimalIterative(TreeNode *root)
{
  vector<int> v;
  stack<TreeNode *> st;
  TreeNode *node = root;
  while (node != NULL || !st.empty())
  {
    if (node != NULL)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      TreeNode *temp = st.top()->right;
      if (temp == NULL)
      {
        temp = st.top();
        st.pop();
        v.push_back(temp->val);
        while (!st.empty() && temp == st.top()->right)
        {
          temp = st.top();
          st.pop();
          v.push_back(temp->val);
        }
      }
      else
        node = temp;
    }
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

  vector<int> res = bruteIterative(root);
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