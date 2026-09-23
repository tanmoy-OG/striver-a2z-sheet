#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(N*M*log(N*M)) (where N and M are dimensions of grid)
  In the worst case, the DFS call will be made for N*M cells taking O(N*M) time.
  In worst case, the set will store O(N*M) entries that takes O(N*M*log(N*M)) time.

  Space complexity: O(3mxn) (visited matrix + recursion stack space + set)
*/

int optimal(vector<vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  set<vector<pair<int, int>>> st;
  vector<vector<int>> vis(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (!vis[i][j] && grid[i][j] == 1)
      {
        vector<pair<int, int>> v;
        dfs(i, j, i, j, v, grid, vis, m, n);
        st.insert(v);
      }
  return st.size();
}
void dfs(int i, int j, int baseI, int baseJ, vector<pair<int, int>> &v, vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n)
{
  vis[i][j] = 1;
  if (grid[i][j] == 0)
    return;
  v.push_back({i - baseI, j - baseJ});
  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};
  for (int k = 0; k < 4; k++)
  {
    int row = i + dRow[k];
    int col = j + dCol[k];
    if (row >= 0 && row < m && col >= 0 && col < n && !vis[row][col])
      dfs(row, col, baseI, baseJ, v, grid, vis, m, n);
  }
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n * n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  cout << optimal(arr) << endl;

  return 0;
}