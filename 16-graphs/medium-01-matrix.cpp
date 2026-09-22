#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(mxn + 4 mxn = 5 mxn) (traversal of the matrix + bfs traversal of each nodes and 4 times loop iteration for each bfs traversal)
  Space complexity: O(2mxn) (visited matrix + queue)
*/

vector<vector<int>> optimal(vector<vector<int>> &image, int sr, int sc, int color)
{
  int check = image[sr][sc];
  if (check == color)
    return image;
  int m = image.size(), n = image[0].size();
  vector<vector<int>> v = image;
  queue<pair<pair<int, int>, int>> q;
  v[sr][sc] = color;
  q.push({{sr, sc}, color});
  while (!q.empty())
  {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int currColor = q.front().second;
    q.pop();
    if (currColor == color)
    {
      int dRow[] = {-1, 0, 1, 0};
      int dCol[] = {0, 1, 0, -1};
      for (int i = 0; i < 4; i++)
      {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];
        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
            v[nRow][nCol] == check)
        {
          q.push({{nRow, nCol}, color});
          v[nRow][nCol] = color;
        }
      }
    }
  }
  return v;
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

  int sr, sc, color;
  cin >> sr;
  cin >> sc;
  cin >> color;

  vector<vector<int>> ans = optimal(arr, sr, sc, color);
  for (auto i : ans)
  {
    for (auto j : i)
      cout << j << ", ";
    cout << endl;
  }

  return 0;
}