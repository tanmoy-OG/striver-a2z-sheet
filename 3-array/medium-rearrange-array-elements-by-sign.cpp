#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach:
  Time complexity: O(n)
  Space complexity: O(n)
*/

vector<int> rearrangeArrayBrute(vector<int> &nums) {
  int pos = 0, neg = 0;
  vector<int> ans;
  for (int i = 0; i < nums.size() / 2; i++) {
    for (int j = pos; j < nums.size(); j++)
      if (nums[j] >= 0) {
        pos = j + 1;
        ans.push_back(nums[j]);
        break;
      }
    for (int k = neg; k < nums.size(); k++)
      if (nums[k] < 0) {
        neg = k + 1;
        ans.push_back(nums[k]);
        break;
      }
  }
  return ans;
}

/*
  Optimized approach: (Two pointer)
  Time complexity: O(n)
  Space complexity: O(n)
*/

vector<int> rearrangeArrayOpti(vector<int> &nums) {
  int pos = 0, neg = 1;
  vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] >= 0) {
      ans[pos] = nums[i];
      pos += 2;
    } else {
      ans[neg] = nums[i];
      neg += 2;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> ans1 = rearrangeArrayBrute(arr);
  for (auto it : ans1)
    cout << it << " ";
  cout << endl;

  vector<int> ans2 = rearrangeArrayOpti(arr);
  for (auto it : ans2)
    cout << it << " ";
  cout << endl;

  return 0;
}