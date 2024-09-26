#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

int singleNumberBrute(vector<int> &nums) {
  int cnt;
  for (int i = 0; i < nums.size(); i++) {
    int cnt = 0;
    for (int j = 0; j < nums.size(); j++)
      if (nums[i] == nums[j])
        cnt++;
    if (cnt == 1)
      return nums[i];
  }
  return -1;
}

/*
  Better approach:
  Time complexity: O(2n)
  Space complexity: O(n)
*/

int singleNumberBetter(vector<int> &nums) {
  unordered_map<int, int> mp;
  for (auto it : nums)
    mp[it]++;
  for (auto it : mp)
    if (it.second == 1)
      return it.first;
  return -1;
}

/*
  Optimized approach: (XOR Bit manipulation)
  Time complexity: O(n)
  Space complexity: O(1)
*/

int singleNumberOpti(vector<int> &nums) {
  int xxor = 0;
  for (auto it : nums)
    xxor = xxor ^ it;
  return xxor;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << singleNumberBrute(arr) << endl;
  cout << singleNumberBetter(arr) << endl;
  cout << singleNumberOpti(arr) << endl;

  return 0;
}