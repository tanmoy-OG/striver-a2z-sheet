#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O((n + m)log(n + m))
  Space complexity: O(n + m)
*/

vector<int> findUnionBrute(int arr1[], int arr2[], int n, int m) {
  map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < n; i++)
    mp[arr1[i]] = i;
  for (int i = 0; i < m; i++)
    mp[arr2[i]] = i;
  for (auto it : mp)
    ans.push_back(it.first);
  return ans;
}

/*
  Optimal approach: (Using two pointers)
  Time complexity: O(n + m)
  Space complexity: O(1)
*/

vector<int> findUnionOpti(int arr1[], int arr2[], int n, int m) {
  vector<int> ans;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) {
      if (ans.size() == 0 || ans.back() != arr1[i])
        ans.push_back(arr1[i]);
      i++;
    } else if (arr1[i] > arr2[j]) {
      if (ans.size() == 0 || ans.back() != arr2[j])
        ans.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) {
    if (ans.size() == 0 || ans.back() != arr1[i])
      ans.push_back(arr1[i]);
    i++;
  }
  while (j < m) {
    if (ans.size() == 0 || ans.back() != arr2[j])
      ans.push_back(arr2[j]);
    j++;
  }
  return ans;
}

int main() {
  int m, n;
  cin >> n;
  cin >> m;
  int arr1[n];
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  int arr2[m];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  vector<int> ans1 = findUnionBrute(arr1, arr2, n, m);
  for (auto it : ans1)
    cout << it << " ";
  cout << endl;
  vector<int> ans2 = findUnionOpti(arr1, arr2, n, m);
  for (auto it : ans2)
    cout << it << " ";
  cout << endl;

  return 0;
}