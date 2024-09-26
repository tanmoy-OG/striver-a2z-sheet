#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

int lenOfLongSubarrBrute(int A[], int N, int K) {
  int maxi = 0;
  for (int i = 0; i < N; i++) {
    long long sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      if (sum == K)
        maxi = max(maxi, j - i + 1);
    }
  }
  return maxi;
}

/*
  Better approach: (Prefix sum + Hashing)
  Time complexity: O(n)
  Space complexity: O(n)
*/

int lenOfLongSubarrBetter(int A[], int N, int K) {
  int maxi = 0;
  long long sum = 0, rem;
  unordered_map<long long, int> mp;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    if (sum == K)
      maxi = max(maxi, i + 1);
    rem = sum - K;
    if (mp.find(rem) != mp.end())
      maxi = max(maxi, i - mp[rem]);
    if (mp.find(sum) == mp.end())
      mp[sum] = i;
  }
  return maxi;
}

/*
  Optimized approach: (Two pointer)
  Time complexity: O(n)
  Space complexity: O(1)
*/

int lenOfLongSubarrOpti(int A[], int N, int K) {
  int maxi = 0, i = 0, j = 0;
  long long sum = 0;
  while (j < N) {
    sum += A[j];
    if (sum == K) {
      maxi = max(maxi, j - i + 1);
      j++;
    } else if (sum > K) {
      sum -= A[i];
      i--;
    } else
      j++;
  }
  return maxi;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  cout << lenOfLongSubarrBrute(arr.data(), n, k) << endl;
  cout << lenOfLongSubarrBetter(arr.data(), n, k) << endl;
  cout << lenOfLongSubarrOpti(arr.data(), n, k) << endl;

  return 0;
}