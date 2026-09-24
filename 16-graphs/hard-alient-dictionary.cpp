#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(K+N + N*Len) (dfs traversal of directed graph, where V and E represent the number of nodes and edges in the graph. And N*Len is the time complexity of forming the graph, there Len is the average length og the words)

  Space complexity: O(4K + N) (The stack will store at most K nodes taking O(K) space and the visited array takes O(K) space, and the recursion stack space takes at most O(K) space and the answer array will be of O(K) space. And the Graph itself takes O(N) space.)
*/

string optimalDfs(string dict[], int N, int K)
{
  vector<int> adj[K];
  for (int i = 0; i < N; i++)
  {
    string st1 = dict[i];
    string st2 = dict[i + 1];
    int len = min(st1.size(), st2.size());
    for (int j = 0; j < len; j++)
      if (st1[j] != st2[j])
      {
        adj[st1[j] - 'a'].push_back(st2[j] - 'a');
        break;
      }
  }
  vector<int> topo = topoSortDfs(K, adj);
  string ans;
  for (auto it : topo)
    ans += char(it + 'a');
  return ans;
}
vector<int> topoSortDfs(int V, vector<int> adj[])
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
  Time complexity: O(2(K+N) + (N*Len)) (bfs traversal of directed graph, where K and N represent the number of nodes and edges in the graph, and traversal of all node count to calculate indegrees is N, and traversal of K times to populate the queue. And N*Len is the time complexity of forming the graph, there Len is the average length og the words)

  Space complexity: O(3K + N) (The queue will store at most K nodes taking O(K) space and the array to store the indegree takes O(K) space and the answer array takes O(K) space. And the graph itself takes N space (One adjacent pair gives at most 1 edge. There are N-1 pairs.))
*/

string optimalBfs(string dict[], int N, int K)
{
  vector<int> adj[K];
  for (int i = 0; i < N; i++)
  {
    string st1 = dict[i];
    string st2 = dict[i + 1];
    int len = min(st1.size(), st2.size());
    for (int j = 0; j < len; j++)
      if (st1[j] != st2[j])
      {
        adj[st1[j] - 'a'].push_back(st2[j] - 'a');
        break;
      }
  }
  vector<int> topo = topoSortBfs(K, adj);
  string ans;
  for (auto it : topo)
    ans += char(it + 'a');
  return ans;
}
vector<int> topoSortBfs(int V, vector<int> adj[])
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
  int N = 5, K = 4;
  string dict[N] = {
      "baa", "abcd", "abca", "cab", "cad"};

  string ans = optimalDfs(dict, N, K);
  cout << "The order to characters as per alien dictionary is: " << ans;

  string ans = optimalBfs(dict, N, K);
  cout << "The order to characters as per alien dictionary is: " << ans;

  return 0;
}