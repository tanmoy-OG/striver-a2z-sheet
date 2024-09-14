#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n+cnt)
  Space complexity: O(n)
*/

void moveZeroesBrute(vector<int> &nums) {
  vector<int> store;
  int cnt = 0;

  for (auto it : nums) {
    if (it == 0)
      cnt++;
    else
      store.push_back(it);
  }
  for (int i = 1; i <= cnt; i++)
    store.push_back(0);

  nums = store;
}

/*
  Optimized approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

void swap(vector<int> &nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void moveZeroesOpti(vector<int> &nums) {
  int i = 0, j = 0;
  while (i < nums.size() && j < nums.size()) {
    if (nums[i] == 0) {
      if (nums[j] != 0) {
        swap(nums, i, j);
        i++;
      }
      j++;
    } else {
      i++;
      j++;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr1 = arr;

  moveZeroesBrute(arr);
  moveZeroesOpti(arr1);

  for (auto it : arr)
    cout << it << " ";
  cout << endl << endl;

  for (auto it : arr1)
    cout << it << " ";
  cout << endl;

  return 0;
}