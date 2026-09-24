#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(2V + E) (DFS traversal takes O(V+E) time and adding the safe nodes to the result takes O(V) time.)

  Space complexity: O(4V) (The visited, path visited, and check array take O(V) space each and the recursion stack space will be O(V) in the worst case.)
*/

vector<int> optimalDfs(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> pathVis(V, 0);
  vector<int> safe(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
    if (!vis[i])
      dfs(i, vis, pathVis, safe, adj);
  for (int i = 0; i < V; i++)
    if (safe[i] == 1)
      ans.push_back(i);
  return ans;
}
bool dfs(int i, vector<int> &vis, vector<int> &pathVis, vector<int> &safe, vector<int> adj[])
{
  vis[i] = 1;
  pathVis[i] = 1;
  for (int j : adj[i])
  {
    if (!vis[j])
    {
      if (dfs(j, vis, pathVis, safe, adj))
        return true;
    }
    else if (pathVis[j])
      return true;
  }
  safe[i] = 1;
  pathVis[i] = 0;
  return false;
}

/*
  Optimized approach (Khan's Algorithm):
  Time complexity: O(V+2E) + O(V*logV) (where V and E represents the number of nodes and edges in the given graph) (Reversing the graph takes O(E) time, Finding topological sort using Kahn's algorithm takes O(V+E) time, Sorting the nodes takes O(N*logN) time (where N is the number of safe nodes, which can go up to V in worst-case)

  Space complexity: O(2V + E) (The queue will store at most V nodes taking O(V) space and the array to store the indegree takes O(V) space, and reverse of adjecency takes E.)
*/

vector<int> optimalBfs(int V, vector<int> adj[])
{
  vector<int> rev[V];
  vector<int> inDeg(V, 0);
  vector<int> safe;
  queue<int> q;
  for (int i = 0; i < V; i++)
    for (auto j : adj[i])
    {
      rev[j].push_back(i);
      inDeg[i]++;
    }
  for (int i = 0; i < V; i++)
    if (inDeg[i] == 0)
      q.push(i);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    safe.push_back(node);
    for (int i : rev[node])
    {
      inDeg[i]--;
      if (inDeg[i] == 0)
        q.push(i);
    }
  }
  sort(safe.begin(), safe.end());
  return safe;
}

/*------------------------------------*/

int main()
{

  int V = 6;
  vector<int> adj[V] = {
      {},
      {},
      {3},
      {1},
      {0, 1},
      {0, 2}};

  vector<int> ans = optimalDfs(V, adj);
  cout << "The topological sorting of the given graph is: \n";
  for (int i = 0; i < V; i++)
    cout << ans[i] << " ";
  cout << endl;

  vector<int> ans = optimalBfs(V, adj);
  cout << "The topological sorting of the given graph is: \n";
  for (int i = 0; i < V; i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}