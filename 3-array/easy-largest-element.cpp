#include <bits/stdc++.h>

using namespace std;

int largest(vector<int> &arr, int n) {
  int mini = INT_MIN;
  for (auto i : arr)
    if (i > mini)
      mini = i;
  return mini;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;
  cout << largest(arr, n) << endl;
  return 0;
}