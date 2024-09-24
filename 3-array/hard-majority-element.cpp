#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n^2)
  Space complexity: O(n)
*/

vector<int> majorityElementBrute(vector<int> &nums) {
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    int check = 0;
    int freq = 0;
    for (auto it : ans)
      if (it == nums[i]) {
        check = 1;
        break;
      }
    if (check == 1)
      continue;
    for (int j = i; j < nums.size(); j++)
      if (nums[i] == nums[j])
        freq++;
    if (freq > nums.size() / 3)
      ans.push_back(nums[i]);
  }
  return ans;
}

/*
  Better approach: (Using map)
  Time complexity: O(n)
  Space complexity: O(n)
*/

vector<int> majorityElementBetter(vector<int> &nums) {
  unordered_map<int, int> freq;
  vector<int> ans;
  for (auto it : nums)
    freq[it]++;
  for (auto it : freq)
    if (it.second > nums.size() / 3)
      ans.push_back(it.first);
  return ans;
}

/*
  Optimal approach: (Using Moore's Voting Algorithm)
  Time complexity: O(2n)
  Space complexity: O(1)
*/

vector<int> majorityElementOpti(vector<int> &nums) {
  int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
  vector<int> ans;
  for (auto it : nums) {
    if (cnt1 == 0 && el2 != it) {
      el1 = it;
      cnt1++;
    } else if (cnt2 == 0 && el1 != it) {
      el2 = it;
      cnt2++;
    } else if (it == el1)
      cnt1++;
    else if (it == el2)
      cnt2++;
    else {
      cnt1--;
      cnt2--;
    }
  }
  cnt1 = 0;
  cnt2 = 0;
  for (auto it : nums) {
    if (it == el1)
      cnt1++;
    else if (it == el2)
      cnt2++;
  }
  if (cnt1 > nums.size() / 3)
    ans.push_back(el1);
  if (cnt2 > nums.size() / 3)
    ans.push_back(el2);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> ans = majorityElementOpti(arr);
  for (auto it : ans)
    cout << it << " ";
  cout << endl;

  vector<int> ans1 = majorityElementBetter(arr);
  for (auto it : ans1)
    cout << it << " ";
  cout << endl;

  vector<int> ans2 = majorityElementBrute(arr);
  for (auto it : ans2)
    cout << it << " ";
  cout << endl;

  return 0;
}