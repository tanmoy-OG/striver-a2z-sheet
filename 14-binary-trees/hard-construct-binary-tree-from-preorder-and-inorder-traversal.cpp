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
  Time complexity: O(nlogn)
  Space complexity: O(2n)
*/
TreeNode *optimal(vector<int> &preorder, vector<int> &inorder)
{
  map<int, int> mp;
  for (int i = 0; i < inorder.size(); i++)
    mp[inorder[i]] = i;
  TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
  return root;
}
TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
  if (preStart > preEnd || inStart > inEnd)
    return NULL;
  TreeNode *root = new TreeNode(preorder[preStart]);
  int inRootPos = mp[root->val];
  int inLeftCnt = inRootPos - inStart;
  root->left = buildTree(preorder, preStart + 1, preStart + inLeftCnt, inorder, inStart, inRootPos - 1, mp);
  root->right = buildTree(preorder, preStart + inLeftCnt + 1, preEnd, inorder, inRootPos + 1, inEnd, mp);
  return root;
}

/*------------------------------------*/

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode *root = optimal(preorder, inorder);
  cout << root->val << endl;

  return 0;
}