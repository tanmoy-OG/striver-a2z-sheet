#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(V + E) (dfs traversal of directed graph, where V and E represent the number of nodes and edges in the graph)

  Space complexity: O(3V) (The stack will store at most V nodes taking O(V) space and the visited array takes O(V) space, and the recursion stack space takes at most O(V) space.)
*/

vector<int> optimalDfs(int V, vector<int> adj[])
{
  stack<int> st;
  vector<int> vis(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
    if (!vis[i])
    {
      dfs(i, adj, vis, st);
    }
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    ans.push_back(node);
  }
  return ans;
}
void dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
  vis[i] = 1;
  for (int j : adj[i])
    if (!vis[j])
      dfs(j, adj, vis, st);
  st.push(i);
}

/*
  Optimized approach (Khan's Algorithm):
  Time complexity: O(2(V+E)) (bfs traversal of directed graph, where V and E represent the number of nodes and edges in the graph, and traversal of all node count to calculate indegrees is E, and traversal of V times to populate the queue.)

  Space complexity: O(2V) (The queue will store at most V nodes taking O(V) space and the array to store the indegree takes O(V) space.)
*/

vector<int> optimalBfs(int V, vector<int> adj[])
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