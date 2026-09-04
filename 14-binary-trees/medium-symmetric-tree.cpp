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
bool brute(TreeNode *root)
{
  return bruteIsSymmetric(root->left, root->right);
}
bool bruteIsSymmetric(TreeNode *root1, TreeNode *root2)
{
  queue<TreeNode *> q1;
  queue<TreeNode *> q2;
  q1.push(root1);
  q2.push(root2);
  while (!q1.empty() && !q2.empty())
  {
    TreeNode *node1 = q1.front();
    TreeNode *node2 = q2.front();
    q1.pop();
    q2.pop();
    if (!node1 && !node2)
      continue;
    if (!node1 || !node2)
      return false;
    if (node1->val != node2->val)
      return false;
    q1.push(node1->left);
    q1.push(node1->right);
    q2.push(node2->right);
    q2.push(node2->left);
  }
  return true;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(h)
*/
bool optimal(TreeNode *root)
{
  return isSymmetric(root->left, root->right);
}
bool isSymmetric(TreeNode *node1, TreeNode *node2)
{
  if (!node1 || !node2)
    return node1 == node2;
  return (node1->val == node2->val) && isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  bool mirror = brute(root);
  cout << mirror << endl;

  bool mirror = optimal(root);
  cout << mirror << endl;

  return 0;
}