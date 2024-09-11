#include <bits/stdc++.h>

using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/

int removeDuplicates(vector<int> &nums) {
  int cnt = 1, i = 0;
  for (int i = 0; i < nums.size() - 1; i++)
    if (nums[i] < nums[i + 1])
      cnt++;
    else {
      nums.erase(nums.begin() + i);
      i--;
    }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << removeDuplicates(arr) << endl;

  return 0;
}