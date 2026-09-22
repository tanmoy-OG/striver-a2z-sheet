#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(n) (n = total number of nodes. Traversal of each nodes through dfs and dfs is called for each node only once)
  Space complexity: O(2n) (visited list n + recursion (n in case of skewed tree, e otherwise))
*/

int optimal(vector<vector<int>> &isConnected)
{
  int n = isConnected.size();
  vector<int> vis(n, 0);
  int cnt = 0;
  for (int i = 0; i < isConnected.size(); i++)
    if (!vis[i])
    {
      dfs(i, isConnected, vis);
      cnt++;
    }
  return cnt;
}
void dfs(int i, vector<vector<int>> &isConnected, vector<int> &vis)
{
  vis[i] = 1;
  for (int j = 0; j < isConnected.size(); j++)
    if (i != j && isConnected[i][j] && !vis[j])
      dfs(j, isConnected, vis);
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n*n);

  for (int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> arr[i][j];

  cout << optimal(arr) << endl;

  return 0;
}