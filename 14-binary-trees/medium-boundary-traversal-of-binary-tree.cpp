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
vector<int> optimal(TreeNode *root) {
        // code here
        vector<int> v;
        if (root == NULL)
            return v;
        if (!leaf(root)) v.push_back(root->val);
        addLeftBoundary(root, v);
        addLeaves(root, v);
        addRightBoundary(root, v);
        return v;
    }
    bool leaf(TreeNode* root) {
        if(root->left || root->right)
            return false;
        return true;
    }
    void addLeftBoundary(TreeNode* root, vector<int>& v) {
        TreeNode* node = root->left;
        while(node) {
            if(!leaf(node)) v.push_back(node->val);
            if(node->left) node = node->left;
            else node = node->right;
        }
    }
    void addRightBoundary(TreeNode* root, vector<int>& v) {
        TreeNode* node = root->right;
        stack<int> st;
        while(node) {
            if(!leaf(node)) st.push(node->val);
            if(node->right) node = node->right;
            else node = node->left;
        }
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
    }
    void addLeaves(TreeNode* root, vector<int>& v) {
        if(leaf(root)) {
            v.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left, v);
        if(root->right) addLeaves(root->right, v);
    }

/*------------------------------------*/

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  vector<int> val = optimal(root);
  for (auto val : val)
  {
    cout << val << endl;
  }
  cout << endl;

  return 0;
}