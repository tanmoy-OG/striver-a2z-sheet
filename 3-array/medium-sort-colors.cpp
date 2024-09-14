#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

/*
  Brute force approach:
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/

void sortColorsBrute(vector<int> &nums) { sort(nums.begin(), nums.end()); }

/*
  Optimal approach 1:
  Time complexity: O(n)
  Space complexity: O(1)
*/

void sortColorsOptiV1(vector<int> &nums) {
  int i = 0, j = 0, check = 0;
  while (i < nums.size() && check <= 1) {
    if (nums[i] == check) {
      i++;
      if (j < i)
        j++;
      continue;
    }
    if (j >= nums.size()) {
      j = i;
      check++;
      continue;
    }
    if (nums[j] == check && nums[i] > nums[j]) {
      nums[j] = nums[i];
      nums[i] = check;
      i++;
    }
    j++;
  }
}

/*
  Optimal approach 2: (Dutch National Flag Algorithm)
  Time complexity: O(n)
  Space complexity: O(1)
*/

void sortColorsOptiV2(vector<int> &nums) {
  int low = 0, mid = 0, high = nums.size() - 1;
  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums, low, mid);
      low++;
      mid++;
    } else if (nums[mid] == 1)
      mid++;
    else {
      swap(nums, mid, high);
      high--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr2 = arr;
  vector<int> arr3 = arr;

  sortColorsBrute(arr);
  sortColorsOptiV1(arr2);
  sortColorsOptiV2(arr3);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl << endl;

  for (int i = 0; i < n; i++)
    cout << arr2[i] << " ";
  cout << endl << endl;

  for (int i = 0; i < n; i++)
    cout << arr3[i] << " ";
  cout << endl;

  return 0;
}