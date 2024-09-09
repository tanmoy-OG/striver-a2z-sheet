#include <bits/stdc++.h>
using namespace std;

/*
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/
int largestBrute(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int maxi = arr[arr.size() - 1];
  return maxi;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
int largestOptimal(vector<int> &arr) {
  int maxi = INT_MIN;
  for (auto i : arr)
    maxi = max(maxi, i);
  return maxi;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << largestBrute(arr) << endl;
  cout << largestOptimal(arr) << endl;
  return 0;
}