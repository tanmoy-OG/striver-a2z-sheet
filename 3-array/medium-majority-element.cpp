#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

int majorityElementBrute(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    int cnt = 1;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] == nums[i])
        cnt++;
      if (cnt > ceil(nums.size() / 2))
        return nums[i];
    }
  }

  return nums[0];
}

/*
  Better approach:
  Time complexity: O(nlogn)
  Space complexity: O(n)
*/

int majorityElementBetter(vector<int> &nums) {
  unordered_map<int, int> mp;
  int n = nums.size() / 2, ans = 0;

  for (auto a : nums) {
    mp[a]++;
  }
  for (auto a : mp) {
    if (a.second > n) {
      ans = a.first;
    }
  }

  return ans;
}

/*
  Optimized approach: (Boyer-Moore Voting Algorithm)
  Time complexity: O(n)
  Space complexity: O(1)
*/

int majorityElement(vector<int> &nums) {
  int ans, cnt = 0;

  for (auto it : nums) {
    if (cnt == 0)
      ans = it;
    if (ans == it)
      cnt++;
    else
      cnt--;
  }

  cnt = 0;
  for (auto it : nums)
    if (ans == it)
      cnt++;

  return cnt > ceil(nums.size() / 2) ? ans : 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr1 = arr;
  vector<int> arr2 = arr;

  cout << majorityElementBrute(arr) << endl;
  cout << majorityElementBetter(arr1) << endl;
  cout << majorityElement(arr2) << endl;

  return 0;
}