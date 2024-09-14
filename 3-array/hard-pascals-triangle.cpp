#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n^3)
  Space complexity: O(n)
*/

int nCr(int n, int r) {
  long long response = 1;

  for (int i = 0; i < r; i++) {
    response *= n - i;
    response /= i + 1;
  }

  return (int)response;
}

vector<vector<int>> generateBrute(int numRows) {
  vector<vector<int>> ans;

  for (int i = 1; i <= numRows; i++) {
    vector<int> temp;
    for (int j = 1; j <= i; j++)
      temp.push_back(nCr(i-1, j-1));
    ans.push_back(temp);
  }

  return ans;
}

/*
  Optimized approach:
  Time complexity: O(n^2)
  Space complexity: O(n^2)
*/

vector<int> generateRows(int i) {
  long long value = 1;
  vector<int> response = {1};

  for (int j = 1; j < i; j++) {
    value *= i - j;
    value /= j;
    response.push_back(value);
  }

  return response;
}

vector<vector<int>> generateOpti(int numRows) {
  vector<vector<int>> ans;

  for (int i = 1; i <= numRows; i++)
    ans.push_back(generateRows(i));

  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> ans = generateBrute(n);

  for (auto it : ans) {
    for (auto el : it)
      cout << el << " ";
    cout << endl;
  }
  cout << endl;

  vector<vector<int>> ans1 = generateOpti(n);

  for (auto it : ans1) {
    for (auto el : it)
      cout << el << " ";
    cout << endl;
  }

  return 0;
}