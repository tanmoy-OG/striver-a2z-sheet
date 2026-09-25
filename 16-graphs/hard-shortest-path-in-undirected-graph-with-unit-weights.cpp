#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach (TOPO Sort):
  Time complexity: O(2(N+M)) (BFS traversal of undirected graph (N+2M), where N and M represent the number of nodes and edges in the graph.
  Another M for creating the adjecency list.
  Another N for updating the distance array for unreachable nodes.)

  Space complexity: O(N + M) (N for the queue in worst case, M for storing the adjecency)
*/

vector<int> optimal(int N, int M, vector<vector<int>> &edges)
{
  vector<vector<int>> adj(N);
  for (auto it : edges)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  vector<int> dist(N, 1e9);
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto v : adj[node])
      if (dist[node] + 1 < dist[v])
      {
        dist[v] = dist[node] + 1;
        q.push(v);
      }
  }
  for (int i = 0; i < N; i++)
    if (dist[i] == 1e9)
      dist[i] = -1;
  return dist;
}

/*------------------------------------*/

int main()
{
  int N = 4, M = 2;
  vector<vector<int>> edges = {
      {0, 1, 2}, {0, 2, 1}};

  vector<int> ans = optimal(N, M, edges);
  cout << "The shortest distance of every node from source node is:\n";
  for (int i = 0; i < N; i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}