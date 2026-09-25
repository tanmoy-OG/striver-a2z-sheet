#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach (TOPO Sort):
  Time complexity: O(2(N+M) + 2M) (Topo Sort (2(N+M) or (N+M) DFS vs BFS) of directed graph, where N and M represent the number of nodes and edges in the graph. 
  And extra M is the time complexity of relaxing the edges of each node and their adjacent ones.
  Another M for creating the adjecency list.)

  Space complexity: O(2N + M) (2N for Toposort M for storing the adjecency)
*/

vector<int> optimal(int N, int M, vector<vector<int>> &edges)
{
  vector<vector<pair<int, int>>> adj(N);
  for (auto it : edges)
    adj[it[0]].push_back({it[1], it[2]});
  vector<int> topo = topoSort(N, adj);
  vector<int> dist(N, 1e9);
  dist[0] = 0;
  for (auto node : topo)
  {
    if (dist[node] == 1e9)
    {
      dist[node] = -1;
      continue;
    }
    for (auto it : adj[node])
    {
      int v = it.first;
      int d = it.second;
      if (dist[node] + d < dist[v])
        dist[v] = dist[node] + d;
    }
  }
  return dist;
}
vector<int> topoSort(int V, vector<vector<pair<int, int>>> &adj)
{
  queue<int> q;
  vector<int> deg(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
    for (auto j : adj[i])
      deg[j.first]++;
  for (int i = 0; i < V; i++)
    if (deg[i] == 0)
      q.push(i);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto j : adj[node])
    {
      int v = j.first;
      deg[v]--;
      if (deg[v] == 0)
        q.push(v);
    }
  }
  return ans;
}

/*------------------------------------*/

int main()
{
  int N = 4, M = 2;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}  
    };

    vector<int> ans = optimal(N, M, edges);
    cout << "The shortest distance of every node from source node is:\n";
    for(int i=0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}