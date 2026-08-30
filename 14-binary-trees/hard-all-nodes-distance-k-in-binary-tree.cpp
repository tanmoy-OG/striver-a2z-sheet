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
vector<int> optimal(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        storeParents(root, parents);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        vector<int> ans;
        int cnt = 0;
        q.push(target);
        while (!q.empty()) {
            int size = q.size();
            if (cnt++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                visited[node] = true;
                if (node->left && !visited[node->left])
                    q.push(node->left);
                if (node->right && !visited[node->right])
                    q.push(node->right);
                if (parents[node] && !visited[parents[node]])
                    q.push(parents[node]);
            }
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
    void storeParents(TreeNode* node,
                      unordered_map<TreeNode*, TreeNode*>& parents) {
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                if (node->left) {
                    parents[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
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

  vector<int> val = optimal(root, root->left, 1);
  for (auto val : val)
  {
    cout << val << endl;
  }
  cout << endl;

  return 0;
}