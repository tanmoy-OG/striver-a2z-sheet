#include <bits/stdc++.h>

using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/

int findMaxConsecutiveOnes(vector<int> &nums) {
  int maxi = INT_MIN, cnt = 0;
  for (auto it : nums) {
    if (it == 1)
      cnt++;
    else
      cnt = 0;
    maxi = max(maxi, cnt);
  }
  return maxi;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findMaxConsecutiveOnes(arr) << endl;

  return 0;
}