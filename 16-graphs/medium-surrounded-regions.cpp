#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(2m + 2n + 4mxn) (traversal of the matrix boundaries + dfs traversal of each nodes and 4 times loop iteration for each dfs traversal)
  Space complexity: O(2mxn) (visited matrix + recursion stack space)
*/

void optimal(vector<vector<char>> &board)
{
  int m = board.size(), n = board[0].size();
  vector<vector<int>> vis(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    if (board[i][0] == 'O' && !vis[i][0])
      dfs(board, vis, i, 0);
    if (board[i][n - 1] == 'O' && !vis[i][n - 1])
      dfs(board, vis, i, n - 1);
  }
  for (int j = 0; j < n; j++)
  {
    if (board[0][j] == 'O' && !vis[0][j])
      dfs(board, vis, 0, j);
    if (board[m - 1][j] == 'O' && !vis[m - 1][j])
      dfs(board, vis, m - 1, j);
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (board[i][j] == 'O' && !vis[i][j])
        board[i][j] = 'X';
}
void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int i, int j)
{
  int m = board.size(), n = board[0].size();
  if (board[i][j] == 'X')
    return;
  vis[i][j] = 1;
  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};
  for (int k = 0; k < 4; k++)
  {
    int row = i + dRow[k];
    int col = j + dCol[k];
    if (row >= 0 && row < m && col >= 0 && col < n && !vis[row][col])
      dfs(board, vis, row, col);
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

  optimal(arr);
  for (auto i : arr)
  {
    for (auto j : i)
      cout << j << ", ";
    cout << endl;
  }

  return 0;
}