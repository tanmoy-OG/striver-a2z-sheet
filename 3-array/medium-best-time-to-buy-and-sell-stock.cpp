#include <bits/stdc++.h>

using namespace std;

/*
  Brute Force Approach
  Time Complexity: O(n^2)
  Space Complexity: O(1)
*/

int maxProfitBrute(vector<int> &prices) {
  int profit = 0;
  for (int i = 0; i < prices.size(); i++) {
    int mini = prices[i];
    for (int j = i + 1; j < prices.size(); j++)
      profit = max(profit, prices[j] - mini);
  }
  return profit;
}

/*
  Optimized Approach:
  Time Complexity: O(n)
  Space Complexity: O(1)
*/

int maxProfitOpti(vector<int> &prices) {
  int profit = 0, mini = INT_MAX;
  for (auto it : prices) {
    mini = min(mini, it);
    profit = max(profit, it - mini);
  }
  return profit;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << maxProfitBrute(arr) << endl;
  cout << maxProfitOpti(arr) << endl;

  return 0;
}