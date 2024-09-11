#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

vector<int> twoSumBrute(vector<int> &nums, int target) {
  int i, j, s;
  vector<int> sum = {0, 0};
  for (i = 0; i < nums.size() - 1; i++) {
    s = nums[i];
    for (j = i + 1; j < nums.size(); j++)
      if (s + nums[j] == target) {
        sum[0] = i;
        sum[1] = j;
        return sum;
      }
  }
  return sum;
}

/*
  Optimized approach
  Time complexity: O(n)
  Space complexity: O(n)
*/

vector<int> twoSumOptimizedV1(vector<int> &nums, int target) {
  unordered_map<int, int> mp;
  vector<int> sum = {0, 0};
  for (int i = 0; i < nums.size(); i++) {
    if (mp.find(target - nums[i]) != mp.end()) {
      sum[0] = mp[target - nums[i]];
      sum[1] = i;
      return sum;
    }
    mp[nums[i]] = i;
  }
  return sum;
}

/*
  Optimized approach v2 (two pointer approach) - works only if the array is sorted
  Time complexity: O(n)
  Space complexity: O(1)
*/

vector<int> twoSumOptimizedV2(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    if (nums[left] + nums[right] == target)
      break;
    else if (nums[left] + nums[right] < target)
      left++;
    else
      right--;
  }
  return {left, right};
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int target;
  cin >> target;

  vector<int> sum = twoSumBrute(arr, target);
  cout << sum[0] << " " << sum[1] << endl;
  vector<int> sum = twoSumOptimizedV1(arr, target);
  cout << sum[0] << " " << sum[1] << endl;
  vector<int> sum = twoSumOptimizedV2(arr, target);
  cout << sum[0] << " " << sum[1] << endl;

  return 0;
}