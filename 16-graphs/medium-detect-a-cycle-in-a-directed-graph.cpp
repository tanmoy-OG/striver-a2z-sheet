#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(V + E) (dfs traversal of directed graph, where V and E represent the number of nodes and edges in the graph)

  Space complexity: O(3V) (The dfs recursion stack space will store at most V nodes taking O(V) space and the two visited arrays take O(V) spaces.)
*/

bool optimalDfs(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> dfsVis(V, 0);
  for (int i = 0; i < V; i++)
    if (!vis[i] && dfs(i, vis, dfsVis, adj))
      return true;
  return false;
}
bool dfs(int i, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[])
{
  vis[i] = 1;
  dfsVis[i] = 1;
  for (int j : adj[i])
  {
    if (dfsVis[j])
      return true;
    else if (!vis[j] && dfs(j, vis, dfsVis, adj))
      return true;
  }
  dfsVis[i] = 0;
  return false;
}

/*
  Optimized approach (Khan's Algorithm):
  Time complexity: O(2(V+E)) (bfs traversal of directed graph, where V and E represent the number of nodes and edges in the graph, and traversal of all node count to calculate indegrees is E, and traversal of V times to populate the queue.)

  Space complexity: O(3V) (The queue will store at most V nodes taking O(V) space and the array to store the indegree takes O(V) space, and the ans array required to return the toposort for checking.)
*/

bool optimalBfs(int V, vector<int> adj[])
{
  vector<int> topo;
  topo = bfs(V, adj);
  if (topo.size() < V)
    return true;
  return false;
}
vector<int> bfs(int V, vector<int> adj[])
{
  queue<int> q;
  vector<int> deg(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
    for (int j : adj[i])
      deg[j]++;
  for (int i = 0; i < V; i++)
    if (deg[i] == 0)
      q.push(i);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int j : adj[node])
    {
      deg[j]--;
      if (deg[j] == 0)
        q.push(j);
    }
  }
  return ans;
}

/*------------------------------------*/

int main()
{
  int V = 6;
    vector<int> adj[V] = {
        {1}, 
        {2, 5}, 
        {3}, 
        {4}, 
        {1},
        {} 
    };

    bool ans = optimalDfs(V, adj);
    if(ans)
        cout << "The given directed graph contains a cycle.";
    else 
        cout << "The given directed graph does not contain a cycle.";

    bool ans = optimalBfs(V, adj);
    if(ans)
        cout << "The given directed graph contains a cycle.";
    else 
        cout << "The given directed graph does not contain a cycle.";
    
    return 0;
}