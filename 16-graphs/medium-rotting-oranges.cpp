#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(mxn + mxn x 4 = 5 mxn) (traversal of each nodes and bfs traversal of each nodes and 4 times loop iteration for each bfs traversal)
  Space complexity: O(2 mxn) (visited matrix + queue)
*/

int optimal(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  queue<pair<pair<int, int>, int>> q;
  int vis[m][n];
  int fresh = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      if (grid[i][j] == 2)
      {
        q.push({{i, j}, 0});
        vis[i][j] = 2;
      }
      else
        vis[i][j] = 0;
      if (grid[i][j] == 1)
        fresh++;
    }
  int newlyRotten = 0;
  int maxTime = 0;
  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};
  while (!q.empty())
  {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int time = q.front().second;
    q.pop();
    maxTime = max(maxTime, time);
    for (int i = 0; i < 4; i++)
    {
      int nRow = row + dRow[i];
      int nCol = col + dCol[i];
      if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
          !vis[nRow][nCol] && grid[nRow][nCol] == 1)
      {
        q.push({{nRow, nCol}, time + 1});
        vis[nRow][nCol] = 2;
        newlyRotten++;
      }
    }
  }
  if (newlyRotten != fresh)
    return -1;
  return maxTime;
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