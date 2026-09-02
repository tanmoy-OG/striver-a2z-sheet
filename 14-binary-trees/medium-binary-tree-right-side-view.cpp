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
  Space complexity: O(n/2)
*/
vector<int> brute(TreeNode *root)
{
  vector<int> v;
  if (!root)
    return v;
  queue<TreeNode *> q;
  TreeNode *node;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    while (size > 1)
    {
      node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      size--;
    }
    node = q.front();
    q.pop();
    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
    v.push_back(node->val);
  }
  return v;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(n) (In worst case like in case of a squed tree, otherwise mostly less than Level Order traversal.)
*/
vector<int> optimal(TreeNode *root)
{
  vector<int> v;
  dfs(root, 0, v);
  return v;
}
void dfs(TreeNode *node, int level, vector<int> &v)
{
  if (!node)
    return;
  if (level == v.size())
    v.push_back(node->val);
  dfs(node->right, level + 1, v);
  dfs(node->left, level + 1, v);
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<int> res = brute(root);
  for (int val : res)
    cout << val << " ";
  cout << endl;
  
  vector<int> res = optimal(root);
  for (int val : res)
    cout << val << " ";
  cout << endl;

  return 0;
}