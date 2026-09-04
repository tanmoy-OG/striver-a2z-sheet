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
  Time complexity: O(2n)
  Space complexity: O(2n)
*/
string serialize(TreeNode *root)
{
  string st;
  if (!root)
    return st;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      if (!node)
        st += "#,";
      else
      {
        st += to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
      }
    }
  }
  return st;
}

TreeNode *deserialize(string data)
{
  if (data.size() == 0)
    return NULL;
  stringstream s(data);
  string st;
  queue<TreeNode *> q;
  getline(s, st, ',');
  TreeNode *root = new TreeNode(stoi(st));
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    getline(s, st, ',');
    if (st == "#")
      node->left = NULL;
    else
    {
      node->left = new TreeNode(stoi(st));
      q.push(node->left);
    }
    getline(s, st, ',');
    if (st == "#")
      node->right = NULL;
    else
    {
      node->right = new TreeNode(stoi(st));
      q.push(node->right);
    }
  }
  return root;
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  TreeNode *node = deserialize(serialize(root));
  cout << node->val << endl;

  return 0;
}