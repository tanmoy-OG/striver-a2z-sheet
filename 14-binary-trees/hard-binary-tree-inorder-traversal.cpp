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
  Space complexity: O(1)
*/
vector<int> optimal(TreeNode *root)
{
  vector<int> v;
  TreeNode *node = root;
  while (node)
  {
    if (node->left == NULL)
    {
      v.push_back(node->val);
      node = node->right;
    }
    else
    {
      TreeNode *prev = node->left;
      while (prev->right && prev->right != node)
        prev = prev->right;
      if (prev->right == NULL)
      {
        prev->right = node;
        node = node->left;
      }
      else
      {
        prev->right = NULL;
        v.push_back(node->val);
        node = node->right;
      }
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

  vector<int> res = optimal(root);
  for (int val : res)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}