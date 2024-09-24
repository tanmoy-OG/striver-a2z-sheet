#include <bits/stdc++.h>

using namespace std;

/*
  Brute Force Approach
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

int maxSubArrayBrute(vector<int> &nums) {
  int maxi = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];
      maxi = max(maxi, sum);
    }
  }
  return maxi;
}

/*
  Optimised: (Kadane's Algorithm)
  Time complexity: O(n)
  Space complexity: O(1)
*/

int maxSubArrayOpti(vector<int> &nums) {
  int i = 0, j = 0, sum = 0, maxi = INT_MIN;
  while (i < nums.size() && j < nums.size()) {
    sum += nums[j];
    j++;
    maxi = max(maxi, sum);
    if (sum < 0) {
      sum = 0;
      i = j;
    }
  }
  return maxi;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << maxSubArrayBrute(arr) << endl;
  cout << maxSubArrayOpti(arr) << endl;

  return 0;
}