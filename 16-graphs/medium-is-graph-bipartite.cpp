#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(n) (n = total number of nodes. Traversal of each nodes through dfs and dfs is called for each node only once)
  Space complexity: O(2n) (visited list n + recursion (n in case of skewed tree, e otherwise))
*/

bool optimal(vector<vector<int>> &graph)
{
  vector<int> vis(graph.size(), -1);
  for (int i = 0; i < graph.size(); i++)
    if (vis[i] == -1 && !dfs(i, 0, graph, vis))
      return false;
  return true;
}
bool dfs(int i, int col, vector<vector<int>> &graph, vector<int> &vis)
{
  vis[i] = col;
  for (auto it : graph[i])
  {
    if (vis[it] == -1 && !dfs(it, !col, graph, vis))
      return false;
    else if (vis[it] == vis[i])
      return false;
  }
  return true;
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  string line;
  getline(cin, line);

  vector<vector<int>> arr;
  arr.reserve(n);

  for (int i = 0; i < n; i++)
  {
    getline(cin, line);
    stringstream ss(line);
    vector<int> temp;
    int val;
    while (ss >> val)
    {
      temp.push_back(val);
    }
    arr.push_back(temp);
  }

  cout << optimal(arr) << endl;

  return 0;
}