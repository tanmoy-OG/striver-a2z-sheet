#include <bits/stdc++.h>

using namespace std;

/*
  Linear search in a sorted array.
  Time complexity: O(n)
  Space complexity: O(1)
*/

int searchInSorted(int arr[], int N, int K) {
  for (int i = 0; i < N; i++)
    if (arr[i] == K)
      return 1;
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  cout << searchInSorted(arr.data(), n, k) << endl;

  return 0;
}