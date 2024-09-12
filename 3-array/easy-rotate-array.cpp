#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n)
  Space complexity: O(n)
*/

void rotateBrute(vector<int> &nums, int k) {
  int size = nums.size();
  if (size == 0 || size == 1)
    return;
  k = k % size;
  if (size < k)
    return;
  vector<int> store = nums;
  int j = size - k;
  for (int i = 0; i < size; i++) {
    if (j + i < size)
      nums[i] = store[j + i];
    else
      nums[i] = store[i - size + j];
  }
}

/*
  Optimal approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

void rotateOpti(vector<int> &nums, int k) {
  if (nums.size() == 0 || nums.size() == 1)
    return;
  k = k % nums.size();
  if (nums.size() < k)
    return;
  reverse(nums.begin(), nums.end() - k);
  reverse(nums.end() - k, nums.end());
  reverse(nums.begin(), nums.end());
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr2 = arr;
  int k;
  cin >> k;

  rotateBrute(arr, k);
  rotateOpti(arr2, k);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl << endl;

  for (int i = 0; i < n; i++)
    cout << arr2[i] << " ";
  cout << endl;

  return 0;
}