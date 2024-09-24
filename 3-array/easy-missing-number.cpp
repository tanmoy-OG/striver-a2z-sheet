#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

int missingNumberBrute(vector<int> &nums) {
  for (int i = 1; i <= nums.size(); i++) {
    int check = 0;
    for (auto it : nums)
      if (it == i) {
        check = 1;
        break;
      }
    if (check == 0)
      return i;
  }
  return -1;
}

/*
  Better approach:
  Time complexity: O(n)
  Space complexity: O(n)
*/

int missingNumberBetter(vector<int> &nums) {
  vector<int> store(nums.size() + 1);
  for (auto it : nums)
    store[it] = 1;
  for (int i = 0; i < store.size(); i++)
    if (store[i] == 0)
      return i;
  return -1;
}

/*
  Optimal approach 1:
  Time complexity: O(n)
  Space complexity: O(1)
*/

int missingNumberOpti1(vector<int> &nums) {
  int size = nums.size(), idealSum = size * (size + 1) / 2, realSum = 0,
      missing;
  for (auto it : nums)
    realSum += it;
  missing = idealSum - realSum;
  return missing;
}

/*
  Optimal approach 2: (Using XOR)
  Time complexity: O(n)
  Space complexity: O(1)
*/

int missingNumberOpti2(vector<int> &nums) {
  int xor1 = 0, xor2 = 0;
  for (int i = 0; i < nums.size(); i++) {
    xor1 = xor1 ^ (i + 1);
    if (nums[i] == 0)
      continue;
    xor2 = xor2 ^ nums[i];
  }
  return xor1 ^ xor2;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << missingNumberBrute(arr) << endl;
  cout << missingNumberBetter(arr) << endl;
  cout << missingNumberOpti1(arr) << endl;
  cout << missingNumberOpti2(arr) << endl;

  return 0;
}