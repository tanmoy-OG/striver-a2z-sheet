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
vector<vector<int>> optimal(TreeNode *root)
{
  vector<vector<int>> v;
  if (root == NULL)
    return v;
  queue<TreeNode *> q;
  TreeNode *node = root;
  q.push(node);
  while (!q.empty())
  {
    vector<vector<int>> v;
    if (root == NULL)
      return v;
    queue<TreeNode *> q;
    TreeNode *node = root;
    int flag = 0;
    q.push(node);
    while (!q.empty())
    {
      int size = q.size();
      vector<int> temp(size);
      for (int i = 0; i < size; i++)
      {
        node = q.front();
        q.pop();
        int index = flag == 0 ? i : size - i - 1;
        temp[index] = node->val;
        if (node->left != NULL)
          q.push(node->left);
        if (node->right != NULL)
          q.push(node->right);
      }
      flag = flag == 1 ? 0 : 1;
      v.push_back(temp);
    }
    return v;
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

  vector<vector<int>> res = optimal(root);
  for (auto level : res)
  {
    for (int val : level)
    {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}