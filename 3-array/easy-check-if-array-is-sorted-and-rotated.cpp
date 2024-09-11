#include <bits/stdc++.h>

using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
bool check(vector<int> &nums) {
  int check = 0, size = nums.size();
  for (int i = 1; i < size; i++) {
    if (nums[i] < nums[i - 1])
      check++;
    if (check > 1)
      return false;
  }
  if (check == 1 && nums[0] < nums[size - 1])
    return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << check(arr) << endl;

  return 0;
}