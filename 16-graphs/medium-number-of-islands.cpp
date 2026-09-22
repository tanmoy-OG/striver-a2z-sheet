#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(2m + 2n + 5mxn) (traversal of the matrix boundaries + dfs traversal of each nodes and 4 times loop iteration for each efs traversal + traversal of visited matrix for the counter)
  Space complexity: O(2mxn) (visited matrix + recursion stack space)
*/

int optimal(vector<vector<char>> &grid)
{
  int cnt = 0, m = grid.size(), n = grid[0].size();
  vector<vector<int>> vis(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == '1' && !vis[i][j])
      {
        cnt++;
        dfs(grid, vis, i, j);
      }
  return cnt;
}
void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j)
{
  if (grid[i][j] == '0')
    return;
  vis[i][j] = 1;
  int m = grid.size(), n = grid[0].size();
  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};
  for (int k = 0; k < 4; k++)
  {
    int row = i + dRow[k];
    int col = j + dCol[k];
    if (row >= 0 && row < m && col >= 0 && col < n && !vis[row][col])
      dfs(grid, vis, row, col);
  }
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  vector<vector<char>> arr(n * n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  cout << optimal(arr) << endl;

  return 0;
}