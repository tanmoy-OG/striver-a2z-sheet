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
  map<int, map<int, multiset<int>>> mp;
  vector<vector<int>> ans;
  dfs(root, mp, 0, 0);
  for (auto &[col, rows] : mp)
  {
    vector<int> rowItems;
    for (auto &[row, values] : rows)
      for (auto it : values)
        rowItems.push_back(it);
    ans.push_back(rowItems);
  }
  return ans;
}
void dfs(TreeNode *node, map<int, map<int, multiset<int>>> &mp, int col, int row)
{
  if (node == NULL)
    return;
  mp[col][row].insert(node->val);
  dfs(node->left, mp, col - 1, row + 1);
  dfs(node->right, mp, col + 1, row + 1);
}

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<vector<int>> vals = optimal(root);
  for (auto vals: vals) {
    for(auto val: vals)
      cout << val << ", ";
    cout << endl;
  }
  cout << endl;

  return 0;
}