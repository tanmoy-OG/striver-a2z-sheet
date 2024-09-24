#include <bits/stdc++.h>

using namespace std;

/*
  Time Complexity: O(nlogn)
  Space Complexity: O(1)*/

void print2ndSmallLargeBrute(vector<int> &arr) {
  int n = arr.size();
  if (n == 0 || n == 1)
    cout << -1 << " " << -1 << endl;

  sort(arr.begin(), arr.end());
  cout << arr[1] << endl;
  cout << arr[n - 2] << endl;
}

/*
  Time Complexity: O(2n) (2 traversals)
  Space Complexity: O(1)*/

void print2ndSmallLargeBetter(vector<int> &arr) {
  int n = arr.size();
  if (n == 0 || n == 1)
    cout << -1 << " " << -1 << endl;

  int mini = INT_MAX, mini2 = INT_MAX, maxi = INT_MIN, maxi2 = INT_MIN;
  for (auto it : arr) {
    mini = min(mini, it);
    maxi = max(maxi, it);
  }

  for (auto it : arr) {
    if (it != mini)
      mini2 = min(mini2, it);
    if (it != maxi)
      maxi2 = max(maxi2, it);
  }

  cout << mini2 << endl;
  cout << maxi2 << endl;
}

/*
  Time Complexity: O(n) (Single Traversal)
  Space Complexity: O(1)*/

void print2ndSmallLargeOptimal(vector<int> &arr) {
  int n = arr.size();
  if (n == 0 || n == 1)
    cout << -1 << " " << -1 << endl;

  int mini = INT_MAX, mini2 = INT_MAX, maxi = INT_MIN, maxi2 = INT_MIN;
  for (auto it : arr) {
    if (it < mini) {
      mini2 = mini;
      mini = it;
    } else if (it < mini2 && it != mini) {
      mini2 = it;
    }

    if (it > maxi) {
      maxi2 = maxi;
      maxi = it;
    } else if (it > maxi2 && it != maxi) {
      maxi2 = it;
    }
  }

  cout << mini2 << endl;
  cout << maxi2 << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  print2ndSmallLargeBrute(arr);
  print2ndSmallLargeBetter(arr);
  print2ndSmallLargeOptimal(arr);
  return 0;
}