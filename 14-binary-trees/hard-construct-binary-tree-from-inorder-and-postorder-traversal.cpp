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
TreeNode *optimal(vector<int> &inorder, vector<int> &postorder)
{
  map<int, int> mp;
  for (int i = 0; i < inorder.size(); i++)
    mp[inorder[i]] = i;
  TreeNode *root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
  return root;
}
TreeNode *buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{
  if (postStart > postEnd || inStart > inEnd)
    return NULL;
  TreeNode *root = new TreeNode(postorder[postEnd]);
  int inRootPos = mp[root->val];
  int inLeftCnt = inRootPos - inStart;
  root->left = buildTree(postorder, postStart, postStart + inLeftCnt - 1, inorder, inStart, inRootPos - 1, mp);
  root->right = buildTree(postorder, postStart + inLeftCnt, postEnd - 1, inorder, inRootPos + 1, inEnd, mp);
  return root;
}

/*------------------------------------*/

int main()
{
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  TreeNode *root = optimal(inorder, postorder);
  cout << root->val << endl;

  return 0;
}